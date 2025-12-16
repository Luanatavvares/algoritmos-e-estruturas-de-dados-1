#include <stdio.h>
#include "mesa.h"
#include "carta.h"
#include "listaCartas.h"
#include <string.h>
#include <stdlib.h>


void Inicializar(MesaCartas *mesa){
    mesa->baralho = CriarListaVazia();
    mesa->descarte = CriarListaVazia();
    for(int i=0;i<4;i++){ //como é um arranjo, temos que percorrer ele todo e tornar cada posição vazia 
        mesa->bases[i] = CriarListaVazia();
    }
    for(int i=0;i<7;i++){ //como é um arranjo, temos que percorrer ele todo e tornar cada posição vazia 
        mesa->tableau[i] = CriarListaVazia();
    }
    mesa->pontuacao=0; 
}
void CarregarBaralhoAleatorio(MesaCartas *mesa) {

    EmbaralharLista(mesa->baralho);}   

void CarregarBaralho(MesaCartas* mesa) {
    // Inicialize o baralho vazio
    mesa->baralho = CriarListaVazia();

    // Loop para criar as cartas e adicioná-las ao baralho
    for (Tipovalor valor = A; valor <= K; valor++) {
        for (Tiponaipe naipe = PAUS; naipe <= OUROS; naipe++) {
            Carta carta;
            Inicializa(&carta, naipe, valor, BAIXO);
            AdicionarCartaAoTopo(mesa->baralho, &carta);
        }
    } 
    EmbaralharLista(mesa->baralho);   
}
void Preparar(MesaCartas *mesa){
    for(int i = 0; i < 7; i++){
        TransferirCartas(mesa->baralho, mesa->tableau[i], i+1);
    }
    for(int i = 0; i < 7; i++){
        Setposicao(&mesa->tableau[i]->topo->carta, CIMA);
    }
}
/*void Preparar(MesaCartas*mesa){
    int cartasDistribuidas =0;
// Distribuir 28 cartas no tableau
    for (int coluna = 0; coluna < 7; coluna++) {
        for (int linha = 0; linha <= coluna; linha++) {
            Carta carta1;
            if (linha == 0) {
            // Na primeira carta de cada coluna, a carta está virada para cima.
                carta1 = *CartaNoTopo(mesa->baralho);
                carta1.posicao = CIMA;
            } else if (cartasDistribuidas < 28) {
            // Nas outras linhas da coluna, as cartas estão viradas para baixo.
                carta1 = *CartaNoTopo(mesa->baralho);
                carta1.posicao = BAIXO;
            }

        // Adicionar a carta ao tableau.
            AdicionarCartaAoTopo(mesa->tableau[coluna], &carta1);
        // Retirar a carta do topo do baralho após adicioná-la ao tableau.
            RetirarCartaDoTopo(mesa->baralho);
            cartasDistribuidas++;
        }
    }
}*/
int VerificarVitoria(MesaCartas* mesa) {
    // Verifique se todas as bases contêm todas as cartas do mesmo naipe (copas, espadas, paus, ouros) em ordem crescente.
    for (Tiponaipe naipe = PAUS; naipe <= OUROS; naipe++) {
        bool baseCompleta = true;
        // Verifique a base correspondente ao naipe atual
        ListaDeCartas* base = mesa->bases[naipe];
        if (TamanhoDaLista(base) != 13) {
            baseCompleta = false; // Se não houver 13 cartas na base, não está completa.
        } else {
            // Verifique se as cartas estão em ordem crescente e alternam entre preto e vermelho.
            Carta* cartaAnterior = CartaNoTopo(base);
            for (int i = 1; i < 13; i++) {
                Carta* cartaAtual = CartaNaPosicao(base, i);
                // Verifique a ordem crescente
                if (cartaAtual->valor != cartaAnterior->valor + 1) {
                    baseCompleta = false;
                    break; // Não está em ordem crescente, saia do loop.
                }
                // Verifique a alternância de cores
                if ((cartaAnterior->naipe == PAUS || cartaAnterior->naipe == ESPADAS) &&
                    (cartaAtual->naipe == COPAS || cartaAtual->naipe == OUROS)) {
                    baseCompleta = false;
                    break; // Não estão alternando as cores, saia do loop.
                } else if ((cartaAnterior->naipe == COPAS || cartaAnterior->naipe == OUROS) &&
                           (cartaAtual->naipe == PAUS || cartaAtual->naipe == ESPADAS)) {
                    baseCompleta = false;
                    break; // Não estão alternando as cores, saia do loop.
                }
                cartaAnterior = cartaAtual;
            }
        }
        // Se uma base não estiver completa, o jogo não está ganho.
        if (!baseCompleta) {
            printf("O jogo ainda não foi vencido.\n");
            return 0; // O jogo não foi vencido, retorne 0.
        }
    }
    // Se todas as bases estiverem completas, o jogador ganhou.
    printf("Você ganhou o jogo de paciência!\n");
    return 1; // O jogo foi vencido, retorne 1.
}
void Exibir(MesaCartas* mesa) {
    printf("===== Mesa de Cartas =====\n");
    for(int i = 0; i< 7; i++){
        printf("Coluna[%d]\n", i);
        ExibirLista(mesa->tableau[i]);
    }
    // Exibir as bases na horizontal
    printf("Bases: ");
    for (int naipe = PAUS; naipe <= OUROS; naipe++) {
        ListaDeCartas* base = mesa->bases[naipe];
        if (!EstaVazia(base)) {
            Carta* carta1 = CartaNoTopo(base);
            printf("Carta na base [%d]: ", naipe); // Impressão de depuração
            Imprimi(carta1);
            printf("  "); // Espaço entre as cartas
        } else {
            printf("    "); // Espaço vazio
        }
    }
    printf("\n");
    // Exibir o baralho, o descarte e a pontuação
    printf("Baralho: %d cartas\n", TamanhoDaLista(mesa->baralho));
    printf("Descarte: ");
    ExibirLista(mesa->descarte);
    printf("\n");
    printf("Pontuação: %d\n", mesa->pontuacao);
    printf("==========================\n");
}
void ComprarCarta(MesaCartas *mesa) {
   if (!EstaVazia(mesa->baralho)) { // se a  mesa estiver precisando de uma carta, 
      Carta *carta = CartaNoTopo(mesa->baralho); // vamos chamar o baralho para pegar uma carta
      carta->posicao = CIMA; // a posicao da carta apos a saida do baralho é sempre para cima, assim, iremos identificar sua posicao chamando o carta->posicao
      AdicionarCartaAoTopo(mesa->descarte, carta); // vamos adicionar a carta ou em cima do descarte
      RetirarCartaDoTopo(mesa->baralho); // aqui vamos retirar a carta do topo do baralho
   }
}
void DescarteBase(MesaCartas *mesa) { // o descarte de bases ocorre abenas se forem sequencias A,2,3,... de mesmo nipe
   Carta *descarte = CartaNoTopo(mesa->descarte);
   if (descarte != NULL) { // faremos a verificacao
      for (int naipeBase = 0; naipeBase < 4; naipeBase++) { // verificação de acordo com os espaços para descarte
        if ((EstaVazia(mesa->bases[naipeBase]) && descarte->valor == A) || (!EstaVazia(mesa->bases[naipeBase]) && descarte->valor == CartaNoTopo(mesa->bases[naipeBase])->valor + 1 && (descarte->naipe % 2 != CartaNoTopo(mesa->bases[naipeBase])->naipe % 2))) {
            AdicionarCartaAoTopo(mesa->bases[naipeBase], descarte);
            RetirarCartaDoTopo(mesa->descarte);
            mesa->pontuacao += 10;

            break; // aqui, quando a verificação pelo naipe for sendo feita ela irá parar apartir do momento em que não conseguirmos colocar cartas em sequência de mesmo naipe

         }
      }
   }

}
void DescarteTableau(MesaCartas *mesa, int indiceColunaTableau){
    // Verifica se o descarte não está vazio.
    if (!EstaVazia(mesa->descarte)) {
        // Verifica se o índice da coluna do tableau é válido.
        if (indiceColunaTableau >= 0 && indiceColunaTableau < 7) {
            ListaDeCartas *colunaTableau = mesa->tableau[indiceColunaTableau];
            // Verifica se a coluna do tableau não está cheia.
            printf("CARTA 1: ");
            Imprimi(CartaNoTopo(mesa->descarte));
            printf("CARTA 2: ");
            Imprimi(CartaNoTopo(mesa->tableau[indiceColunaTableau]));
            Imprimi(&mesa->tableau[indiceColunaTableau]->topo->carta);
            ExibirLista(mesa->tableau[indiceColunaTableau]);
            if (Verificasequenciaalt(&mesa->descarte->topo->carta, &mesa->tableau[indiceColunaTableau]->topo->carta)) {
                // Obtém a carta no topo do descarte.
                //Carta *cartaDescarte = CartaNoTopo(mesa->descarte);
                // Move a carta do topo do descarte para o topo da coluna do tableau.
                //AdicionarCartaAoTopo(colunaTableau, cartaDescarte);
                // Remove a carta do topo do descarte.
                //RetirarCartaDoTopo(mesa->descarte);
                TransferirCartas(mesa->descarte, mesa->tableau[indiceColunaTableau], 1);
                mesa->pontuacao += 5;
            } else {
                printf("A coluna do tableau selecionada está cheia. Escolha outra coluna.\n");
            }
        } else {
            printf("O índice da coluna do tableau é inválido. Escolha um índice válido.\n");
        }
    } else {
        printf("O descarte está vazio. Não é possível mover cartas.\n");
    }
}
void TableauBase(MesaCartas *mesa,int colunaTableau) {
        Carta* cartaTableau = CartaNoTopo(mesa->tableau[colunaTableau]);
        if (cartaTableau != NULL) {
        // Percorrer as bases e verificar se a carta pode ser movida para alguma delas.
            for (int naipeBase = 0; naipeBase < 4; naipeBase++) {
        // Se a base está vazia, então somente a carta A pode ser adicionada. Se a base não estiver vazia, uma nova carta poderá ser adcionada se estiver na sequência e do mesmo naipe.
                if (EstaVazia(mesa->bases[naipeBase]) && cartaTableau->valor == A) {
        // A carta pode ser movida para a base, então a move.
                    AdicionarCartaAoTopo(mesa->bases[naipeBase], cartaTableau);
                    RetirarCartaDoTopo(mesa->tableau[colunaTableau]);
                    return;
                } else if (!EstaVazia(mesa->bases[naipeBase]) && cartaTableau->valor == Getvalor(CartaNoTopo(mesa->bases[naipeBase])) + 1) {
        // A carta pode ser movida para a base, então a move.
                    AdicionarCartaAoTopo(mesa->bases[naipeBase], cartaTableau);
                    RetirarCartaDoTopo(mesa->tableau[colunaTableau]);
                    mesa->pontuacao += 10;

                    return;
            }
        }
    }
}
void BaseTableau(MesaCartas* mesa, int indiceBase, int colunaTableau){
    Carta* cartaBase = CartaNoTopo(mesa->bases[indiceBase]);
    if (cartaBase != NULL) {
        Carta* cartaTableau = CartaNoTopo(mesa->tableau[colunaTableau]);
        if (cartaTableau == NULL || (cartaTableau->valor == cartaBase->valor - 1 &&
                                     (cartaTableau->naipe % 2 != cartaBase->naipe % 2))) {
            // A carta da base pode ser movida para o tableau, então a move.
            AdicionarCartaAoTopo(mesa->tableau[colunaTableau], cartaBase);
            RetirarCartaDoTopo(mesa->bases[indiceBase]);
             mesa->pontuacao -= 15;

        }
    }
}
void ColunasTableau(MesaCartas* mesa, int quantidade, int colunaOrigem, int colunaDestino) {
        // Verifique se os parâmetros são válidos.
    if (mesa == NULL || quantidade <= 0 || colunaOrigem < 0 || colunaOrigem >= 7 || colunaDestino < 0 || colunaDestino >= 7) {
        // Trate o erro, por exemplo, lançando uma exceção ou retornando um código de erro.
        return;
    }
    ListaDeCartas* origem = mesa->tableau[colunaOrigem];
    ListaDeCartas* destino = mesa->tableau[colunaDestino];
        // Verifica se a coluna de origem não está vazia e se a quantidade de cartas é válida.
    if (!EstaVazia(origem) && TamanhoDaLista(origem) >= quantidade) {
        // Move as cartas da coluna de origem para a coluna de destino e faz a proxima carta da coluna de origem ficar virada para CIMA
        for (int i = 0; i < quantidade; i++) {
            Carta* carta = CartaNoTopo(origem);
            RetirarCartaDoTopo(origem);
            AdicionarCartaAoTopo(destino, carta);

        }
        if (!EstaVazia(origem)) {
            Carta* proximaCarta = CartaNoTopo(origem);
            proximaCarta->posicao = CIMA;
            mesa->pontuacao+=5;
        }
    }
}
int ModoInterativo() {
    MesaCartas mesa;
    Inicializar(&mesa);
    CarregarBaralho(&mesa);
    Preparar(&mesa);
    
    bool vitoria = false;
    int coluna=0,base=0,origem=0,destino=0,qtd=0;
    char opcao[3];
    
    
    while (!vitoria) {
        Exibir(&mesa);
        printf("Opcoes:\n");
        printf("1 - Comprar Carta: CC\n");
        printf("2 - Descarte Base: DB\n");
        printf("3 - Descarte Tableau: DT\n");
        printf("4 - Mover Carta do Tableau para Base:TB\n ");
        printf("5 - Mover Carta da Base para Tableau: BT\n");
        printf("6 - Mover Carta entre Colunas do Tableau: TT\n");
        printf("7 - Reciclar Baralho: RB\n");
        printf("0 - Encerrar o Jogo: SA\n");
        printf("Escolha uma opcao: ");
        scanf("%2s", opcao);
        
        if(strcmp(opcao, "CC")==0){
            ComprarCarta(&mesa);
        }
        else if(strcmp(opcao, "DB")==0){
            DescarteBase(&mesa);
                
        }             
        else if(strcmp(opcao, "DT")==0) {       
                printf("Coluna Tableau:");
                scanf("%d",&coluna);
                DescarteTableau(&mesa,coluna);
        }

        else if(strcmp(opcao, "TB")==0)  {  
                printf("Coluna Tableau:");
                scanf("%d",&coluna);
                TableauBase(&mesa,coluna);
        }
        else if(strcmp(opcao, "BT")==0)  {
                printf("Indice da base:");
                scanf("%d",&base);
                printf("Coluna Tableau:");
                scanf("%d",&coluna);
                BaseTableau(&mesa,base,coluna);
        }
        else if(strcmp(opcao, "TT")==0) {
                printf("Quantidade de cartas:");
                scanf("%d",&qtd);
                printf("Coluna Origem:");
                scanf("%d",&origem); 
                printf("Coluna destino:");
                scanf("%d",&destino);               
                ColunasTableau(&mesa,qtd,origem,destino);

        }
        else if(strcmp(opcao, "RB")==0){
            
                ReciclarBaralho(&mesa);
        }
        else if(strcmp(opcao, "SA")==0){
                printf("Encerrando o Jogo.\n");
                return 0;
        }
        else{
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    // Verificar se a condição de vitória foi atingida.
    vitoria = VerificarVitoria(&mesa);

    // Exibir a mesa final após a vitória.
    Exibir(&mesa);

    
}
void ModoArquivo(){
    
}

void ReciclarBaralho(MesaCartas *mesa) {
    
}

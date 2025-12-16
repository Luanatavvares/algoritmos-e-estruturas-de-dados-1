/*TIPO ABSTRATO DE DADOS MESA
Este TAD deve representar uma mesa do jogo Paciência, contendo as listas de cartas para cada
espaço, e a contagem dos pontos. Assim, a estrutura deste TAD deve conter os campos
descritos abaixo. Obs.: para as bases e para o tableau, é recomendado que se use vetores.
● baralho: uma lista de cartas;
● descarte: uma lista de cartas;
● bases: quatro listas de cartas, uma para cada naipe;
● tableau: sete listas de cartas;
● pontuação.
As operações do TAD englobam todas as ações necessárias para fazer o jogo funcionar. Este
TAD é que chama as operações do TAD Carta para conferir se as jogadas são válidas.
● Inicializar: inicializa cada uma das listas de cartas como vazias e zera a pontuação.
● Carregar baralho aleatório: insere todas as 52 cartas no baralho, e o embaralha.
● Carregar baralho: insere cartas no baralho de acordo com as cartas passadas num
parâmetro de entrada, preservando a ordem passada.
● Preparar: distribui as cartas do baralho para o tableau, como descrito na introdução.
● Verificar vitória: confere se a condição de vitória do jogo foi atingida;
● Exibir: imprime a disposição das cartas na mesa, chamando a função de exibir lista de
cartas adequadamente. A forma exata de como exibir a mesa é de escolha livre do
grupo. Não há problema em imprimir as colunas do tableau como linhas, na horizontal,
visto que seria muito trabalhoso imprimir as listas em colunas lado a lado como
mostram as Figuras 1 a 7. A pontuação também deve ser exibida.
● Comprar carta: executa a ação de comprar uma carta.
● Mover do descarte para as bases;
● Mover do descarte para o tableau: tem como parâmetro o índice de qual coluna do
tableau vai receber a carta;
● Mover do tableau para as bases: tem como parâmetro o índice de qual coluna do
tableau vai ser obtida a carta;
● Mover das bases para o tableau: tem como parâmetro o índice de qual base vai ser
obtida a carta, e o índice de qual coluna do tableau vai receber essa carta;
● Mover entre colunas do tableau: tem como parâmetro a quantidade de cartas a ser
movidas, o índice de qual coluna do tableau vão ser obtidas as cartas, e o índice de
qual coluna do tableau vai receber as cartas.
*/
#include "listaCartas.h"
typedef struct{
    ListaDeCartas *baralho;
    ListaDeCartas *descarte; 
    ListaDeCartas *bases[4];
    ListaDeCartas *tableau[7];
    int pontuacao; 
}MesaCartas;
void Inicializar(MesaCartas *mesa);
void CarregarBaralhoAleatorio(MesaCartas *mesa);
void CarregarBaralho(MesaCartas *mesa);
void Preparar(MesaCartas*mesa);
int VerificarVitoria(MesaCartas*mesa);
void Exibir(MesaCartas* mesa);
void ComprarCarta(MesaCartas*cartas);
void DescarteBase(MesaCartas *mesa);
void DescarteTableau(MesaCartas *mesa, int indiceColunaTableau);
void TableauBase(MesaCartas *mesa,int colunaTableau);
void BaseTableau(MesaCartas* mesa, int indiceBase, int colunaTableau);
void ColunasTableau(MesaCartas* mesa, int quantidade, int colunaOrigem, int colunaDestino);
int ModoInterativo();
void ModoArquivo();
void ReciclarBaralho(MesaCartas *mesa);

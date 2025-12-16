/*TIPO ABSTRATO DE DADOS LISTA DE CARTAS
A finalidade deste TAD é gerenciar uma lista de cartas, para representar cada um dos espaços
onde podemos colocar cartas na mesa do jogo. Em todos esses espaços, é importante saber
qual carta está no topo (puxamos cartas do topo do baralho, inserimos cartas no topo das
colunas do tableau, etc.).
Assim, na implementação da lista encadeada, o grupo deve definir qual das pontas da lista se
refere ao topo da lista de cartas. Por exemplo, uma opção é definir o início da lista como sendo
o topo daquele conjunto de cartas. Além da lista encadeada de cartas, deve ser colocado no
TAD um campo que registra o número de cartas na lista. As operações a serem disponibilizadas
devem ser:
● Criar: inicializa a lista vazia;
● Retornar tamanho;
● Verificar se está vazia; se o inicio é igual ao final 
● Retornar a carta que está no topo;
● Retornar a carta que está numa dada posição: a posição 0 se refere à carta que está no
topo, a posição n-1 se refere à carta que está no fundo, sendo n o tamanho da lista;
● Adicionar carta ao topo;
● Retirar carta do topo.
● Transferir cartas: transfere uma quantidade arbitrária de cartas a partir do topo de uma
lista, para o topo de outra, mantendo a ordem original.
● Embaralhar: faz uma permutação aleatória da lista, alterando a mesma.
● Exibir: imprime o conteúdo da lista de cartas, sendo necessário indicar quando a lista
está vazia. Além disso, deve haver um parâmetro para indicar se todas as cartas devem
ser exibidas, ou apenas a carta do topo.*/
#ifndef LISTACARTAS_H
#define LISTACARTAS_H
#include "carta.h" // Inclua o cabeçalho da estrutura Carta
typedef struct Celula {
    Carta carta;
    struct Celula* proxima;
} Celula;
typedef struct {
    Celula* topo;
    int tamanho;
} ListaDeCartas;
ListaDeCartas* CriarListaVazia();
int TamanhoDaLista(ListaDeCartas* lista);
int EstaVazia(ListaDeCartas* lista);
Carta* CartaNoTopo(ListaDeCartas* lista);
Carta* CartaNaPosicao(ListaDeCartas* lista, int posicao);
void AdicionarCartaAoTopo(ListaDeCartas* lista, Carta* carta);
void RetirarCartaDoTopo(ListaDeCartas* lista);
void TransferirCartas(ListaDeCartas* origem, ListaDeCartas* destino, int quantidade);
void EmbaralharLista(ListaDeCartas* lista);
void ExibirLista(ListaDeCartas* lista);

#endif

#include "listaCartas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para criar uma nova lista de cartas vazia.
ListaDeCartas* CriarListaVazia() {
    ListaDeCartas* novaLista = (ListaDeCartas*)malloc(sizeof(ListaDeCartas)); // Aloca memória para a nova lista.
    if (novaLista != NULL) {
        novaLista->topo = NULL; // Inicializa o topo da lista como NULL (vazia).
        novaLista->tamanho = 0; // Inicializa o tamanho da lista como 0.
    }
    return novaLista; // Retorna a nova lista criada.
}

// Função para obter o tamanho atual da lista.
int TamanhoDaLista(ListaDeCartas* lista) {
    return lista->tamanho; // Retorna o tamanho da lista.
}

// Função para verificar se a lista está vazia.
int EstaVazia(ListaDeCartas* lista) {
    return (lista->topo == NULL); // Retorna 1 se a lista estiver vazia, 0 caso contrário.
}

// Função para obter a carta no topo da lista.
Carta* CartaNoTopo(ListaDeCartas* lista) {
    if (EstaVazia(lista)) {
        return NULL; // Lista vazia, não há carta no topo.
    }
    return &(lista->topo->carta); // Retorna a carta no topo da lista.
}

// Função para obter a carta em uma posição específica na lista.
Carta* CartaNaPosicao(ListaDeCartas* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        return NULL; // Posição inválida.
    }

    Celula* atual = lista->topo;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proxima; // Avança para a próxima célula na posição desejada.
    }

    return &(atual->carta); // Retorna a carta na posição especificada.
}

// Função para adicionar uma carta ao topo da lista.
void AdicionarCartaAoTopo(ListaDeCartas* lista, Carta* carta) {
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula)); // Aloca memória para uma nova célula.
    if (novaCelula != NULL) {
        novaCelula->carta = *carta; // Copia a carta para a nova célula.
        novaCelula->proxima = lista->topo; // Define a próxima célula como a que atualmente está no topo.
        lista->topo = novaCelula; // Atualiza o topo da lista para a nova célula.
        lista->tamanho++; // Aumenta o tamanho da lista.
    }
}

// Função para retirar a carta do topo da lista.
void RetirarCartaDoTopo(ListaDeCartas* lista) {
    if (!EstaVazia(lista)) {
        Celula* celulaRemovida = lista->topo; // Armazena a célula a ser removida.
        lista->topo = celulaRemovida->proxima; // Atualiza o topo da lista.
        free(celulaRemovida); // Libera a memória da célula removida.
        lista->tamanho--; // Diminui o tamanho da lista.
    }
}
void TransferirCartas(ListaDeCartas* origem, ListaDeCartas* destino, int quantidade){
    int contador = 0;
    while (origem->topo != NULL && contador < quantidade) {
        Celula* celulaRemovida = origem->topo;
        origem->topo = origem->topo->proxima; // Atualiza o topo da pilha de origem
        celulaRemovida->proxima = destino->topo; // Define a próxima célula como a que atualmente está no topo da pilha de destino.
        destino->topo = celulaRemovida; // Atualiza o topo da pilha de destino para a nova célula.
        origem->tamanho--;
        destino->tamanho++;
        contador++;
    }
}
// Função para embaralhar a lista de cartas.
void EmbaralharLista(ListaDeCartas* lista) {
    if (lista->tamanho > 1) {
        Carta* cartas = (Carta*)malloc(lista->tamanho * sizeof(Carta)); // Aloca memória para um array temporário de cartas.
        if (cartas != NULL) {
            // Copiar as cartas para um array temporário.
            Celula* atual = lista->topo;
            for (int i = 0; i < lista->tamanho; i++) {
                cartas[i] = atual->carta;
                atual = atual->proxima; // Avança para a próxima célula.
            }

            // Embaralhar o array de cartas.
            for (int i = lista->tamanho - 1; i > 0; i--) {
                int j = rand() % (i + 1); // Gerar um índice aleatório.
                // Trocar as cartas nas posições i e j.
                Carta temp = cartas[i];
                cartas[i] = cartas[j];
                cartas[j] = temp;
            }

            // Copiar as cartas embaralhadas de volta para a lista.
            atual = lista->topo;
            for (int i = 0; i < lista->tamanho; i++) {
                atual->carta = cartas[i];
                atual = atual->proxima; // Avança para a próxima célula.
            }

            free(cartas); // Libera a memória alocada para o array temporário.
        }
    }
}
void ExibirLista(ListaDeCartas* lista){
    Celula* atual = lista->topo;
    while (atual != NULL) {
        Imprimi(&atual->carta);
        atual = atual->proxima;
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/Cartas.h"
#include "../headers/ordenacao.h"


void adicionarCarta(Baralho* baralho, int valor, Cor cor) {
    Carta novaCarta = {valor, cor};
    baralho->cartas[baralho->tamanho++] = novaCarta;
}
void adicionarCartaEspecial(Baralho* baralho, int valor, Cor cor, const char* nome) {
    Carta novaCarta = {valor, cor, nome};
    baralho->cartas[baralho->tamanho++] = novaCarta;
}

void inicializarBaralho(Baralho* baralho) {
    int i, j;

    // Adicionar cartas de 0 a 9, Bloqueio, Reverso e +2 para cada cor
    for (i = 0; i <= 9; ++i) {
        for (j = 0; j < 4; ++j) {
            adicionarCarta(baralho, i, (Cor)j);
        }
    }

    // Adicionar cartas de Bloqueio, Reverso e +2 para cada cor
    for (i = 0; i < 4; ++i) {
        adicionarCartaEspecial(baralho, 10, (Cor)i,"BLOQUEIO"); // Cartas de Bloqueio
        adicionarCartaEspecial(baralho, 11, (Cor)i,"REVERSO"); // Cartas de Reverso
        adicionarCartaEspecial(baralho, 12, (Cor)i,"+2"); // Cartas de +2
    }

    // Adicionar cartas coringas (+4 e escolhe cor)
    for (i = 0; i < 2; ++i) {
        adicionarCartaEspecial(baralho, 13, CORINGA,"+4");          // Cartas de +4
        adicionarCartaEspecial(baralho, 14, CORINGA,"MUDA COR");          // Cartas de escolhe cor
    }

    // Embaralhar o baralho
    srand((unsigned int)time(NULL));
    for (i = baralho->tamanho - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Carta temp = baralho->cartas[i];
        baralho->cartas[i] = baralho->cartas[j];
        baralho->cartas[j] = temp;
    }
}

void mostrarCarta(Carta* carta) {
    switch (carta->cor) {
        case AZUL:
            printf("\033[34;1m"); // Azul
            break;
        case VERDE:
            printf("\033[32;1m"); // Verde
            break;
        case VERMELHO:
            printf("\033[31;1m"); // Vermelho
            break;
        case AMARELO:
            printf("\033[33;1m"); // Amarelo
            break;
        case CORINGA:
            printf("\033[37;1m"); // Branco para coringas
            break;
            
        default:
            break;
    }
    if (carta->nome != NULL) {
            printf("Valor: %s\n", carta->nome);
        } else {
            printf("Valor: %d\n", carta->valor);
        }

    // Resetar a cor para a cor padrão
    printf("\033[0m");
}

void mostrarBaralho(Baralho* baralho) {
    int i;
    for (i = 0; i < baralho->tamanho; ++i) {
        mostrarCarta(&baralho->cartas[i]);
    }
}

// Função para retirar 10 cartas aleatórias do baralho e armazenar em um vetor
void retirarCartasAleatorias(Baralho* baralho, Carta vetorRetiradas[NUMERO_DE_CARTAS]) {
    if (baralho->tamanho < NUMERO_DE_CARTAS) {
        printf("Não há cartas suficientes no baralho.\n");
        return;
    }

    for (int i = 0; i < NUMERO_DE_CARTAS; ++i) {
        vetorRetiradas[i] = baralho->cartas[--baralho->tamanho];
    }
}

// Função para mostrar um vetor de cartas
void mostrarVetorCartas(Carta vetorRetiradas[NUMERO_DE_CARTAS]) {
    for (int i = 0; i < NUMERO_DE_CARTAS; ++i) {
        mostrarCarta(&vetorRetiradas[i]);
    }
}

void mostrarVetorCartas1(Carta vetor[]) {
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        printf("Carta %d - Cor: %c, Valor: %d\n", i + 1, vetor[i].cor, vetor[i].valor);
    }
}

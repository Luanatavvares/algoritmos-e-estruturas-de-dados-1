#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/Permutacao.h"
#include "../headers/Matriz.h"

Matriz* criarMatriz(int numeroDeCidades) {
    Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
    if (matriz == NULL) {
        // Se a alocação falhar, retorne NULL ou trate o erro conforme necessário
        return NULL;
    }
    
    matriz->numeroDeCidades = numeroDeCidades;
    matriz->matrizDistancias = (int**)malloc(numeroDeCidades * sizeof(int*));

    if (matriz->matrizDistancias == NULL) {
        // Se a alocação falhar, libere a matriz e retorne NULL ou trate o erro conforme necessário
        free(matriz);
        return NULL;
    }

    for (int i = 0; i < numeroDeCidades; i++) {
        matriz->matrizDistancias[i] = (int*)malloc(numeroDeCidades * sizeof(int));
        if (matriz->matrizDistancias[i] == NULL) {
            // Se a alocação falhar, libere as linhas anteriores e retorne NULL ou trate o erro conforme necessário
            for (int j = 0; j < i; j++) {
                free(matriz->matrizDistancias[j]);
            }
            free(matriz->matrizDistancias);
            free(matriz);
            return NULL;
        }
    }

    return matriz;
}
// Função para gerar uma matriz aleatória de distâncias e imprimir
void gerarMatrizAleatoria(Matriz* matriz) {
    srand(time(NULL));

    for (int i = 0; i < matriz->numeroDeCidades; i++) {
        for (int j = 0; j < matriz->numeroDeCidades; j++) {
            if (i == j) {
                matriz->matrizDistancias[i][j] = 0;
            } else {
                int distanciaCidades = rand() % 100;
                matriz->matrizDistancias[i][j] = distanciaCidades;
            }
        }
    }

    // Imprime a matriz diretamente no terminal
    printf("Matriz de Distâncias:\n");
    for (int i = 0; i < matriz->numeroDeCidades; i++) {
        for (int j = 0; j < matriz->numeroDeCidades; j++) {
            printf("%d\t", matriz->matrizDistancias[i][j]);
        }
        printf("\n");
    }
}
// Função para calcular a soma das distâncias de uma permutação
int calcularSomaDistancias(Matriz* matriz, int* permutacao) {
    int resultado = 0;
    for (int i = 0; i < matriz->numeroDeCidades; i++) {
        int j = (i + 1) % matriz->numeroDeCidades;
        resultado += matriz->matrizDistancias[permutacao[i]][permutacao[j]];
    }
    return resultado;
}
// Função para liberar a memória da matriz
void destruirMatriz(Matriz* matriz) {
    for (int i = 0; i < matriz->numeroDeCidades; i++) {
        free(matriz->matrizDistancias[i]);
    }
    free(matriz->matrizDistancias);
    free(matriz);
}

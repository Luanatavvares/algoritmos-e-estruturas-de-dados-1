#include <stdio.h>
#include <stdlib.h>
#include "../headers/Permutacao.h"
#include "../headers/Matriz.h"

void realizarTroca(int* vetor, int i, int j) {
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}
// Função que soma os dígitos de uma matrícula
int calcularSomaDigitos(int matricula) {
    int soma = 0;
    int tempMatricula = matricula;

    while (tempMatricula > 0) {
        soma += tempMatricula % 10;
        tempMatricula /= 10;
    }

    return soma;
}
// Função que gera um vetor permutado com base no número de cidades e no resto da soma das matrículas
int* gerarVetorPermutado(int numeroDeCidades, int restoSomaMatriculas) {
    int tamanhoVetor = numeroDeCidades - 1;
    int* vetorPermutado = (int*)malloc(sizeof(int) * tamanhoVetor);
    int cidadeInicial = calcularCidadeInicial(restoSomaMatriculas);

    int j = 0;
    for (int i = 0; i < numeroDeCidades; i++) {
        if (i == cidadeInicial) {
            continue; 
        }
        vetorPermutado[j] = i;
        j++;
    }

   
    return vetorPermutado;
}
// Função que adiciona a cidade inicial no início e no final do vetor permutado     
int* adicionarCidadeInicialNoVetor(int* vetorPermutado, int numeroDeCidades, int cidadeInicial) {
    int tamanhoNovoVetor = numeroDeCidades + 1;
    int* novoVetor = (int*)malloc(sizeof(int) * tamanhoNovoVetor);

    novoVetor[0] = cidadeInicial;

    for (int i = 1; i < numeroDeCidades; i++) {
        novoVetor[i] = vetorPermutado[i - 1];
    }

    novoVetor[numeroDeCidades] = cidadeInicial;

    return novoVetor;
}

int gerarProximaPermutacao(int* arr, int n) { 
    int i, j;

    for (i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            break;
        }
    }

    if (i < 0) {
        return 0; 
    }

    for (j = n - 1; j > i; j--) {
        if (arr[j] > arr[i]) {
            break;
        }
    }

    // Troca arr[i] e arr[j]
    realizarTroca(arr, i, j);

    // Inverte a ordem dos elementos após i
    for (int l = i + 1, r = n - 1; l < r; l++, r--) {
        realizarTroca(arr, l, r);
    }

    return 1; // Permutação gerada com sucesso
}
// Função que encontra a cidade inicial com base no resto da soma das matrículas
int calcularCidadeInicial(int restoSomaMatriculas) {
    int cidadeInicial = restoSomaMatriculas;
    return cidadeInicial;
}

void encontrarMelhorPermutacao(int* vetorPermutado, int numeroDeCidades, int numeroTotalCidades, int restoSomaMatriculas) {
    int cidadeInicial = calcularCidadeInicial(restoSomaMatriculas);
    Matriz* matrizDistancias = criarMatriz(numeroTotalCidades);
    gerarMatrizAleatoria(matrizDistancias);
    int distanciaMinima = 999999999;
    int* melhorVetor = NULL;

    int* copiaVetor = (int*)malloc(sizeof(int) * (numeroTotalCidades - 1));
    for (int i = 0; i < numeroTotalCidades - 1; i++) {
        copiaVetor[i] = vetorPermutado[i];
    }

    do {
        int* novoVetor = adicionarCidadeInicialNoVetor(copiaVetor, numeroTotalCidades, cidadeInicial);
        int resultadoMinimo = calcularSomaDistancias(matrizDistancias, novoVetor);
        if (resultadoMinimo < distanciaMinima) {
            distanciaMinima = resultadoMinimo;
            if (melhorVetor != NULL) {
                free(melhorVetor);
            }
            melhorVetor = novoVetor;
        } else {
            free(novoVetor);
        }
    } while (gerarProximaPermutacao(copiaVetor, numeroTotalCidades - 1));
    
    printf("\nMelhor permutacao: ");
    for (int i = 0; i <= numeroTotalCidades; i++) {
        printf("%d ", melhorVetor[i]);
    }
    printf("\n");
    printf("Distância = %d\n", distanciaMinima);

    free(melhorVetor);
    free(copiaVetor);
    destruirMatriz(matrizDistancias);
}

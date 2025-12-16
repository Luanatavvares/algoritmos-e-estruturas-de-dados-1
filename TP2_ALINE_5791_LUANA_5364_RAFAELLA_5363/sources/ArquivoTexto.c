#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/Permutacao.h"
#include "../headers/Menu.h"
#include "../headers/Matriz.h"
#include "../headers/ArquivoTexto.h"


void encontrarMelhorPermutacaoArquivo(FILE* arquivoSaida, int* vetorPermutado, int numeroDeCidades, int numeroTotalCidades, int restoSomaMatriculas,Matriz* matrizDistancias) {
    int cidadeInicial = calcularCidadeInicial(restoSomaMatriculas);
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
    
    fprintf(arquivoSaida, "\nMelhor permutacao: ");
    for (int i = 0; i <= numeroTotalCidades; i++) {
        fprintf(arquivoSaida, "%d ", melhorVetor[i]);
    }
    fprintf(arquivoSaida, "\n");
    fprintf(arquivoSaida, "Distância = %d\n", distanciaMinima);

    free(melhorVetor);
    free(copiaVetor);
    destruirMatriz(matrizDistancias);
}

void gerarMatrizAleatoriaArquivo(FILE* arquivoSaida, Matriz* matriz) {
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

    // Imprime a matriz diretamente no arquivo de texto
    fprintf(arquivoSaida, "Matriz de Distâncias:\n");
    for (int i = 0; i < matriz->numeroDeCidades; i++) {
        for (int j = 0; j < matriz->numeroDeCidades; j++) {
            fprintf(arquivoSaida, "%d\t", matriz->matrizDistancias[i][j]);
        }
        fprintf(arquivoSaida, "\n");
    }
}
//Para não ter que modificar o código inteiro , foi preciso recriar essa função para o modo arquivo. 
void encontrarMelhorPermutacaoModoArquivo(int* vetorPermutado, int numeroDeCidades, int numeroTotalCidades, int restoSomaMatriculas, Matriz* matrizDistancias) {
    int cidadeInicial = calcularCidadeInicial(restoSomaMatriculas);
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
}

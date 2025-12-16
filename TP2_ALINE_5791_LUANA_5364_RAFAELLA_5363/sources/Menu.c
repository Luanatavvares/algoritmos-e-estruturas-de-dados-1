#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../headers/Permutacao.h"
#include "../headers/Menu.h"
#include "../headers/Matriz.h"
#include "../headers/ArquivoTexto.h"

void modoAleatorio() {
    int n, integrantesGrupo, modo;
    printf("=====================================\n");
    printf("          Modo Aleatório\n");
    printf("=====================================\n");

    do {
        printf("Digite o número de cidades (n): ");
        scanf("%d", &n);
        if (n < 5) {
            printf("Número de cidades deve ser no mínimo 5. Tente novamente.\n");
        }
    } while (n < 5);

    do {
        printf("Quantos integrantes no grupo (até 3 integrantes)? ");
        scanf("%d", &integrantesGrupo);

        if (integrantesGrupo > 3 || integrantesGrupo <= 0) {
            printf("Número de integrantes inválido. Digite novamente.\n");
        }
    } while (integrantesGrupo > 3 || integrantesGrupo <= 0);

    int matriculas[integrantesGrupo];
    int somaMatriculas = 0;

    for (int i = 0; i < integrantesGrupo; i++) {
        printf("Matrícula do integrante %d: ", i + 1);
        scanf("%d", &matriculas[i]);
        somaMatriculas += calcularSomaDigitos(matriculas[i]);
    }

    int resto = somaMatriculas % n;

    printf("=====================================\n");
    printf("       Opções de Visualização\n");
    printf("=====================================\n");
    printf("1 - Visualizar no Terminal\n");
    printf("2 - Salvar em um Arquivo de Texto\n");

    do {
        printf("Escolha uma opção: ");
        scanf("%d", &modo);
        printf("\n");
        if (modo != 1 && modo != 2) {
            printf("Opção inválida. Escolha 1 para visualização no terminal ou 2 para salvar em arquivo.\n");
        }
    } while (modo != 1 && modo != 2);

    clock_t start_time, end_time;
    double cpu_time_used;

    if (modo == 1) {
        start_time = clock(); // Início da contagem de tempo
        int *vetpermutado = gerarVetorPermutado(n, resto);
        encontrarMelhorPermutacao(vetpermutado, n, n, resto);
        end_time = clock(); // Fim da contagem de tempoa
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %f segundos\n", cpu_time_used);
    } else if (modo == 2) {
    start_time = clock();//contagem de tempo de execução 
    // Lógica para salvar em arquivo de texto
    FILE *arquivoSaida = fopen("resultados.txt", "w");
    if (arquivoSaida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return;
    }

    Matriz* matrizDistancias = criarMatriz(n);
    gerarMatrizAleatoriaArquivo(arquivoSaida,matrizDistancias);
    int *vetpermutado = gerarVetorPermutado(n, resto);
    encontrarMelhorPermutacaoArquivo(arquivoSaida, vetpermutado, n, n, resto,matrizDistancias);
    end_time = clock(); // Fim da contagem de tempo
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    fprintf(arquivoSaida, "Tempo de execução: %f segundos\n", cpu_time_used); // Escreve o tempo no arquivo
    fclose(arquivoSaida);
    printf("Resultados salvos no arquivo 'resultados.txt'.\n");
    fclose(arquivoSaida);

    }
}

void modoArquivo(char* nomeArquivo) {
    clock_t start_time, end_time;
    double cpu_time_used;
    int numeroDeCidades, integrantesGrupo, modo;
    printf("=====================================\n");
    printf("          Modo Arquivo\n");
    printf("=====================================\n");

    FILE* arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(arquivo, "%d", &numeroDeCidades);

    Matriz* matrizDistancias = criarMatriz(numeroDeCidades);

    for (int i = 0; i < numeroDeCidades; i++) {
        for (int j = 0; j < numeroDeCidades; j++) {
            if (i == j) {
                matrizDistancias->matrizDistancias[i][j] = 0;
            }
            else{
                fscanf(arquivo, "%d", &matrizDistancias->matrizDistancias[i][j]);
            }
        }
    }

    do {
        printf("Quantos integrantes no grupo (até 3 integrantes)? ");
        scanf("%d", &integrantesGrupo);

        if (integrantesGrupo > 3 || integrantesGrupo <= 0) {
            printf("Número de integrantes inválido. Digite novamente.\n");
        }
    } while (integrantesGrupo > 3 || integrantesGrupo <= 0);

    int matriculas[integrantesGrupo];
    int somaMatriculas = 0;

    for (int i = 0; i < integrantesGrupo; i++) {
        printf("Matrícula do integrante %d: ", i + 1);
        scanf("%d", &matriculas[i]);
        somaMatriculas += calcularSomaDigitos(matriculas[i]);
    }

    int resto = somaMatriculas % numeroDeCidades;

    printf("=====================================\n");
    printf("       Opções de Visualização\n");
    printf("=====================================\n");
    printf("1 - Visualizar no Terminal\n");
    printf("2 - Salvar em um Arquivo de Texto\n");
    scanf("%d",&modo);
    if(modo==1){
        start_time = clock(); // Início da contagem de tempo
        printf("Matriz de Distâncias:\n");
        for (int i = 0; i < numeroDeCidades; i++) {
            for (int j = 0; j < numeroDeCidades; j++) {
                printf("%d\t", matrizDistancias->matrizDistancias[i][j]);
        }
            printf("\n");
    }
        int *vetpermutado = gerarVetorPermutado(numeroDeCidades, resto);
        encontrarMelhorPermutacaoModoArquivo(vetpermutado, numeroDeCidades, numeroDeCidades, resto,matrizDistancias);
        end_time = clock(); // Fim da contagem de tempo
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %f segundos\n", cpu_time_used);
    }
    else if(modo==2){
        start_time = clock();
        // Lógica para salvar em arquivo de texto
        FILE *arquivoSaida = fopen("resultados.txt", "w");
        if (arquivoSaida == NULL) {
            perror("Erro ao abrir o arquivo de saída");
            return;
        }
        fprintf(arquivoSaida,"Matriz de Distâncias:\n");
        for (int i = 0; i < numeroDeCidades; i++) {
            for (int j = 0; j < numeroDeCidades; j++) {
                fprintf(arquivoSaida,"%d\t", matrizDistancias->matrizDistancias[i][j]);
            }
            fprintf(arquivoSaida,"\n");
        }
        int *vetpermutado = gerarVetorPermutado(numeroDeCidades, resto);
        encontrarMelhorPermutacaoArquivo(arquivoSaida, vetpermutado, numeroDeCidades, numeroDeCidades, resto,matrizDistancias);
        end_time = clock(); // Fim da contagem de tempo
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        fprintf(arquivoSaida, "Tempo de execução: %f segundos\n", cpu_time_used); // Escreve o tempo no arquivo
        fclose(arquivoSaida);
        printf("Resultados salvos no arquivo 'resultados.txt'.\n");
        fclose(arquivoSaida);

    }
    
    else{
        printf("Modo inválido");
    }
    destruirMatriz(matrizDistancias);
    
}

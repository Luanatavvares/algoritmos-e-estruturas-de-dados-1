#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../headers/Cartas.h"
#include "../headers/Menu.h"
#include "../headers/ordenacao.h"

void modoAleatorio(){
    int modo;
    clock_t start_time, end_time;
    double cpu_time_used;
    printf("Cartas não ordenadas::\n");
    Baralho meuBaralho;
    meuBaralho.tamanho = 0;
    inicializarBaralho(&meuBaralho);
    Carta vetorRetiradas[NUMERO_DE_CARTAS];
    retirarCartasAleatorias(&meuBaralho, vetorRetiradas);
    mostrarVetorCartas(vetorRetiradas);
    printf("\nOpções de ordenação: ");
    printf("\n[1]-BubbleSort\n");
    printf("[2]-SelectSort\n");
    printf("[3]-InsertSort\n");
    printf("[4]-ShellSort\n");
    printf("[5]-QuickSort\n");
    printf("[6]-HeapSort\n");
    printf("[7]-Imprimir todos\n");
    printf("Escolha uma opção:");
    scanf("%d",&modo);

    if(modo==1){
        start_time = clock(); // Início da contagem de tempo
        printf("===BubbleSort===\n");
        ordenarCartasBubbleSort(vetorRetiradas);
    }
    
    else if(modo==2){
        start_time = clock(); // Início da contagem de tempo
        printf("===SelectSort===\n");
        ordenarCartasSelectSort(vetorRetiradas);
    }
    else if(modo==3){
        start_time = clock(); // Início da contagem de tempo
        printf("===InsertSort===\n");
        ordenarCartasInsercao(vetorRetiradas);     
    }
    else if(modo==4){
        start_time = clock(); // Início da contagem de tempo
        printf("===ShellSort===\n");
        ordenarCartasShellSort(vetorRetiradas);
    }
    else if(modo==5){
        start_time = clock(); // Início da contagem de tempo
        printf("===QuickSort===\n");
        ordenarCartasQuickSort(vetorRetiradas);
    }
    else if(modo==6){
        start_time = clock(); // Início da contagem de tempo
        printf("===HeapSort===\n");
        ordenarCartasHeapSort(vetorRetiradas);
    }
     else if(modo==7){
        start_time = clock(); // Início da contagem de tempo
        printf("===BubbleSort===\n");
        ordenarCartasBubbleSort(vetorRetiradas);
        printf("===SelectSort===\n");
        ordenarCartasSelectSort(vetorRetiradas);
        printf("===InsertSort===\n");
        ordenarCartasInsercao(vetorRetiradas);
        printf("===ShellSort===\n");
        ordenarCartasShellSort(vetorRetiradas);
        printf("===QuickSort===\n");
        ordenarCartasQuickSort(vetorRetiradas);
        printf("===HeapSort===\n");
        ordenarCartasHeapSort(vetorRetiradas);
    }
    
    else{
        printf("Ordenação inválida");
    }
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

}

void modoArquivo() {
    FILE *arquivo;
    int modo; 
    char nomeArquivo[50];
    int nConjuntos;
    clock_t start_time, end_time;
    double cpu_time_used;

    // Solicita o nome do arquivo ao usuário
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    // Tenta abrir o arquivo
    arquivo = fopen(nomeArquivo, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Lê a quantidade de conjuntos de cartas
    fscanf(arquivo, "%d", &nConjuntos);

    // Processa cada conjunto
    for (int i = 0; i < nConjuntos; i++) {
        Carta conjunto[NUMERO_DE_CARTAS];

        // Lê as cartas do conjunto
        lerConjunto(arquivo, conjunto);
        
        printf("\n");


        // Escolhe o algoritmo de ordenação
        int escolha;
        printf("Escolha uma opção:");        
        printf("\n[1]-BubbleSort\n");
        printf("[2]-SelectSort\n");
        printf("[3]-InsertSort\n");
        printf("[4]-ShellSort\n");
        printf("[5]-QuickSort\n");
        printf("[6]-HeapSort\n");
        printf("[7]-Imprimir todos\n");
        scanf("%d", &escolha);

        // Ordena o conjunto conforme a escolha do usuário
        switch (escolha) {
            case 1:
                start_time = clock(); // Início da contagem de tempo
                bubbleSort(conjunto, NUMERO_DE_CARTAS);
                
                break;
            case 2:
                start_time = clock(); // Início da contagem de tempo
                selectionSort(conjunto, NUMERO_DE_CARTAS);
                break;
            case 3:
                start_time = clock(); // Início da contagem de tempo
                insertionSort(conjunto, NUMERO_DE_CARTAS);
                break;
            case 4:
                start_time = clock(); // Início da contagem de tempo
                shellSort(conjunto, NUMERO_DE_CARTAS);
                break;
            case 5:
                start_time = clock(); // Início da contagem de tempo
                quickSort(conjunto, 0, NUMERO_DE_CARTAS - 1);
                break;
            case 6:
                start_time = clock(); // Início da contagem de tempo
                heapSort2(conjunto, NUMERO_DE_CARTAS);
                break;
            case 7:
                // Executar todos os algoritmos
                start_time = clock();
                bubbleSort(conjunto, NUMERO_DE_CARTAS);
                printf("Conjunto Ordenado com Bubble Sort:\n");
                for (int j = 0; j < NUMERO_DE_CARTAS; j++) {
                    imprimirCarta(conjunto[j]);
                }
                end_time = clock();
                cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n", cpu_time_used); 

                
                start_time = clock();
                selectionSort(conjunto, NUMERO_DE_CARTAS);
                printf("\nConjunto Ordenado com Selection Sort:\n");
                for (int j = 0; j < NUMERO_DE_CARTAS; j++) {
                    imprimirCarta(conjunto[j]);
                }
                end_time = clock();
                cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n", cpu_time_used); 
            
               start_time = clock();
                insertionSort(conjunto, NUMERO_DE_CARTAS);
                printf("\nConjunto Ordenado com Insertion Sort:\n");
                for (int j = 0; j < NUMERO_DE_CARTAS; j++) {
                    imprimirCarta(conjunto[j]);
                }
                end_time = clock();
                cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n", cpu_time_used); 

            
                start_time = clock();
                shellSort(conjunto, NUMERO_DE_CARTAS);
                printf("\nConjunto Ordenado com Shell Sort:\n");
                for (int j = 0; j < NUMERO_DE_CARTAS; j++) {
                    imprimirCarta(conjunto[j]);
                }
                end_time = clock();
                cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n", cpu_time_used); 

            
                start_time = clock();
                quickSort(conjunto, 0, NUMERO_DE_CARTAS - 1);
                printf("\nConjunto Ordenado com Quick Sort:\n");
                for (int j = 0; j < NUMERO_DE_CARTAS; j++) {
                    imprimirCarta(conjunto[j]);
                }
                end_time = clock();
                cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n", cpu_time_used); 

    
                start_time = clock();
                heapSort2(conjunto, NUMERO_DE_CARTAS);
                printf("\nConjunto Ordenado com Heap Sort:\n");
                for (int j = 0; j < NUMERO_DE_CARTAS; j++) {
                    imprimirCarta(conjunto[j]);
                }
                end_time = clock();
                cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
                printf("Tempo de execução: %f segundos\n", cpu_time_used); 
                printf("\n");

                
                break;
            default:
                printf("Opcao invalida.\n");
                // Tratar outras ações necessárias, se houver
                break;
        }

        // Imprime as cartas ordenadas
        printf("Conjunto %d Ordenado:  \n", i+1 );
        printf("\n");
        for (int j = 0; j < NUMERO_DE_CARTAS; j++) {
            imprimirCarta(conjunto[j]);
        }
        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %f segundos\n", cpu_time_used);  
        // Imprime uma linha em branco para separar os conjuntos
        printf("\n");
    }


    fclose(arquivo);
}

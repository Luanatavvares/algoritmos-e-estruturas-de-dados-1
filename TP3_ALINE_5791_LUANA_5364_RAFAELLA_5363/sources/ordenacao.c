#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/Cartas.h"
#include "../headers/Menu.h"
#include "../headers/ordenacao.h"

void BubbleSort(Item* v, int n, int* comparacoes, int* movimentacoes) {
    int i, j;
    Item aux;

    for (i = 0; i < n - 1; i++) {
        for (j = 1; j < n - i; j++) {
            // Incrementa o contador de comparações
            (*comparacoes)++;

            if (v[j].Dado.cor < v[j - 1].Dado.cor || 
               (v[j].Dado.cor == v[j - 1].Dado.cor && v[j].Dado.valor < v[j - 1].Dado.valor)) {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;

                // Incrementa o contador de movimentações
                (*movimentacoes)++;
            }
        }
    }
}

void ordenarCartasBubbleSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]) {
    int comparacoes = 0;
    int movimentacoes = 0;

    // Criar um vetor de itens para facilitar a ordenação
    Item vetorItens[NUMERO_DE_CARTAS];
    
    // Preencher o vetor de itens com as cartas a serem ordenadas
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorItens[i].Dado = vetorRetiradas[i];
    }

    // Ordenar o vetor de itens usando o método de ordenação bolha
    BubbleSort(vetorItens, NUMERO_DE_CARTAS, &comparacoes, &movimentacoes);

    // Atualizar o vetor de cartas ordenado
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorRetiradas[i] = vetorItens[i].Dado;
    }
    mostrarVetorCartas(vetorRetiradas);
    // Mostrar o número de comparações e movimentações
    printf("\nNúmero de comparações: %d\n", comparacoes);
    printf("Número de movimentações: %d\n", movimentacoes);
}

void SelectSort(Item* v, int n, int* comparacoes, int* movimentacoes) {
    for (int i = 0; i < n - 1; i++) {
        int indiceMin = i;
        for (int j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (v[j].Dado.cor < v[indiceMin].Dado.cor ||
                (v[j].Dado.cor == v[indiceMin].Dado.cor &&
                 v[j].Dado.valor < v[indiceMin].Dado.valor)) {
                indiceMin = j;
            }
        }
        if (indiceMin != i) {
            // Troca diretamente na lógica do Selection Sort
            Item temp = v[i];
            v[i] = v[indiceMin];
            v[indiceMin] = temp;
            // Incrementa o contador de movimentações
            (*movimentacoes)++;
        }
    }
}

void ordenarCartasSelectSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]) {
    int comparacoes = 0;
    int movimentacoes = 0;
    // Criar um vetor de itens para facilitar a ordenação
    Item vetorItens[NUMERO_DE_CARTAS];
    // Preencher o vetor de itens com as cartas a serem ordenadas
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorItens[i].Dado = vetorRetiradas[i];
    }
    
    // Ordenar o vetor de itens usando o método de ordenação Selection Sort
    SelectSort(vetorItens, NUMERO_DE_CARTAS, &comparacoes, &movimentacoes);

    // Atualizar o vetor de cartas ordenado
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorRetiradas[i] = vetorItens[i].Dado;
    }
    
    // Mostrar o vetor ordenado
    mostrarVetorCartas(vetorRetiradas);

    // Mostrar o número de comparações e movimentações
    printf("\nNúmero de comparações: %d\n", comparacoes);
    printf("Número de movimentações: %d\n", movimentacoes);
}

void Insercao(Item* v, int n, int* comparacoes, int* movimentacoes) {
    int i, j;
    Item aux;

    for (i = 1; i < n; i++) {
        aux = v[i];
        j = i - 1;
        (*comparacoes)++;  // Incrementa o contador de comparações

        while ((j >= 0) && (aux.Dado.cor < v[j].Dado.cor || (aux.Dado.cor == v[j].Dado.cor && aux.Dado.valor < v[j].Dado.valor))) {
            v[j + 1] = v[j];
            j--;
            (*movimentacoes)++;  // Incrementa o contador de movimentações
            if (j >= 0) {
                (*comparacoes)++;  // Incrementa o contador de comparações
            }
        }

        v[j + 1] = aux;
        (*movimentacoes)++;  // Incrementa o contador de movimentações
    }
}

void ordenarCartasInsercao(Carta vetorRetiradas[NUMERO_DE_CARTAS]) {
    // Criar um vetor de itens para facilitar a ordenação
    Item vetorItens[NUMERO_DE_CARTAS];

    // Preencher o vetor de itens com as cartas a serem ordenadas
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorItens[i].Dado = vetorRetiradas[i];
    }

    // Inicializar os contadores
    int comparacoesInsercao = 0;
    int movimentacoesInsercao = 0;

    // Ordenar o vetor de itens usando o método de ordenação por inserção
    Insercao(vetorItens, NUMERO_DE_CARTAS, &comparacoesInsercao, &movimentacoesInsercao);

    // Atualizar o vetor de cartas ordenado
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorRetiradas[i] = vetorItens[i].Dado;
    }

    mostrarVetorCartas(vetorRetiradas);

    // Mostrar o número de comparações e movimentações
    printf("\nNúmero de comparações: %d\n", comparacoesInsercao);
    printf("Número de movimentações: %d\n", movimentacoesInsercao);
}

void Shellsort(Item* A, int n, int* comparacoes, int* movimentacoes) {
    int i, j;
    int h = 1;
    Item aux;

    do h = h * 3 + 1; while (h < n);
    
    do {
        h = h / 3;
        
        for (i = h; i < n; i++) {
            aux = A[i];
            j = i;

            (*comparacoes)++;  // Incrementa o contador de comparações

            while (A[j - h].Dado.cor > aux.Dado.cor || 
                   (A[j - h].Dado.cor == aux.Dado.cor && A[j - h].Dado.valor > aux.Dado.valor)) {
                A[j] = A[j - h];
                j -= h;

                (*movimentacoes)++;  // Incrementa o contador de movimentações

                if (j < h) break;
            }

            A[j] = aux;
        }
    } while (h != 1);
}

void ordenarCartasShellSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]) {
    // Criar um vetor de itens para facilitar a ordenação
    Item vetorItens[NUMERO_DE_CARTAS];
    
    // Preencher o vetor de itens com as cartas a serem ordenadas
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorItens[i].Dado = vetorRetiradas[i];
    }

    // Inicializar os contadores
    int comparacoesShell = 0;
    int movimentacoesShell = 0;

    // Ordenar o vetor de itens usando o método de ordenação shell sort
    Shellsort(vetorItens, NUMERO_DE_CARTAS, &comparacoesShell, &movimentacoesShell);

    // Atualizar o vetor de cartas ordenado
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorRetiradas[i] = vetorItens[i].Dado;
    }

    mostrarVetorCartas(vetorRetiradas);

    // Mostrar o número de comparações e movimentações
    printf("\nNúmero de comparações: %d\n", comparacoesShell);
    printf("Número de movimentações: %d\n", movimentacoesShell);
}

int particionar(Item* A, int baixo, int alto, int* comparacoes, int* movimentacoes) {
    Item pivo = A[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        (*comparacoes)++;
        if (A[j].Dado.cor < pivo.Dado.cor || (A[j].Dado.cor == pivo.Dado.cor && A[j].Dado.valor < pivo.Dado.valor)) {
            i++;

            // Troca diretamente na lógica de particionar
            Item temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            // Incrementa o contador de movimentações
            (*movimentacoes)++;
        }
    }

    // Troca do pivo
    Item temp = A[i + 1];
    A[i + 1] = A[alto];
    A[alto] = temp;

    return i + 1;
}

void quicksort(Item* A, int baixo, int alto, int* comparacoes, int* movimentacoes) {
    if (baixo < alto) {
        int indicePivo = particionar(A, baixo, alto, comparacoes, movimentacoes);
        quicksort(A, baixo, indicePivo - 1, comparacoes, movimentacoes);
        quicksort(A, indicePivo + 1, alto, comparacoes, movimentacoes);
    }
}

void ordenarCartasQuickSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]) {
    int comparacoes = 0;
    int movimentacoes = 0;
    // Criar um vetor de itens para facilitar a ordenação
    Item vetorItens[NUMERO_DE_CARTAS];

    // Preencher o vetor de itens com as cartas a serem ordenadas
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorItens[i].Dado = vetorRetiradas[i];
    }

    // Ordenar o vetor de itens usando o método de ordenação Quicksort
    quicksort(vetorItens, 0, NUMERO_DE_CARTAS - 1, &comparacoes, &movimentacoes);

    // Atualizar o vetor de cartas ordenado
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorRetiradas[i] = vetorItens[i].Dado;
    }

    mostrarVetorCartas(vetorRetiradas);

    // Mostrar o número de comparações e movimentações
    printf("\nNúmero de comparações: %d\n", comparacoes);
    printf("Número de movimentações: %d\n", movimentacoes);
}

void heapify(Item* A, int n, int i, int* comparacoes, int* movimentacoes) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    // Incrementa o contador de comparações
    (*comparacoes)++;

    if (esquerda < n && (A[esquerda].Dado.cor > A[maior].Dado.cor || 
                         (A[esquerda].Dado.cor == A[maior].Dado.cor && A[esquerda].Dado.valor > A[maior].Dado.valor))) {
        maior = esquerda;
    }

    // Incrementa o contador de comparações
    (*comparacoes)++;

    if (direita < n && (A[direita].Dado.cor > A[maior].Dado.cor ||
                        (A[direita].Dado.cor == A[maior].Dado.cor && A[direita].Dado.valor > A[maior].Dado.valor))) {
        maior = direita;
    }

    // Incrementa o contador de comparações
    (*comparacoes)++;

    if (maior != i) {
        // Troca diretamente na lógica do heapify
        Item temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;

        // Incrementa o contador de movimentações
        (*movimentacoes)++;

        // Recursivamente transforma a subárvore afetada em um heap
        heapify(A, n, maior, comparacoes, movimentacoes);
    }
}

void heapSort(Item* A, int n, int* comparacoes, int* movimentacoes) {
    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i, comparacoes, movimentacoes);
    }

    // Extrai um elemento por vez do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        Item temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        // Incrementa o contador de movimentações
        (*movimentacoes)++;

        // Chama a função heapify para o heap reduzido
        heapify(A, i, 0, comparacoes, movimentacoes);
    }
}

void ordenarCartasHeapSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]) {
    int comparacoes = 0;
    int movimentacoes = 0;

    // Cria um vetor de itens para facilitar a ordenação
    Item vetorItens[NUMERO_DE_CARTAS];

    // Preenche o vetor de itens com as cartas a serem ordenadas
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorItens[i].Dado = vetorRetiradas[i];
    }

    // Ordena o vetor de itens usando o método de ordenação Heap Sort
    heapSort(vetorItens, NUMERO_DE_CARTAS, &comparacoes, &movimentacoes);

    // Atualiza o vetor de cartas ordenado
    for (int i = 0; i < NUMERO_DE_CARTAS; i++) {
        vetorRetiradas[i] = vetorItens[i].Dado;
    }

    // Mostra o vetor ordenado
    mostrarVetorCartas(vetorRetiradas);

    // Mostra o número de comparações e movimentações
    printf("\nNúmero de comparações: %d\n", comparacoes);
    printf("Número de movimentações: %d\n", movimentacoes);
}





// ARQUIVO
void imprimirCarta(Carta carta) {
    const char* cores[] = {"VERDE", "AMARELO", "VERMELHO", "AZUL", "PRETO"};
    const char* valores[] = {"ZERO", "UM", "DOIS", "TRES", "QUATRO", "CINCO", "SEIS", "SETE", "OITO", "NOVE", "VOLTAR", "PULAR", "MAIS2", "MAIS4", "CORINGA"};

    printf("Cor: %s, Valor: %s\n", cores[carta.cor], valores[carta.valor]);
}

void lerConjunto(FILE* arquivo, Carta vetorRetiradas[NUMERO_DE_CARTAS]) {
    for (int j = 0; j < NUMERO_DE_CARTAS; j++) {
        char corStr[20];
        char valorStr[20];

        // Leitura da entrada no formato (cor valor)
        if (fscanf(arquivo, " (%19[^ ] %19[^)])", corStr, valorStr) != 2) {
            // Tratar erro de leitura
            printf("Erro de leitura no arquivo.\n");
            // Outras ações necessárias, como fechar o arquivo e encerrar o programa.
            break;
        }

        // Converte a string da cor para o tipo enum Cor
        if (strcasecmp(corStr, "verde") == 0) {
            vetorRetiradas[j].cor = VERDE;
        } else if (strcasecmp(corStr, "amarelo") == 0) {
            vetorRetiradas[j].cor = AMARELO;
        } else if (strcasecmp(corStr, "vermelho") == 0) {
            vetorRetiradas[j].cor = VERMELHO;
        } else if (strcasecmp(corStr, "azul") == 0) {
            vetorRetiradas[j].cor = AZUL;
        } else if (strcasecmp(corStr, "preto") == 0) {
            vetorRetiradas[j].cor = PRETO;
        } else {
            // Tratar cor não reconhecida
            printf("Cor não reconhecida: %s\n", corStr);
            // Outras ações necessárias, como fechar o arquivo e encerrar o programa.
            break;
        }

        // Converte a string do valor para o tipo enum Valor ou int
        if (strcasecmp(valorStr, "0") == 0) {
            vetorRetiradas[j].valor = ZERO;
        } else if (strcasecmp(valorStr, "1") == 0) {
            vetorRetiradas[j].valor = UM;
        } else if (strcasecmp(valorStr, "2") == 0) {
            vetorRetiradas[j].valor = DOIS;
        } else if (strcasecmp(valorStr, "3") == 0) {
            vetorRetiradas[j].valor = TRES;
        } else if (strcasecmp(valorStr, "4") == 0) {
            vetorRetiradas[j].valor = QUATRO;
        } else if (strcasecmp(valorStr, "5") == 0) {
            vetorRetiradas[j].valor = CINCO;
        } else if (strcasecmp(valorStr, "6") == 0) {
            vetorRetiradas[j].valor = SEIS;
        } else if (strcasecmp(valorStr, "7") == 0) {
            vetorRetiradas[j].valor = SETE;
        } else if (strcasecmp(valorStr, "8") == 0) {
            vetorRetiradas[j].valor = OITO;
        } else if (strcasecmp(valorStr, "9") == 0) {
            vetorRetiradas[j].valor = NOVE;
        } else if (strcasecmp(valorStr, "Pular") == 0) {
            vetorRetiradas[j].valor = PULAR;
        } else if (strcasecmp(valorStr, "Voltar") == 0) {
            vetorRetiradas[j].valor = VOLTAR;
        }  else if (strcasecmp(valorStr, "+2") == 0) {
            vetorRetiradas[j].valor = MAIS2;
        }else if (strcasecmp(valorStr, "+4") == 0) {
            vetorRetiradas[j].valor = MAIS4;
        } else if (strcasecmp(valorStr, "Coringa") == 0) {
            vetorRetiradas[j].valor = CORINGA;
         }

        // Imprimir a carta para verificar
        imprimirCarta(vetorRetiradas[j]);
    }
}
    

// Função para trocar duas cartas de posição
void trocarCartas(Carta *a, Carta *b) {
    Carta temp = *a;
    *a = *b;
    *b = temp;
}

// Função de ordenação Bubble Sort
void bubbleSort(Carta vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j].cor > vetor[j + 1].cor || 
                (vetor[j].cor == vetor[j + 1].cor && vetor[j].valor > vetor[j + 1].valor)) {
                trocarCartas(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

// Função de ordenação Selection Sort
void selectionSort(Carta vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menorIndice = i;
        for (int j = i + 1; j < n; j++) {
            if (vetor[j].cor < vetor[menorIndice].cor || 
                (vetor[j].cor == vetor[menorIndice].cor && vetor[j].valor < vetor[menorIndice].valor)) {
                menorIndice = j;
            }
        }
        trocarCartas(&vetor[i], &vetor[menorIndice]);
    }
}

// Função de ordenação Insertion Sort
void insertionSort(Carta vetor[], int n) {
    int i, j;
    Carta chave;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && (vetor[j].cor > chave.cor || 
                          (vetor[j].cor == chave.cor && vetor[j].valor > chave.valor))) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

// Função de ordenação Shell Sort
void shellSort(Carta vetor[], int n) {
    for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < n; i += 1) {
            Carta temp = vetor[i];
            int j;
            for (j = i; j >= intervalo && (vetor[j - intervalo].cor > temp.cor ||
                                           (vetor[j - intervalo].cor == temp.cor && vetor[j - intervalo].valor > temp.valor)); j -= intervalo) {
                vetor[j] = vetor[j - intervalo];
            }
            vetor[j] = temp;
        }
    }
}

// Função auxiliar para o Quick Sort
int particionar2(Carta vetor[], int baixo, int alto) {
    Carta pivo = vetor[alto];
    int i = baixo - 1;

    for (int j = baixo; j <= alto - 1; j++) {
        if (vetor[j].cor < pivo.cor || (vetor[j].cor == pivo.cor && vetor[j].valor < pivo.valor)) {
            i++;
            trocarCartas(&vetor[i], &vetor[j]);
        }
    }

    trocarCartas(&vetor[i + 1], &vetor[alto]);
    return i + 1;
}

// Função de ordenação Quick Sort
void quickSort(Carta vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int indicePivo = particionar2(vetor, baixo, alto);

        quickSort(vetor, baixo, indicePivo - 1);
        quickSort(vetor, indicePivo + 1, alto);
    }
}

// Função auxiliar para o Heap Sort
void heapify2(Carta vetor[], int n, int indice) {
    int maior = indice;
    int filhoEsquerda = 2 * indice + 1;
    int filhoDireita = 2 * indice + 2;

    if (filhoEsquerda < n && (vetor[filhoEsquerda].cor > vetor[maior].cor ||
                              (vetor[filhoEsquerda].cor == vetor[maior].cor && vetor[filhoEsquerda].valor > vetor[maior].valor))) {
        maior = filhoEsquerda;
    }

    if (filhoDireita < n && (vetor[filhoDireita].cor > vetor[maior].cor ||
                             (vetor[filhoDireita].cor == vetor[maior].cor && vetor[filhoDireita].valor > vetor[maior].valor))) {
        maior = filhoDireita;
    }

    if (maior != indice) {
        trocarCartas(&vetor[indice], &vetor[maior]);
        heapify2(vetor, n, maior);
    }
}

// Função de ordenação Heap Sort
void heapSort2(Carta vetor[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify2(vetor, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        trocarCartas(&vetor[0], &vetor[i]);
        heapify2(vetor, i, 0);
    }
}  

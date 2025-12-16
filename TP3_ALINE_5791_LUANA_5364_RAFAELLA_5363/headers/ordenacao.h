#ifndef ORDENACAO_H
#define ORDENACAO_H

typedef struct {
    int Chave;
    Carta Dado;
} Item;

void BubbleSort(Item* v, int n, int* comparacoes, int* movimentacoes);
void ordenarCartasBubbleSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]);
void SelectSort(Item* v, int n, int* comparacoes, int* movimentacoes);
void ordenarCartasSelectSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]) ;
void Insercao(Item* v, int n, int* comparacoes, int* movimentacoes) ;
void ordenarCartasInsercao(Carta vetorRetiradas[NUMERO_DE_CARTAS]);
void Shellsort(Item* A, int n, int* comparacoes, int* movimentacoes) ;
void ordenarCartasShellSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]) ;
int particionar(Item* A, int baixo, int alto, int* comparacoes, int* movimentacoes) ;
void quicksort(Item* A, int baixo, int alto, int* comparacoes, int* movimentacoes) ;
void ordenarCartasQuickSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]); 
void heapify(Item* A, int n, int i, int* comparacoes, int* movimentacoes) ;
void heapSort(Item* A, int n, int* comparacoes, int* movimentacoes) ;
void ordenarCartasHeapSort(Carta vetorRetiradas[NUMERO_DE_CARTAS]) ;
void lerConjunto(FILE* arquivo, Carta vetorRetiradas[NUMERO_DE_CARTAS]) ;
void trocarCartas(Carta *a, Carta *b);
void ordenarCartas(Carta vetorRetiradas[NUMERO_DE_CARTAS]);
int compararCores(Carta carta1, Carta carta2);
void selectSort(Carta vetor[], int tamanho);
void imprimirCarta(Carta carta);
void trocarCartas(Carta *a, Carta *b);
void bubbleSort(Carta vetor[], int n);
void selectionSort(Carta vetor[], int n);
void insertionSort(Carta vetor[], int n);
void shellSort(Carta vetor[], int n);
int particionar2(Carta vetor[], int baixo, int alto);
void quickSort(Carta vetor[], int baixo, int alto);
void heapify2(Carta vetor[], int n, int indice);
void heapSort2(Carta vetor[], int n);


#endif

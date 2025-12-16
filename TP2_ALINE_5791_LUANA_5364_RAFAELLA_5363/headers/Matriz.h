// matriz.h
#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Matriz {
    int numeroDeCidades;
    int** matrizDistancias;
} Matriz;

Matriz* criarMatriz(int numeroDeCidades);
void gerarMatrizAleatoria(Matriz* matriz);
int calcularSomaDistancias(Matriz* matriz, int* permutacao);
void destruirMatriz(Matriz* matriz);

#endif

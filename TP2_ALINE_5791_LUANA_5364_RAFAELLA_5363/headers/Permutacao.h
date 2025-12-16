#ifndef PERMUTACAO_H
#define PERMUTACAO_H

void realizarTroca(int* vetor, int i, int j) ;
int calcularSomaDigitos(int matricula);
int calcularCidadeInicial(int restoSomaMatriculas);
int* gerarVetorPermutado(int numeroDeCidades, int restoSomaMatriculas);
int* adicionarCidadeInicialNoVetor(int* vetorPermutado, int numeroDeCidades, int cidadeInicial);
int gerarProximaPermutacao(int* arr, int n);
void encontrarMelhorPermutacao(int* vetorPermutado, int numeroDeCidades, int numeroTotalCidades, int restoSomaMatriculas);

#endif

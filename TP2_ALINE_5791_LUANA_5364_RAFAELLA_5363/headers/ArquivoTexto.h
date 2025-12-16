#ifndef ARQUIVOTEXTO_H
#define ARQUIVOTEXTO_H

void gerarMatrizAleatoriaArquivo(FILE* arquivoSaida, Matriz* matriz);
void encontrarMelhorPermutacaoArquivo(FILE* arquivoSaida, int* vetorPermutado, int numeroDeCidades, int numeroTotalCidades, int restoSomaMatriculas,Matriz* matrizDistancias) ;
void encontrarMelhorPermutacaoModoArquivo(int* vetorPermutado, int numeroDeCidades, int numeroTotalCidades, int restoSomaMatriculas, Matriz* matrizDistancias); 

#endif

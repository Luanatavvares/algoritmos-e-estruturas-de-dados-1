/*TIPO ABSTRATO DE DADOS CARTA
O primeiro TAD a ser implementado deve ser o TAD Carta. Este TAD representa uma carta
dentro do jogo, e portanto sua estrutura deve conter os campos:
● naipe (copas, espadas, ouros, paus);
● valor (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K);
● posição (para cima ou para baixo).
Uma carta tem seu naipe e valor atribuídos uma única vez, e depois esse valor não muda. Já
sua posição pode ser mudada ao longo do jogo. Além disso, esse TAD será responsável por
verificar a relação entre as cartas, ou seja, se duas cartas consecutivas formam uma sequência
de mesmo naipe, ou uma sequência de cor alternada. Assim, as operações do TAD são:
● Criar: inicializa a carta com seu naipe, valor e posição inicial. OK
● Retornar naipe;OK
● Retornar valor;OK
● Retornar posição;OK
● Alterar posição;OK
● Verificar sequência de mesmo naipe: recebe duas cartas como parâmetro, e retorna
verdadeiro caso a segunda carta seja adequada como próxima carta numa sequência
de mesmo naipe para a primeira carta. Obs.: se a primeira carta é nula, então o valor
válido para a segunda carta é um Ás; OK
● Verificar sequência alternada: recebe duas cartas como parâmetro, e retorna
verdadeiro caso a segunda carta seja adequada como próxima carta numa sequência
de cores alternadas para a primeira carta. Obs.: se a primeira carta é nula, então o
valor válido para a segunda carta é um Rei; OK
● Exibir: imprime uma representação da carta, levando em conta que se a carta estiver
virada para baixo, seu valor e naipe não devem aparecer. A forma como a carta é
representada no terminal é definida pelo grupo, sendo possível utilizar caracteres
simples, caracteres especiais, cores, etc. OK
*/
#ifndef CARTA_H
#define CARTA_H
#include <stdbool.h>
typedef enum {
    A,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    DEZ,
    J,
    Q,
    K
} Tipovalor;

typedef enum {
    PAUS,
    COPAS,
    ESPADAS,
    OUROS
} Tiponaipe;

typedef enum {
    BAIXO,
    CIMA
} Tipoposicao;

typedef struct {
    Tiponaipe naipe;
    Tipovalor valor;
    Tipoposicao posicao;
} Carta;
void Inicializa(Carta* carta1, Tiponaipe naipe, Tipovalor valor, Tipoposicao posicao);
Tiponaipe Getnaipe(const Carta* carta1);
Tipovalor Getvalor(const Carta* carta1);
Tipoposicao Getposicao(const Carta* carta1);
void Setposicao(Carta* carta1, Tipoposicao posicao);
bool Verificasequencia(const Carta* carta1, const Carta* carta2);
bool Verificasequenciaalt(const Carta* carta1, const Carta* carta2);
void Imprimi(const Carta* carta1);
#endif

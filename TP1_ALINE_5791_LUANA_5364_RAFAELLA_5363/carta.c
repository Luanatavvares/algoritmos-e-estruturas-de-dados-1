#include "carta.h"
#include <stdio.h>
// Inicializa uma carta com valores específicos.
void Inicializa(Carta* carta1, Tiponaipe naipe, Tipovalor valor, Tipoposicao posicao) {
    carta1->naipe = naipe;
    carta1->posicao = posicao;
    carta1->valor = valor;
}
// Obtém o naipe da carta.
Tiponaipe Getnaipe(const Carta* carta1) {
    return carta1->naipe;    // Retorna o naipe da carta.
}
// Obtém o valor da carta.
Tipovalor Getvalor(const Carta* carta1) {
    return carta1->valor;    // Retorna o valor da carta.
}
// Obtém a posição da carta.
Tipoposicao Getposicao(const Carta* carta1) {
    return carta1->posicao;    // Retorna a posição da carta.
}
// Define a posição da carta.
void Setposicao(Carta* carta1, Tipoposicao posicao) {
    carta1->posicao = posicao;    // Define a posição da carta.
}
bool Verificasequencia(const Carta* carta1, const Carta* carta2) {
    // Esta função verifica se duas cartas consecutivas formam uma sequência.    
    // A primeira parte da condição verifica se a carta2 é um valor maior que a carta1 em 1 unidade.
    if ((carta2->valor == carta1->valor + 1) ||
        // OU a segunda parte da condição verifica se a carta1 é um valor maior que a carta2 em 1 unidade.
        (carta1->valor == carta2->valor + 1)) {
        // Se qualquer uma das partes da condição for verdadeira, isso significa que as cartas formam uma sequência.
        return true;    // Nesse caso, a função retorna verdadeiro (true).
    } else {
        // Se ambas as partes da condição forem falsas, isso significa que as cartas não formam uma sequência.
        return false;    // Nesse caso, a função retorna falso (false).
    }
}
// Verifica se há uma sequência alternada de cartas (cores alternadas).
bool Verificasequenciaalt(const Carta* carta1, const Carta* carta2) {
    // Esta função verifica se duas cartas consecutivas formam uma sequência alternada de cores.    
    // A primeira parte da condição verifica se as cartas formam uma sequência de valores.
    if ((carta2->valor == carta1->valor + 1) || (carta1->valor == carta2->valor + 1)) {
        
        // Em seguida, verifica a cor das cartas pelo valor de naipe:
        if ((carta1->naipe % 2 == 0) && (carta2->naipe % 2 == 0)) {
            // Se ambas as cartas têm naipe par (preto), retorna falso.
            return false;    
        } else if ((carta1->naipe % 2 != 0) && (carta2->naipe % 2 != 0)) {
            // Se ambas as cartas têm naipe ímpar (vermelho), retorna falso.
            return false;    
        } else {
            // Se as cores forem alternadas, retorna verdadeiro.
            return true;     
        }
    } else {
        // Caso contrário, se não houver uma sequência de valores, retorna falso.
        return false;    
    }
}
// Imprime informações sobre a carta.
void Imprimi(const Carta* carta1) {
    if (carta1->posicao == CIMA) {
        // Carta está virada para cima, imprima valor e naipe sem espaço em branco.
        char* valor_str;
        switch (carta1->valor) {
            case A: valor_str = "A"; break;
            case DOIS: valor_str = "2"; break;
            case TRES: valor_str = "3"; break;
            case QUATRO: valor_str = "4"; break;
            case CINCO: valor_str = "5"; break;
            case SEIS: valor_str = "6"; break;
            case SETE: valor_str = "7"; break;
            case OITO: valor_str = "8"; break;
            case NOVE: valor_str = "9"; break;
            case DEZ: valor_str = "10"; break;
            case J: valor_str = "J"; break;
            case Q: valor_str = "Q"; break;
            case K: valor_str = "K"; break;
        } 
        char* naipe_str;
        switch (carta1->naipe) {
            case PAUS: naipe_str = "P"; break;
            case COPAS: naipe_str = "C"; break;
            case ESPADAS: naipe_str = "E"; break;
            case OUROS: naipe_str = "O"; break;
        }
        // Determine a cor da carta com base no naipe
        if (carta1->naipe == COPAS || carta1->naipe == OUROS) {
            printf("\x1B[31m%s%s\x1B[0m\n", valor_str, naipe_str);
        } else {
            printf("%s%s\n", valor_str, naipe_str);
        }
    } else {
        // Carta está virada para baixo, imprima apenas "Carta virada para baixo".
        printf("***\n");
    }
}

#ifndef CARTAS_H
#define CARTAS_H
#define NUMERO_DE_CARTAS 10



typedef enum {
    VERDE,
    AMARELO,
    VERMELHO,
    AZUL,
    PRETO
} Cor;



typedef enum {
    ZERO, UM, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, PULAR, VOLTAR, MAIS2, MAIS4,CORINGA
} Valor;


typedef struct {
    Valor valor;
    Cor cor;
    const char* nome;
} Carta;



typedef struct {
    Carta cartas[56];
    int tamanho;
} Baralho;


void adicionarCarta(Baralho* baralho, int valor, Cor cor);
void adicionarCartaEspecial(Baralho* baralho, int valor, Cor cor, const char* nome);
void inicializarBaralho(Baralho* baralho);
void mostrarCarta(Carta* carta);
void mostrarBaralho(Baralho* baralho);
void retirarCartasAleatorias(Baralho* baralho, Carta vetorRetiradas[NUMERO_DE_CARTAS]);
void mostrarVetorCartas(Carta vetorRetiradas[NUMERO_DE_CARTAS]);

#endif

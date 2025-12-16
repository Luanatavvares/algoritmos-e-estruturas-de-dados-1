#include <stdio.h>
#include <stdbool.h>
#include "mesa.h"
#include "carta.h"
#include "listaCartas.h"
#include <time.h>
#include <stdlib.h> 


int main() {
    srand(time(NULL)); 

    int modo;
    printf("Escolha o modo de utilizacao (1 - Interativo, 2 - Arquivo): ");
    scanf("%d", &modo);
    if (modo == 1) {
        // Modo interativo
        printf("Modo Interativo\n");
        ModoInterativo();
    } else if (modo == 2) {
        // Modo arquivo
        printf("Modo Arquivo\n");
        ModoArquivo();
    } else {
        printf("Modo invalido. Encerrando o programa.\n");
    }
    return 0;
}





    

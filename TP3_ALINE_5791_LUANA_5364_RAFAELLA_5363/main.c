#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers/Cartas.h"
#include "headers/Menu.h"
#include "headers/ordenacao.h"

int main() {
    int opcao;
    printf("1-Modo Aleatorio\n2-Modo Arquivo\nEscolha uma opção:\n");
    scanf("%d",&opcao);
    if (opcao==1){
        modoAleatorio();
    }
    else if(opcao==2){
        modoArquivo();
    }
    else{
        printf("Opção inválida");
    }

    return 0;
}

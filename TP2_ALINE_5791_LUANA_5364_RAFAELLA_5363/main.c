#include <stdio.h>
#include "headers/Permutacao.h"
#include "headers/Menu.h"

int main() {
    int opcao;
    printf("1 - Modo Arquivo\n2 - Modo Aleatório\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        char nomeArquivo[100]; 
        printf("Digite o nome do arquivo: ");
        scanf("%s", nomeArquivo);
        modoArquivo(nomeArquivo);
    } else if (opcao == 2) {
        modoAleatorio();
    } else {
        printf("Modo inválido\n");
    }

    return 0;
}

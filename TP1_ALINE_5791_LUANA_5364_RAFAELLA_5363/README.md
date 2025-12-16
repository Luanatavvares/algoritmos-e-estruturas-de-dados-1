# 🃏 Trabalho Prático 1 — Paciência 
Este projeto implementa o jogo de cartas **Paciência**, em uma das versões mais tradicionais e populares do jogo. O trabalho foi desenvolvido para a disciplina **Algoritmos e Estruturas de Dados 1 (AEDS1)** e tem como objetivo aplicar conceitos fundamentais de TADs e estruturas dinâmicas, especialmente o uso de **listas encadeadas**, requisito obrigatório do projeto.

A solução foi dividida em três TADs principais:  
- 🂠 **Carta** — representa individualmente cada carta do baralho.  
- 🎴 **Lista de Cartas** — implementada com **lista encadeada**, permitindo manipulação dinâmica das cartas.  
- ♠️ **Mesa** — controla tableau, bases, baralho, descarte e regras do jogo.  

A partir desses módulos, o programa cria o baralho, distribui as cartas nas colunas iniciais e gerencia os movimentos segundo as regras clássicas da Paciência.



##  Como Jogar

O objetivo é organizar todas as cartas nas **bases** separadas por naipe — **♠️ Espadas**, **♥️ Copas**, **♦️ Ouros**, **♣️ Paus** — em ordem crescente, do **Ás (A)** ao **Rei (K)**.

Ao iniciar o programa, um menu com ações possíveis é exibido. Cada jogada é acionada por um código:

- **CC** — Comprar carta do baralho.  
- **DB** — Mover carta do descarte para a base.  
- **DT** — Mover carta do descarte para o tableau.  
- **TB** — Mover carta do tableau para a base.  
- **BT** — Mover carta da base para o tableau.  
- **TT** — Mover cartas entre colunas do tableau.  
- **RB** — Reciclar o baralho (descarte → baralho).  
- **SA** — Sair do jogo.  

O jogo prossegue até que todas as bases estejam completas.



##  Conceitos Utilizados

Ao longo do desenvolvimento, foram aplicados:

- Estruturas dinâmicas com **listas encadeadas**.  
- Construção modular utilizando **TADs**.  
- Manipulação de memória e ponteiros.  

O trabalho reforça os fundamentos de estruturas de dados estudados na disciplina.

## Como Executar

Para compilar  e executar o jogo, faça no terminal:

```bash
gcc -o programa main.c carta.c listacartas.c mesa.c
./programa




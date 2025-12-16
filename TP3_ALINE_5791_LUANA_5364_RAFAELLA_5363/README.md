# 🃏 Trabalho Prático 3 — Ordenação das Cartas do UNO

Este trabalho tem como objetivo implementar e analisar o desempenho de seis algoritmos clássicos de ordenação aplicados a um conjunto de cartas do jogo **UNO**. A tarefa consiste em ordenar uma mão de cartas embaralhadas considerando simultaneamente **cor** e **valor**, simulando o processo de organização do baralho de forma eficiente. Além da implementação dos algoritmos, o trabalho inclui a avaliação de métricas importantes como número de comparações, número de movimentações e tempo total de processamento.

## Organização do Projeto

O código foi estruturado de forma modular para facilitar a leitura e manutenção. Os arquivos `.c` foram colocados na pasta **sources** e os arquivos `.h` na pasta **headers**, mantendo o padrão adotado nos trabalhos anteriores. O `main.c`, o `makefile`, o executável e o arquivo de entrada (`arquivotp3.txt`) permanecem na raiz do diretório, garantindo fácil acesso e execução.

## Desenvolvimento

Foram implementados **seis algoritmos de ordenação**, cada um adaptado para lidar com a lógica de comparação das cartas do UNO. A ordenação respeita primeiro as cores (🟥 vermelho, 🟦 azul, 🟩 verde, 🟨 amarelo) e depois os valores numéricos das cartas.

### Algoritmos implementados

- **BubbleSort** — compara pares de cartas adjacentes, trocando-as quando necessário. Simples e didático, mas pouco eficiente para grandes conjuntos.
- **Selection Sort** — seleciona a menor carta a cada iteração e a coloca na posição correta. Sua simplicidade o torna fácil de entender, porém não é eficiente para conjuntos maiores.
- **Insertion Sort** — insere cada carta na posição correta dentro do subarray já ordenado; eficaz para entradas pequenas ou parcialmente ordenadas.
- **ShellSort** — variação mais eficiente do Insertion Sort, ordenando inicialmente elementos distantes; melhora o desempenho em vetores maiores.
- **QuickSort** — utiliza a estratégia de dividir e conquistar para ordenar as cartas; muito eficiente na média e uma das abordagens mais rápidas do conjunto.
- **HeapSort** — constrói uma heap para reorganizar as cartas em ordem crescente; possui desempenho consistente e previsível.

Cada algoritmo possui sua própria função de ordenação e uma função auxiliar responsável por preparar o vetor de cartas, inicializar contadores de comparações e movimentações, e exibir os resultados no terminal.

Durante o desenvolvimento, também foram identificadas algumas dificuldades, especialmente relacionadas ao modo interativo na opção que exibe todas as ordenações simultaneamente e ao cálculo correto de movimentações em SelectSort e ShellSort, motivo pelo qual as saídas foram exibidas individualmente na documentação.

## Como Executar

A compilação e execução são realizadas por meio do **Makefile**, garantindo que todos os arquivos do projeto sejam compilados, mesmo estando em pastas diferentes. No terminal, basta digitar:

```bash
make
./programa

# 🚚 Trabalho Prático 2 — Problema do Caixeiro Viajante Assimétrico (ATSP)

Este trabalho implementa uma solução completa para o **Problema do Caixeiro Viajante Assimétrico (ATSP)**, um problema clássico de otimização combinatória. O objetivo é determinar a menor rota possível para que um viajante percorra todas as cidades **sem que as distâncias entre elas sejam necessariamente simétricas**, isto é, a distância de A→B pode ser diferente de B→A.

O projeto faz parte da disciplina **Algoritmos e Estruturas de Dados 1 (AEDS1)** e enfatiza conceitos fundamentais de análise de algoritmos, estruturas de dados, permutação, cálculo de custo de rotas e impacto computacional de algoritmos exaustivos.



##  Ideia Geral do Projeto

A solução desenvolvida utiliza um **algoritmo de permutação** para gerar todas as possíveis ordens de visita às cidades (exceto a cidade inicial), avaliando o custo de cada rota. A partir das permutações, o programa calcula a distância total percorrida para cada possível caminho e seleciona o de menor custo.

Para representar as distâncias entre as cidades, foi utilizada uma **matriz NxN**, onde cada posição `M[i][j]` armazena o custo de viajar da cidade `i` para a cidade `j`. As posições da diagonal principal (`M[i][i]`) têm valor zero, já que não há custo para permanecer na mesma cidade.

Além disso, o programa permite dois modos de entrada:
- **📄 Modo arquivo** – leituras das distâncias a partir de um arquivo texto.
- **🎲 Modo aleatório** – o próprio usuário informa o número de cidades e o programa gera as distâncias automaticamente.

Para definir a cidade inicial e final, foi utilizado um valor calculado a partir das matrículas do grupo, garantindo um ponto fixo para início e término da viagem.



## Conceitos Abordados

Durante o desenvolvimento, foram trabalhados:

-   **Permutação** 
  Usado para gerar todas as possíveis ordens de visita às cidades, avaliando todos os caminhos possíveis.

-  **Cálculo de rotas**  
  Para cada permutação, o programa soma as distâncias consecutivas presentes na matriz de custos.

-  **Representação em matriz**  
  A matriz de distâncias é alocada dinamicamente e armazenada em estrutura própria.

- **Análise de complexidade**  
  O trabalho avalia o impacto do crescimento do número de cidades no tempo de execução.

-  **Organização modular (TAD + Pastas)**  
  Os arquivos foram divididos em:
  - `headers/` → arquivos `.h`
  - `sources/` → arquivos `.c`  



##  Como Executar

O projeto possui um **Makefile**, facilitando a compilação.  
No terminal, dentro do diretório do trabalho, execute:

```bash
make

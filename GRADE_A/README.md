# Simulação de Epidemia - Trabalho do Grau A

Este repositório contém o código-fonte de uma simulação de contágio, desenvolvido como parte do Trabalho do Grau A. A aplicação modela a propagação de uma infecção em uma população, considerando fatores como:
- População total
- Número inicial de pessoas infectadas
- Taxa de contágio
- Porcentagem de população vacinada
- Efetividade da vacinação

Além disso, o programa incorpora eventos aleatórios que podem alterar a taxa de contágio durante a simulação, tais como:
- Mutação mais contagiosa
- Alerta gerado pela mídia
- Isolamento voluntário
- Aglomeração

## Funcionalidades

- **Entrada de dados interativa:** O usuário fornece parâmetros essenciais para a simulação, garantindo a execução conforme os dados reais fornecidos.
- **Eventos aleatórios:** Cada dia da simulação pode disparar um evento que modifica a taxa de contágio, refletindo cenários realistas.
- **Cálculo dinâmico:** A simulação realiza o cálculo diário dos infectados, ajustando conforme a vacinação e os eventos que ocorrem, até que toda a população esteja infectada ou o período simulado se esgote.
- **Resumo final:** Ao término da simulação, o programa apresenta um resumo detalhado com o total de infectados, o número de pessoas vacinadas, quantos vacinados foram infectados e a população que permaneceu saudável.

## Requisitos

- Compilador C (como o GCC)

## Como Executar

1. Baixe o repositório

2. Rode o comando ``` gcc final.c -o main```

3. Rode o comando ```./main```

## Detalhes do Trabalho

Este é o Trabalho do Grau A e foi desenvolvido pelo grupo formado por:

- Pedro Klein

- Nicoly Barros

- Gustavo Lima

O projeto foi idealizado e criado com o objetivo de unir conceitos de programação, modelagem de eventos e simulação computacional para abordar cenários de epidemiologia de forma interativa e educativa.
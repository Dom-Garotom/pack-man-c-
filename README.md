# Projeto: Jogo de Coleta em Tabuleiro

Este projeto é um jogo de coleta simples desenvolvido em C++. O jogador controla uma posição em um tabuleiro 20x20, tentando "comer" um item que aparece aleatoriamente no tabuleiro. O jogo usa uma interface de texto para exibir o tabuleiro e mostrar a posição do jogador.

## Funcionalidades

- **Movimento do Jogador**: O jogador se move automaticamente em direção ao item, usando uma lógica para se aproximar vertical e horizontalmente.
- **Sistema de Pontuação**: Cada vez que o jogador alcança o item, ganha um ponto.
- **Embaralhador**: As posições iniciais do jogador e do item são aleatórias e o item muda de posição após ser "comido".
- **Tabuleiro**: Exibição de um tabuleiro 20x20, onde o jogador é representado por `@` e o item por `#`.

## Compilação e Execução

Para compilar e executar o jogo, siga estas etapas:

1. Compile o código:
```tsx
g++ -o jogo main.cpp
```
2. Execute o jogo:
```tsx
./jogo
```

### Exemplo de Saída:
````tsx
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  
+  +  +  +  +  @  +  +  +  +  +  +  +  +  +  +  +  +  +  +  
+  +  +  +  +  +  +  +  +  +  +  +  +  +  +  +  #  +  +  +  
...
Pontos: 0
````


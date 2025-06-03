#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
     int tabuleiro [10][10] = {0}; // tabuleiro inicial
    int navio1 [3] = {3}; //navio 1 de tamanho 3
    int navio2 [3] = {3}; // navio 2 de tamanho 3
    int i,j;
    int tamanho1 = sizeof(navio1) / sizeof(navio1[0]); // tamanho do navio 1
    int tamanho2 = sizeof(navio2) / sizeof(navio2[0]); // tamanho do navio 2
    int posicaoinicial1 = 4; // posição inicial do navio 1
    int posicaoinicial2 = 5; // posição inicial do navio 2

    // verifica se a posição inicial do navio 1 é válida para que o navio esteja dentro do tabuleiro
    if (posicaoinicial1 + tamanho1 > 10) {
        printf("O navio 1 não está fora dos limites do tabuleiro, escolha outra posição inicial!\n");
        return 1; // encerra o programa se a posição inicial for inválida
    }
    // verifica se a posição inicial do navio 2 é válida para que o navio esteja dentro do tabuleiro
    if (posicaoinicial2 + tamanho2 > 10) {
        printf("O navio 2 não está fora dos limites do tabuleiro, escolha outra posição inicial!\n");
        return 1; // encerra o programa se a posição inicial for inválida
    }
    
    // Posiciona navio1 na linha 2, colunas 4, 5 e 6 (horizontal)
    for (i = 0; i < tamanho1 ; i++) {
        tabuleiro[2][posicaoinicial1 + i] = 3; // representa navio1, sendo colocado na sua posição inicial mais tres unidades para a direita
    }

    //Verificar se o navio 2 irá se sobrepor ao navio 1
    for (i = 0; i < tamanho2; i++) {
        if (tabuleiro[posicaoinicial2 + i][7] != 0) {
            printf("O navio 2 não pode ser posicionado nesta nessa posição!\n");
            return 1; // encerra o programa se houver sobreposição
        }
    }

    // Posiciona navio2 na coluna 7, linhas 5, 6 e 7 (vertical)
    for (i = 0; i < tamanho2; i++) {
        tabuleiro[posicaoinicial2 + i][7] = 3; //representa navio2, sendo colocado na sua posição inicial mais tres unidades para baixo
    }

    //exibir tabuleiro
    for (i = 0; i < 10; i++) {
        for ( j = 0; j < 10; j++)
    {
        printf("%d ",tabuleiro[i][j]);
    }
    printf("\n");
    }
 

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}

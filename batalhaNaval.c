#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
void naviohorizontal(int tabuleiro[10][10], int posicao[2], int tamanho) {
    //verificar se a posição do navio está dentro dos limites do tabuleiro
    if (posicao[0] < 0 || posicao[0] >= 10 || posicao[1] < 0 || posicao[1] + tamanho > 10) {
        printf("Posição inválida para o navio horizontal.\n");
        return;
    }else if (tabuleiro[posicao[0]][posicao[1]] != 0) {
        printf("Posição já ocupada por outro navio.\n");
        return;
    } else {
        // Coloca o navio horizontalmente no tabuleiro
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[posicao[0]][posicao[1] + i] = 3; // Marca a posição do navio no tabuleiro
        }
    }
}

void naviovertical(int tabuleiro[10][10], int posicao[2], int tamanho) {
    //verificar se a posição do navio está dentro dos limites do tabuleiro
    if (posicao[0] < 0 || posicao[0] + tamanho > 10 || posicao[1] < 0 || posicao[1] >= 10) {
        printf("Posição inválida para o navio vertical.\n");
        return;
    }else if (tabuleiro[posicao[0]][posicao[1]] != 0) {
        printf("Posição já ocupada por outro navio.\n");
        return;
    } else {
        // Coloca o navio verticalmente no tabuleiro
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[posicao[0] + i][posicao[1]] = 3; // Marca a posição do navio no tabuleiro
        }
    }
    }

void naviodiagonal_direita(int tabuleiro[10][10], int posicao[2], int tamanho) {
    //verificar se a posição do navio está dentro dos limites do tabuleiro
    if (posicao[0] < 0 || posicao[0] + tamanho > 10 || posicao[1] < 0 || posicao[1] + tamanho > 10) {
        printf("Posição inválida para o navio diagonal direita.\n");
        return;
    }else if (tabuleiro[posicao[0]][posicao[1]] != 0) {
        printf("Posição já ocupada por outro navio.\n");
        return;
    } else {
        // Coloca o navio diagonalmente para a direita no tabuleiro
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[posicao[0] + i][posicao[1] + i] = 3; // Marca a posição do navio no tabuleiro
        }
    }
}

void naviodiagonal_esquerda(int tabuleiro[10][10], int posicao[2], int tamanho) {
    //verificar se a posição do navio está dentro dos limites do tabuleiro
    if (posicao[0] < 0 || posicao[0] + tamanho > 10 || posicao[1] < tamanho - 1 || posicao[1] >= 10) {
        printf("Posição inválida para o navio diagonal esquerda.\n");
        return;
    }else if (tabuleiro[posicao[0]][posicao[1]] != 0) {
        printf("Posição já ocupada por outro navio.\n");
        return;
    } else {
        // Coloca o navio diagonalmente para a esquerda no tabuleiro
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[posicao[0] + i][posicao[1] - i] = 3; // Marca a posição do navio no tabuleiro
        }
    }
}

void ataquecone(int tabuleiro[10][10], int posicao[2]) {
    // Verifica se a posição do ataque está dentro do tabuleiro
    if (posicao[0] < 0 || posicao[0] >= 10 || posicao[1] < 0 || posicao[1] >=10) {
        printf("posição de ataque inválida!\n");
        return;
    }
    // Marca ataque no tabuleiro
    for(int i=0; i<3; i++) {
        int linha = posicao[0] + i;
        if (linha >= 10) break; // evita ultrapassar limites do tabuleiro
        for (int j = posicao[1] - i; j <= posicao[1] + i; j++) {
            if (j >= 0 && j < 10) {
                tabuleiro[linha][j] = 1;
            }
        }
        
    }
}

void ataquecruz(int tabuleiro[10][10], int posicao[2]) {
    // Verifica se a posição está dentro do tabuleiro
    if (posicao[0] < 0 || posicao[0] >=10 || posicao[1] < 0 || posicao[1] >=10) {
        printf("posição de ataque inválida!\n");
        return;
    }
    // Marca a linha acima do centro
    tabuleiro[posicao[0] -1][posicao[1]] = 1;
    // Marca a linha do centro
    for(int j = posicao[1] -2; j <= posicao[1] +2; j++) {
        tabuleiro[posicao[0]][j] = 1;
    }
    // Marca a linha abaixo do centro
    tabuleiro[posicao[0] + 1][posicao[1]] = 1;
}

void ataqueoctaedro(int tabuleiro[10][10], int posicao[2]) {
    int centro_linha = posicao[0];
    int centro_coluna = posicao[1];
    // Verifica se a posição do ataque está dentro do tabuleiro
    if (posicao[0] < 0 || posicao[0] >= 10 || posicao[1] < 0 || posicao[1] >= 10) {
        printf("posição de ataque inválida!\n");
        return;
    }
    // Marca ataque no tabuleiro
     for (int i = -2; i <= 2; i++) {
        int linha = centro_linha + i;
        int alcance = (i < 0) ? 2 + i : 2 - i;  // quantidade de colunas à esquerda e direita
        for (int j = -alcance; j <= alcance; j++) {
            int coluna = centro_coluna + j;
            tabuleiro[linha][coluna] = 1;
        }
    }
}


int main() {
   int tabuleiro [10][10] = {0}; // tabuleiro inicial
    int navio1 [3] = {3}; //navio 1 de tamanho 3
    int navio2 [3] = {3}; // navio 2 de tamanho 3
    int navio3 [3] = {3}; // navio 3 de tamanho 3
    int navio4 [3] = {3}; // navio 4 de tamanho 3
    int i,j;
    int tamanho1 = sizeof(navio1) / sizeof(navio1[0]); // tamanho do navio 1
    int tamanho2 = sizeof(navio2) / sizeof(navio2[0]); // tamanho do navio 2
    int tamanho3 = sizeof(navio3) / sizeof(navio3[0]); // tamanho do navio 3
    int tamanho4 = sizeof(navio4) / sizeof(navio4[0]); // tamanho do navio 4    
    int posicaoinicial1 [1][2] = {{1, 0}}; // posição inicial do navio 1
    int posicaoinicial2 [1][2] = {{5, 6}}; // posição inicial do navio 2
    int posicaoinicial3 [1][2] = {{7, 1}}; // posição inicial do navio 3    
    int posicaoinicial4 [1][2] = {{1, 8}}; // posição inicial do navio 4

    //colocando navio 1 horizontal
    //naviohorizontal(tabuleiro, posicaoinicial1[0], tamanho1);

    //colocando navio 2 vertical
    //naviovertical(tabuleiro, posicaoinicial2[0], tamanho2);

    //colocando navio 3 diagonal direita
    //naviodiagonal_direita(tabuleiro, posicaoinicial3[0], tamanho3);

    //colocando navio 4 diagonal esquerda
    //naviodiagonal_esquerda(tabuleiro, posicaoinicial4[0], tamanho4);

    // executando ataque em cone na posição (2, 2)
    int posicaoataque[2] = {0, 2};
    ataquecone(tabuleiro, posicaoataque);

    // executando ataque em cruz na posiçao (5, 5)
    int posicaoataque2[2] = {4, 7};
    ataquecruz(tabuleiro, posicaoataque2);

    // executa ataque em octaedro na posição (7, 7)
    int posicaoataque3[2] = {7, 2};
    ataqueoctaedro(tabuleiro, posicaoataque3);

    //exibir tabuleiro
    for (i = 0; i < 10; i++) {
        for ( j = 0; j < 10; j++)
    {
        printf("%d  ",tabuleiro[i][j]);
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

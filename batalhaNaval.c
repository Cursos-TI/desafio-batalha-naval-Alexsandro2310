#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5 // Valor que representa área de habilidade

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    int sobreposicao = 0;

    // === Posicionamento dos navios (mesmo código de antes) ===
    int linhaH = 2, colunaH = 4;
    if (colunaH + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++)
                tabuleiro[linhaH][colunaH + i] = 3;
        } else {
            printf("Erro: Navio horizontal sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites.\n");
        return 1;
    }

    sobreposicao = 0;
    int linhaV = 5, colunaV = 7;
    if (linhaV + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++)
                tabuleiro[linhaV + i][colunaV] = 3;
        } else {
            printf("Erro: Navio vertical sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites.\n");
        return 1;
    }

    sobreposicao = 0;
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + NAVIO <= TAMANHO && colunaD1 + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++)
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
        } else {
            printf("Erro: Navio diagonal sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio diagonal fora dos limites.\n");
        return 1;
    }

    sobreposicao = 0;
    int linhaD2 = 1, colunaD2 = 8;
    if (linhaD2 + NAVIO <= TAMANHO && colunaD2 - (NAVIO - 1) >= 0) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++)
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
        } else {
            printf("Erro: Navio diagonal sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio diagonal fora dos limites.\n");
        return 1;
    }

    // === MATRIZES DE HABILIDADES (5x5) ===
    int cone[5][5] = {0};     // Matriz para habilidade em forma de cone
    int cruz[5][5] = {0};     // Matriz para habilidade em forma de cruz
    int octaedro[5][5] = {0}; // Matriz para habilidade em forma de octaedro (losango)

    // === Construção dinâmica da habilidade CONE ===
    for (int i = 0; i < 5; i++) { // linhas
        for (int j = 0; j < 5; j++) { // colunas
            if (j >= 2 - i && j <= 2 + i) // forma de cone voltado para baixo
                cone[i][j] = 1;
        }
    }

    // === Construção dinâmica da habilidade CRUZ ===
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1; // linha central
        cruz[i][2] = 1; // coluna central
    }

    // === Construção dinâmica da habilidade OCTAEDRO ===
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) // condição de losango
                octaedro[i][j] = 1;
        }
    }

    // === Sobreposição das habilidades no tabuleiro ===

    // Ponto de origem da habilidade no tabuleiro
    int origemLinha = 6, origemColuna = 2;

    // Sobreposição da matriz CONE
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int lin = origemLinha + i - 2;
            int col = origemColuna + j - 2;
            // Validação de limites e sobreposição
            if (lin >= 0 && lin < TAMANHO && col >= 0 && col < TAMANHO) {
                if (cone[i][j] == 1 && tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = HABILIDADE;
            }
        }
    }

    // Ponto de origem da habilidade CRUZ
    origemLinha = 4;
    origemColuna = 4;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int lin = origemLinha + i - 2;
            int col = origemColuna + j - 2;
            if (lin >= 0 && lin < TAMANHO && col >= 0 && col < TAMANHO) {
                if (cruz[i][j] == 1 && tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = HABILIDADE;
            }
        }
    }

    // Ponto de origem da habilidade OCTAEDRO
    origemLinha = 7;
    origemColuna = 7;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int lin = origemLinha + i - 2;
            int col = origemColuna + j - 2;
            if (lin >= 0 && lin < TAMANHO && col >= 0 && col < TAMANHO) {
                if (octaedro[i][j] == 1 && tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = HABILIDADE;
            }
        }
    }

    // === EXIBIÇÃO DO TABULEIRO FINAL ===
    printf("\n=== Tabuleiro Batalha Naval com Habilidades ===\n\n");

    printf("   ");
    for (int col = 0; col < TAMANHO; col++) {
        printf(" %c", 'A' + col);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" ~"); // água
            else if (tabuleiro[i][j] == 3)
                printf(" N"); // navio
            else if (tabuleiro[i][j] == 5)
                printf(" *"); // área de habilidade
        }
        printf("\n");
    }

    return 0;
}

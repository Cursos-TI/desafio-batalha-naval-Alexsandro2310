#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10
#define NAVIO 3 

int main() {
    
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    int sobreposicao = 0; 

    // === NAVIO 1 - Horizontal ===
    int linhaH = 2;
    int colunaH = 4;

    
    if (colunaH + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        } else {
            printf("Erro: Navio horizontal sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites.\n");
        return 1;
    }

    sobreposicao = 0; 

    // === NAVIO 2 - Vertical ===
    int linhaV = 5;
    int colunaV = 7;

    
    if (linhaV + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Erro: Navio vertical sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites.\n");
        return 1;
    }

    sobreposicao = 0; 

    // === NAVIO 3 - Diagonal 
    int linhaD1 = 0;
    int colunaD1 = 0;

    // posicionamento diagonal 
    if (linhaD1 + NAVIO <= TAMANHO && colunaD1 + NAVIO <= TAMANHO) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        } else {
            printf("Erro: Navio diagonal ↘ sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio diagonal ↘ fora dos limites.\n");
        return 1;
    }

    sobreposicao = 0; 

    // === NAVIO 4 - Diagonal 
    int linhaD2 = 1;
    int colunaD2 = 8;

    
    if (linhaD2 + NAVIO <= TAMANHO && colunaD2 - (NAVIO - 1) >= 0) {
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        } else {
            printf("Erro: Navio diagonal ↙ sobrepõe outro navio.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio diagonal ↙ fora dos limites.\n");
        return 1;
    }

    // === EXIBINDO O TABULEIRO ===
    printf("\n=== Tabuleiro Batalha Naval ===\n\n");

    // Cabeçalho das colunas
    printf("   ");
    for (int col = 0; col < TAMANHO; col++) {
        printf(" %c", 'A' + col);
    }
    printf("\n");

    // Linhas com conteúdo do tabuleiro
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

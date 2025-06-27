#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10
#define NAVIO 3 // ← LINHA NOVA: Define o tamanho fixo dos navios

int main() {
    // Matriz 10x10 representando o tabuleiro (inicialmente só com água = 0)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    int sobreposicao = 0; // ← LINHA NOVA: Variável para checar sobreposição

    // Tamanho fixo dos navios
    int tamanhoNavio = 3;

    // Coordenadas iniciais dos navios (definidas no código)
    // Navio 1: horizontal
    int linhaNavio1 = 2;
    int colunaNavio1 = 4;

    // Navio 2: vertical
    int linhaNavio2 = 5;
    int colunaNavio2 = 7;

    // Validação: garantir que o navio 1 (horizontal) cabe no tabuleiro
    if (colunaNavio1 + tamanhoNavio <= TAMANHO) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaNavio1][colunaNavio1 + i] = 3;
        }
    } else {
        printf("Erro: Navio 1 (horizontal) ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Validação: garantir que o navio 2 (vertical) cabe no tabuleiro e não sobrepõe
    int sobreposicao = 0;
    if (linhaNavio2 + tamanhoNavio <= TAMANHO) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaNavio2 + i][colunaNavio2] != 0) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaNavio2 + i][colunaNavio2] = 3;
            }
        } else {
            printf("Erro: Navio 2 (vertical) sobrepõe outro navio.\n");
            return 1;
        }

    } else {
        printf("Erro: Navio 2 (vertical) ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Exibindo o tabuleiro com cabeçalho de letras
    printf("=== Tabuleiro Batalha Naval ===\n\n");
    

    // Imprime letras das colunas
    printf("   ");
    for (int col = 0; col < TAMANHO; col++) {
        printf(" %c", 'A' + col);
    }
    printf("\n");

    // Imprime as linhas com rótulo numérico
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i); // Número da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

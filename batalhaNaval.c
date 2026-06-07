#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // 1. Representação do Tabuleiro: Matriz 10x10 inicializada com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Vetores unidimensionais para representar os navios (cada posição com valor 3)
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais (definidas diretamente no código)
    // Navio Horizontal: começará na linha 2, coluna 3 e ocupará as colunas 3, 4 e 5.
    int linha_h = 2;
    int coluna_h = 3;

    // Navio Vertical: começará na linha 5, coluna 6 e ocupará as linhas 5, 6 e 7.
    int linha_v = 5;
    int coluna_v = 6;

    // 2. Validação de Limites (Garantir que os navios caibam no tabuleiro)
    if (coluna_h + TAMANHO_NAVIO > TAMANHO_TABULEIRO || linha_v + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Os navios ultrapassam os limites do tabuleiro!\n");
        return 1;
    }

    // Validação de Sobreposição Simplificada
    // Como o horizontal usa a linha 'linha_h' (2) e o vertical usa a coluna 'coluna_v' (6),
    // eles só se cruzariam se a linha do horizontal passasse pelo vertical E a coluna do vertical passasse pelo horizontal.
    if (linha_h >= linha_v && linha_h < linha_v + TAMANHO_NAVIO &&
        coluna_v >= coluna_h && coluna_v < coluna_h + TAMANHO_NAVIO) {
        printf("Erro: Os navios estão se sobrepondo!\n");
        return 1;
    }

    // 3. Posicionamento dos Navios na Matriz
    // Posicionando o Navio Horizontal (varia a coluna)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }

    // Posicionando o Navio Vertical (varia a linha)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
    }

    // 4. Exibição do Tabuleiro no Console
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    
    // Loops aninhados para percorrer as linhas e colunas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Imprime o valor da posição seguido de um espaço para melhor legibilidade
            printf("%d ", tabuleiro[i][j]);
        }
        // Quebra de linha ao final de cada linha da matriz
        printf("\n");
    }

    return 0;
}
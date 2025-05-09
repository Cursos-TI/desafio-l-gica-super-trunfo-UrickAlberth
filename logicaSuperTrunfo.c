#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char nome_pais[50];       // Nome do país
    int populacao;            // População
    float area;               // Área em km²
    float pib;                // PIB em milhões
    int pontos_turisticos;    // Número de pontos turísticos
    float densidade_dem;      // Densidade demográfica (calculada)
} Carta;

// Função para calcular densidade demográfica
void calcular_densidade(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_dem = carta->populacao / carta->area;
    } else {
        carta->densidade_dem = 0;
    }
}

// Função para exibir o menu e obter a escolha do usuário
int exibir_menu() {
    int escolha;
    printf("\n=== Menu de Comparação ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha);
    return escolha;
}

// Função para comparar duas cartas com base no atributo escolhido
void comparar_cartas(Carta carta1, Carta carta2, int escolha) {
    printf("\nComparação de cartas:\n");

    // Variáveis para armazenar os valores a comparar
    float valor1, valor2;
    char atributo[30];

    // Determinar o atributo e os valores com base na escolha
    switch (escolha) {
        case 1: // População
            strcpy(atributo, "População");
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            printf("Atributo: %s\n", atributo);
            printf("Carta 1 - %s: %d\n", carta1.nome_pais, (int)valor1);
            printf("Carta 2 - %s: %d\n", carta2.nome_pais, (int)valor2);
            break;
        case 2: // Área
            strcpy(atributo, "Área");
            valor1 = carta1.area;
            valor2 = carta2.area;
            printf("Atributo: %s\n", atributo);
            printf("Carta 1 - %s: %.2f km²\n", carta1.nome_pais, valor1);
            printf("Carta 2 - %s: %.2f km²\n", carta2.nome_pais, valor2);
            break;
        case 3: // PIB
            strcpy(atributo, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            printf("Atributo: %s\n", atributo);
            printf("Carta 1 - %s: %.2f milhões\n", carta1.nome_pais, valor1);
            printf("Carta 2 - %s: %.2f milhões\n", carta2.nome_pais, valor2);
            break;
        case 4: // Pontos Turísticos
            strcpy(atributo, "Pontos Turísticos");
            valor1 = carta1.pontos_turisticos;
            valor2 = carta2.pontos_turisticos;
            printf("Atributo: %s\n", atributo);
            printf("Carta 1 - %s: %d\n", carta1.nome_pais, (int)valor1);
            printf("Carta 2 - %s: %d\n", carta2.nome_pais, (int)valor2);
            break;
        case 5: // Densidade Demográfica
            strcpy(atributo, "Densidade Demográfica");
            valor1 = carta1.densidade_dem;
            valor2 = carta2.densidade_dem;
            printf("Atributo: %s\n", atributo);
            printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nome_pais, valor1);
            printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nome_pais, valor2);
            break;
        default:
            printf("Opção inválida! Comparação cancelada.\n");
            return;
    }

    // Lógica de comparação usando if-else aninhados
    if (escolha == 5) { // Densidade Demográfica: menor valor vence
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_pais);
        } else if (valor2 < valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_pais);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else { // Outros atributos: maior valor vence
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_pais);
        } else if (valor2 > valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_pais);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    // Definição da primeira carta (Brasil)
    Carta carta1;
    strcpy(carta1.nome_pais, "Brasil");
    carta1.populacao = 213000000;
    carta1.area = 8515767.0;
    carta1.pib = 1900000.0;
    carta1.pontos_turisticos = 15;

    // Definição da segunda carta (Argentina)
    Carta carta2;
    strcpy(carta2.nome_pais, "Argentina");
    carta2.populacao = 45000000;
    carta2.area = 2780400.0;
    carta2.pib = 500000.0;
    carta2.pontos_turisticos = 10;

    // Calcular densidade demográfica para ambas as cartas
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    // Exibir as cartas
    printf("=== Carta 1 ===\n");
    printf("País: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f milhões\nPontos Turísticos: %d\nDensidade: %.2f hab/km²\n",
           carta1.nome_pais, carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos, carta1.densidade_dem);
    printf("\n=== Carta 2 ===\n");
    printf("País: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f milhões\nPontos Turísticos: %d\nDensidade: %.2f hab/km²\n",
           carta2.nome_pais, carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos, carta2.densidade_dem);

    // Obter escolha do usuário
    int escolha = exibir_menu();

    // Comparar as cartas com base na escolha
    comparar_cartas(carta1, carta2, escolha);

    return 0;
}

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
    carta->densidade_dem = (carta->area > 0) ? carta->populacao / carta->area : 0;
}

// Função para exibir o menu de atributos
void exibir_menu(int atributo_excluido) {
    printf("\n=== Escolha um atributo ===\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    if (atributo_excluido != 0) {
        printf("(Atributo %d já escolhido e não disponível)\n", atributo_excluido);
    }
    printf("Digite sua escolha (1-5): ");
}

// Função para validar a escolha do atributo
int validar_escolha(int escolha, int atributo_excluido) {
    if (escolha < 1 || escolha > 5) {
        return 0; // Escolha inválida
    }
    if (escolha == atributo_excluido) {
        return 0; // Atributo já escolhido
    }
    return 1; // Escolha válida
}

// Função para obter o valor de um atributo da carta
float obter_valor_atributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontos_turisticos;
        case 5: return carta.densidade_dem;
        default: return 0;
    }
}

// Função para obter o nome do atributo
void obter_nome_atributo(int atributo, char *nome) {
    switch (atributo) {
        case 1: strcpy(nome, "População"); break;
        case 2: strcpy(nome, "Área"); break;
        case 3: strcpy(nome, "PIB"); break;
        case 4: strcpy(nome, "Pontos Turísticos"); break;
        case 5: strcpy(nome, "Densidade Demográfica"); break;
        default: strcpy(nome, "Desconhecido"); break;
    }
}

// Função para comparar dois atributos e calcular a soma
void comparar_cartas(Carta carta1, Carta carta2, int atributo1, int atributo2) {
    printf("\n=== Resultado da Comparação ===\n");

    // Obter nomes dos atributos
    char nome_atributo1[30], nome_atributo2[30];
    obter_nome_atributo(atributo1, nome_atributo1);
    obter_nome_atributo(atributo2, nome_atributo2);

    // Obter valores dos atributos
    float valor1_atr1 = obter_valor_atributo(carta1, atributo1);
    float valor2_atr1 = obter_valor_atributo(carta2, atributo1);
    float valor1_atr2 = obter_valor_atributo(carta1, atributo2);
    float valor2_atr2 = obter_valor_atributo(carta2, atributo2);

    // Exibir valores dos atributos
    printf("Atributo 1: %s\n", nome_atributo1);
    printf("%s: %.2f\n", carta1.nome_pais, valor1_atr1);
    printf("%s: %.2f\n", carta2.nome_pais, valor2_atr1);

    printf("\nAtributo 2: %s\n", nome_atributo2);
    printf("%s: %.2f\n", carta1.nome_pais, valor1_atr2);
    printf("%s: %.2f\n", carta2.nome_pais, valor2_atr2);

    // Calcular soma dos atributos
    float soma_carta1 = valor1_atr1 + valor1_atr2;
    float soma_carta2 = valor2_atr1 + valor2_atr2;

    // Comparação individual para cada atributo
    printf("\nComparação Individual:\n");
    // Atributo 1
    if (atributo1 == 5) { // Densidade Demográfica: menor vence
        printf("%s: %s\n", nome_atributo1, 
               (valor1_atr1 < valor2_atr1) ? carta1.nome_pais : 
               (valor2_atr1 < valor1_atr1) ? carta2.nome_pais : "Empate");
    } else { // Outros atributos: maior vence
        printf("%s: %s\n", nome_atributo1, 
               (valor1_atr1 > valor2_atr1) ? carta1.nome_pais : 
               (valor2_atr1 > valor1_atr1) ? carta2.nome_pais : "Empate");
    }

    // Atributo 2
    if (atributo2 == 5) { // Densidade Demográfica: menor vence
        printf("%s: %s\n", nome_atributo2, 
               (valor1_atr2 < valor2_atr2) ? carta1.nome_pais : 
               (valor2_atr2 < valor1_atr2) ? carta2.nome_pais : "Empate");
    } else { // Outros atributos: maior vence
        printf("%s: %s\n", nome_atributo2, 
               (valor1_atr2 > valor2_atr2) ? carta1.nome_pais : 
               (valor2_atr2 > valor1_atr2) ? carta2.nome_pais : "Empate");
    }

    // Exibir soma dos atributos
    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", carta1.nome_pais, soma_carta1);
    printf("%s: %.2f\n", carta2.nome_pais, soma_carta2);

    // Determinar vencedor pela soma
    printf("\nResultado Final: ");
    if (soma_carta1 > soma_carta2) {
        printf("%s venceu!\n", carta1.nome_pais);
    } else if (soma_carta2 > soma_carta1) {
        printf("%s venceu!\n", carta2.nome_pais);
    } else {
        printf("Empate!\n");
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

    // Calcular densidade demográfica
    calcular_densidade(&carta1);
    calcular_densidade(&carta2);

    // Exibir informações das cartas
    printf("=== Carta 1 ===\n");
    printf("País: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f milhões\nPontos Turísticos: %d\nDensidade: %.2f hab/km²\n",
           carta1.nome_pais, carta1.populacao, carta1.area, carta1.pib, carta1.pontos_turisticos, carta1.densidade_dem);
    printf("\n=== Carta 2 ===\n");
    printf("País: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f milhões\nPontos Turísticos: %d\nDensidade: %.2f hab/km²\n",
           carta2.nome_pais, carta2.populacao, carta2.area, carta2.pib, carta2.pontos_turisticos, carta2.densidade_dem);

    // Escolha do primeiro atributo
    int atributo1, atributo2;
    do {
        exibir_menu(0);
        scanf("%d", &atributo1);
        if (!validar_escolha(atributo1, 0)) {
            printf("Escolha inválida! Tente novamente.\n");
        }
    } while (!validar_escolha(atributo1, 0));

    // Escolha do segundo atributo
    do {
        exibir_menu(atributo1);
        scanf("%d", &atributo2);
        if (!validar_escolha(atributo2, atributo1)) {
            printf("Escolha inválida ou atributo já selecionado! Tente novamente.\n");
        }
    } while (!validar_escolha(atributo2, atributo1));

    // Comparar as cartas
    comparar_cartas(carta1, carta2, atributo1, atributo2);

    return 0;
}

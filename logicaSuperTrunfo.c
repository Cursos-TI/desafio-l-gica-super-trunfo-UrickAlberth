#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];           // Sigla do estado (ex: SP, RJ)
    char codigo[10];          // Código da carta
    char nome_cidade[50];     // Nome da cidade
    int populacao;            // População da cidade
    float area;               // Área em km²
    float pib;                // PIB em milhões
    int pontos_turisticos;    // Número de pontos turísticos
    float densidade_pop;      // Densidade populacional (calculada)
    float pib_per_capita;     // PIB per capita (calculado)
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcular_metricas(Carta *carta) {
    carta->densidade_pop = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nome_cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade_pop);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
}

// Função para comparar duas cartas com base em um atributo
void comparar_cartas(Carta carta1, Carta carta2) {
    // Atributo escolhido para comparação: População
    printf("\nComparação de cartas (Atributo: População):\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.nome_cidade, carta2.estado, carta2.populacao);

    // Comparação: maior população vence
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Definição da primeira carta (São Paulo)
    Carta carta1;
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "SP001");
    strcpy(carta1.nome_cidade, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 750000.0;
    carta1.pontos_turisticos = 10;

    // Definição da segunda carta (Rio de Janeiro)
    Carta carta2;
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "RJ001");
    strcpy(carta2.nome_cidade, "Rio de Janeiro");
    carta2.populacao = 6000000;
    carta2.area = 1200.0;
    carta2.pib = 350000.0;
    carta2.pontos_turisticos = 8;

    // Calcular densidade populacional e PIB per capita para ambas as cartas
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);

    // Exibir os dados das duas cartas
    printf("=== Carta 1 ===\n");
    exibir_carta(carta1);
    printf("\n=== Carta 2 ===\n");
    exibir_carta(carta2);

    // Comparar as cartas
    comparar_cartas(carta1, carta2);

    return 0;
}

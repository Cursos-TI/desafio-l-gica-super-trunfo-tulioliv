#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[50];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcularIndicadores(Carta *carta) {
    carta->densidadePopulacional = (float)carta->populacao / carta->area;
    if (carta->populacao != 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0; // Evita divisão por zero
    }
}

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Cadastro da Carta:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado); // Permite espaços no nome
    printf("Código da Carta: ");
    scanf("%s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    calcularIndicadores(carta); // Calcula densidade e PIB per capita
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
}

// Função para comparar duas cartas com base em um atributo
void compararCartas(Carta carta1, Carta carta2, char *atributo) {
    printf("\nComparando cartas...\n");
    exibirCarta(carta1);
    printf("\nVS\n");
    exibirCarta(carta2);
    printf("\n");

    if (strcmp(atributo, "populacao") == 0) {
        printf("Comparando por População:\n");
        printf("Carta 1: %d\n", carta1.populacao);
        printf("Carta 2: %d\n", carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Carta 1 vence!\n");
        } else if (carta2.populacao > carta1.populacao) {
            printf("Carta 2 vence!\n");
        } else {
            printf("Empate!\n");
        }
    } else if (strcmp(atributo, "area") == 0) {
        printf("Comparando por Área:\n");
        printf("Carta 1: %.2f\n", carta1.area);
        printf("Carta 2: %.2f\n", carta2.area);
        if (carta1.area > carta2.area) {
            printf("Carta 1 vence!\n");
        } else if (carta2.area > carta1.area) {
            printf("Carta 2 vence!\n");
        } else {
            printf("Empate!\n");
        }
    } else if (strcmp(atributo, "pib") == 0) {
        printf("Comparando por PIB:\n");
        printf("Carta 1: %.2f\n", carta1.pib);
        printf("Carta 2: %.2f\n", carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Carta 1 vence!\n");
        } else if (carta2.pib > carta1.pib) {
            printf("Carta 2 vence!\n");
        } else {
            printf("Empate!\n");
        }
    } else if (strcmp(atributo, "densidadePopulacional") == 0) {
        printf("Comparando por Densidade Populacional:\n");
        printf("Carta 1: %.2f\n", carta1.densidadePopulacional);
        printf("Carta 2: %.2f\n", carta2.densidadePopulacional);
        if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
            printf("Carta 1 vence!\n");
        } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
            printf("Carta 2 vence!\n");
        } else {
            printf("Empate!\n");
        }
    } else if (strcmp(atributo, "pibPerCapita") == 0) {
        printf("Comparando por PIB per capita:\n");
        printf("Carta 1: %.2f\n", carta1.pibPerCapita);
        printf("Carta 2: %.2f\n", carta2.pibPerCapita);
        if (carta1.pibPerCapita > carta2.pibPerCapita) {
            printf("Carta 1 vence!\n");
        } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
            printf("Carta 2 vence!\n");
        } else {
            printf("Empate!\n");
        }
    } else {
        printf("Atributo inválido para comparação.\n");
    }
}

int main() {
    Carta carta1, carta2;

    // Cadastro das cartas
    cadastrarCarta(&carta1);
    printf("\n");
    cadastrarCarta(&carta2);

    // Escolha do atributo para comparação (definido no código)
    char atributoParaComparar[] = "pibPerCapita"; // Altere aqui para o atributo desejado

    // Comparação das cartas
    compararCartas(carta1, carta2, atributoParaComparar);

    return 0;
}

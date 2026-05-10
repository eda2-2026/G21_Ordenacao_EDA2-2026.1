#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
} evento;

int main() {
    evento agenda[100];
    int numEventos = 0;
    int opcao;

    while (1) {
        printf("Menu:\n");
        printf("1. Cadastrar evento\n");
        printf("2. Mostrar agenda\n");
        printf("3. Mostrar eventos de um mês específico\n");
        printf("4. Mostrar próximo evento\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                printf("Digite nome dia mes ano hora minuto: ");
                scanf("%s %d %d %d %d %d",
                    agenda[numEventos].nome,
                    &agenda[numEventos].dia,
                    &agenda[numEventos].mes,
                    &agenda[numEventos].ano,
                    &agenda[numEventos].hora,
                    &agenda[numEventos].minuto);
                    numEventos++;
                break;
            }
            case 2: {

                break;
            }
            case 3: {
                int mes;
                printf("Digite o mês: ");
                scanf("%d", &mes);
                break;
            }
            case 4: {

                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                printf("Opção inválida!\n");
            }
        }
    }

    return 0;
}
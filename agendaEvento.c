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

void maxMinAno(evento agenda[], int numEventos, int* maxIndex, int* minIndex) {
    if (numEventos <= 0) {
        *maxIndex = -1;
        *minIndex = -1;
        return;
    }

    *maxIndex = 0;
    *minIndex = 0;

    for (int i = 1; i < numEventos; i++) {
        if (
            agenda[i].ano > agenda[*maxIndex].ano ||
            (agenda[i].ano == agenda[*maxIndex].ano &&
             agenda[i].mes > agenda[*maxIndex].mes)
        ) {
            *maxIndex = i;
        }

        if (
            agenda[i].ano < agenda[*minIndex].ano ||
            (agenda[i].ano == agenda[*minIndex].ano &&
             agenda[i].mes < agenda[*minIndex].mes)
        ) {
            *minIndex = i;
        }
    }
}

int indiceBucket(evento agenda[], int maxIndex, int minIndex) {
    int indice =
        (agenda[maxIndex].ano - agenda[minIndex].ano) * 12 +
        (agenda[maxIndex].mes - agenda[minIndex].mes);

    return indice;
}

int indiceEvento(evento agenda[], int i, int minIndex) {
    int indice =
        (agenda[i].ano - agenda[minIndex].ano) * 12 +
        (agenda[i].mes - agenda[minIndex].mes);

    return indice;
}

int comparaEvento(evento a, evento b) {
    if (a.ano != b.ano) return a.ano - b.ano;
    if (a.mes != b.mes) return a.mes - b.mes;
    if (a.dia != b.dia) return a.dia - b.dia;
    if (a.hora != b.hora) return a.hora - b.hora;
    return a.minuto - b.minuto;
}

void insertionSort(evento bucket[], int qtd) {
    for (int i = 1; i < qtd; i++) {
        evento chave = bucket[i];
        int j = i - 1;

        while (j >= 0 && comparaEvento(bucket[j], chave) > 0) {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = chave;
    }
}

void bucketSort(evento agenda[], int numEventos, int minIndex, int maxIndex) {
    int totalBuckets = indiceBucket(agenda, maxIndex, minIndex) + 1;

    evento buckets[100][100];
    int qtdBuckets[100] = {0};

    for (int i = 0; i < numEventos; i++) {
        int indice = indiceEvento(agenda, i, minIndex);

        buckets[indice][qtdBuckets[indice]] = agenda[i];
        qtdBuckets[indice]++;
    }

    for (int i = 0; i < totalBuckets; i++) {
        insertionSort(buckets[i], qtdBuckets[i]);
    }

    int k = 0;

    for (int i = 0; i < totalBuckets; i++) {
        for (int j = 0; j < qtdBuckets[i]; j++) {
            agenda[k] = buckets[i][j];
            k++;
        }
    }
}

int main() {
    evento agenda[100];
    int numEventos = 0;
    int opcao;
    int maiorAnoIndex = 0;
    int menorAnoIndex = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Cadastrar evento\n");
        printf("2. Mostrar agenda\n");
        printf("3. Mostrar eventos de um mês específico\n");
        printf("4. Mostrar próximo evento\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1: {

                if (numEventos >= 100) {
                    printf("\nAgenda cheia!\n");
                    break;
                }

                printf("\nCadastro de evento\n");

                printf("Nome: ");
                scanf("%s", agenda[numEventos].nome);

                printf("Dia: ");
                scanf("%d", &agenda[numEventos].dia);

                printf("Mês: ");
                scanf("%d", &agenda[numEventos].mes);

                printf("Ano: ");
                scanf("%d", &agenda[numEventos].ano);

                printf("Hora: ");
                scanf("%d", &agenda[numEventos].hora);

                printf("Minuto: ");
                scanf("%d", &agenda[numEventos].minuto);

                numEventos++;

                maxMinAno(
                    agenda,
                    numEventos,
                    &maiorAnoIndex,
                    &menorAnoIndex
                );

                printf("\nEvento cadastrado com sucesso!\n");

                break;
            }

            case 2: {

                if (numEventos == 0) {
                    printf("\nAgenda vazia!\n");
                    break;
                }

                maxMinAno(
                    agenda,
                    numEventos,
                    &maiorAnoIndex,
                    &menorAnoIndex
                );

                bucketSort(
                    agenda,
                    numEventos,
                    menorAnoIndex,
                    maiorAnoIndex
                );

                printf("\nAgenda ordenada:\n");

                for (int i = 0; i < numEventos; i++) {

                    printf("%s - %02d/%02d/%d %02d:%02d\n",
                        agenda[i].nome,
                        agenda[i].dia,
                        agenda[i].mes,
                        agenda[i].ano,
                        agenda[i].hora,
                        agenda[i].minuto
                    );
                }

                break;
            }

            case 3: {

                int mes;
                int encontrou = 0;
                int ultimoAno = -1;

                if (numEventos == 0) {
                    printf("\nAgenda vazia!\n");
                    break;
                }

                maxMinAno(
                    agenda,
                    numEventos,
                    &maiorAnoIndex,
                    &menorAnoIndex
                );

                bucketSort(
                    agenda,
                    numEventos,
                    menorAnoIndex,
                    maiorAnoIndex
                );

                printf("\nDigite o mês: ");
                scanf("%d", &mes);

                printf("\nEventos do mês %02d:\n", mes);

                for (int i = 0; i < numEventos; i++) {

                    if (agenda[i].mes == mes) {

                        if (agenda[i].ano != ultimoAno) {

                            printf("\n===== %d =====\n",
                                agenda[i].ano);

                            ultimoAno = agenda[i].ano;
                        }

                        printf("%s - %02d/%02d/%d %02d:%02d\n",
                            agenda[i].nome,
                            agenda[i].dia,
                            agenda[i].mes,
                            agenda[i].ano,
                            agenda[i].hora,
                            agenda[i].minuto
                        );

                        encontrou = 1;
                    }
                }

                if (encontrou == 0) {
                    printf("\nNenhum evento encontrado para esse mês.\n");
                }

                break;
            }

            case 4: {

                int diaAtual;
                int mesAtual;
                int anoAtual;
                int horaAtual;
                int minutoAtual;
                int encontrou = 0;

                evento atual;

                if (numEventos == 0) {
                    printf("\nAgenda vazia!\n");
                    break;
                }

                maxMinAno(
                    agenda,
                    numEventos,
                    &maiorAnoIndex,
                    &menorAnoIndex
                );

                bucketSort(
                    agenda,
                    numEventos,
                    menorAnoIndex,
                    maiorAnoIndex
                );

                printf("\nDigite a data e hora atual:\n");

                printf("Dia: ");
                scanf("%d", &diaAtual);

                printf("Mês: ");
                scanf("%d", &mesAtual);

                printf("Ano: ");
                scanf("%d", &anoAtual);

                printf("Hora: ");
                scanf("%d", &horaAtual);

                printf("Minuto: ");
                scanf("%d", &minutoAtual);

                atual.dia = diaAtual;
                atual.mes = mesAtual;
                atual.ano = anoAtual;
                atual.hora = horaAtual;
                atual.minuto = minutoAtual;

                for (int i = 0; i < numEventos; i++) {

                    if (comparaEvento(agenda[i], atual) >= 0) {

                        printf("\nPróximo evento:\n");

                        printf("%s - %02d/%02d/%d %02d:%02d\n",
                            agenda[i].nome,
                            agenda[i].dia,
                            agenda[i].mes,
                            agenda[i].ano,
                            agenda[i].hora,
                            agenda[i].minuto
                        );

                        encontrou = 1;

                        break;
                    }
                }

                if (encontrou == 0) {
                    printf("\nNão há próximos eventos.\n");
                }

                break;
            }

            case 5: {

                exit(0);
            }

            default: {

                printf("\nOpção inválida!\n");
            }
        }
    }

    return 0;
}
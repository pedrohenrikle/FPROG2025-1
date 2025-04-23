#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aplicar_evento(int taxa) {
    int chance = rand() % 100 + 1;

    if (chance <= 5) {
        printf("Evento: Mutação mais contagiosa!\n");
        return taxa + taxa * 0.5;
    } else if (chance <= 10) {
        printf("Evento: Mídia gera alerta!\n");
        return taxa - taxa * 0.3;
    } else if (chance <= 20) {
        printf("Evento: Isolamento voluntário!\n");
        return taxa - taxa * 0.2;
    } else if (chance <= 35) {
        printf("Evento: Aglomeração!\n");
        return taxa + taxa * 0.25;
    }

    return taxa;
}

int main() {
    int opcao;

    srand(time(NULL));

    do {
        printf("===== Menu =====\n");
        printf("1 - Nova Simulação\n");
        printf("2 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int populacao, infectados_iniciais, dias;
            float taxa_contagio, percentual_vacinados, efetividade;

            printf("População total: ");
            scanf("%d", &populacao);
            printf("Infectados iniciais: ");
            scanf("%d", &infectados_iniciais);
            printf("Taxa de contágio (0-100%%): ");
            scanf("%f", &taxa_contagio);
            printf("Porcentagem da população vacinada (0-100%%): ");
            scanf("%f", &percentual_vacinados);
            printf("Efetividade da vacina (0-100%%): ");
            scanf("%f", &efetividade);
            printf("Número de dias da simulação: ");
            scanf("%d", &dias);

            int vacinados = populacao * (percentual_vacinados / 100);
            int nao_vacinados = populacao - vacinados;
            int vacinados_infectados = 0;
            int total_infectados = infectados_iniciais;

            printf("\n===== Simulação =====\n");
            printf("Dia 1: %d infectados\n", total_infectados);

            for (int dia = 2; dia <= dias; dia++) {
                int suscetiveis = (nao_vacinados - total_infectados);
                suscetiveis += (vacinados - vacinados_infectados) * (1.0 - (efetividade / 100));

                if (suscetiveis <= 0) {
                    printf("Toda a população suscetível foi infectada. Encerrando simulação.\n");
                    break;
                }

                int taxa_ajustada = aplicar_evento(taxa_contagio);
                int novos = (int)(total_infectados * (taxa_ajustada / 100.0));
                if (novos > suscetiveis) novos = suscetiveis;

                total_infectados += novos;

                int novos_vacinados = (int)((vacinados - vacinados_infectados) * (1.0 - (efetividade / 100.0)));
                if (novos_vacinados > novos) novos_vacinados = novos;
                vacinados_infectados += novos_vacinados;

                printf("Dia %d: %d infectados (+%d)\n", dia, total_infectados, novos);
            }

            int saudaveis = populacao - total_infectados;

            printf("\n===== Resultados =====\n");
            printf("Total infectados: %d\n", total_infectados);
            printf("População vacinada: %d\n", vacinados);
            printf("Vacinados infectados: %d\n", vacinados_infectados);
            printf("População saudável: %d\n\n", saudaveis);
        }

    } while (opcao != 2);

    printf("Programa encerrado.\n");
    return 0;
}

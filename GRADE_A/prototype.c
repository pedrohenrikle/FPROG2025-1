#include <stdio.h>

#define SIZE 10

int main()
{
    // Declarando as variaveis relacionadas ao controle do fluxo da aplicação
    int programOption = 0;

    while(programOption != 2) {
        printf("\n\n\n1 - Nova Simulacao\n");
        printf("2 - Sair do Programa\n");
        printf("--> ");
        scanf("%i", &programOption);

        if(programOption == 1) {
            // Declarando as variaveis relacionadas ao cálculo
            int population, initialInfected, simulationDays;
            float contaminationRate, populationVaccinatedRate, vaccineEffectiveness;

            printf("P.S.: Digite os valores sem a unidade de medida!\n");

            printf("Populacao: ");
            scanf("%i", &population);

            printf("\nNumero de pessoas inicialmente infectadas: ");
            scanf("%i", &initialInfected);

            printf("\nTaxa de contagio (0 a 100%%): ");
            scanf("%f", &contaminationRate);

            printf("\nPorcentagem da populacao vacinada (0 a 100%%): ");
            scanf("%f", &populationVaccinatedRate);

            printf("\nEfetividade da Vacina (0 a 100%%): ");
            scanf("%f", &vaccineEffectiveness);

            printf("\nNumero de dias da simulação : ");
            scanf("%i", &simulationDays);

            int infected = initialInfected;
            int notVaccinated = population * (1 - populationVaccinatedRate / 100);
            int vaccinated = population - notVaccinated;
            int healthyVaccinated = vaccinated * (1 - vaccineEffectiveness / 100);
            int notHealthyVaccinated = vaccinated - healthyVaccinated;
            int healthyNotVaccinated = notVaccinated;
            
            int vaccinatedInfected = 0;

            srand(time(NULL));

            for (int day = 1; day <= simulationDays; day++) {
                /// eventos aleatorios
                int randomEvent = rand() % 100 + 1;
                float currentContaminationRate = contaminationRate;
 
                if (randomEvent <= 15) {
                    // Evento > Aglomeração de pessoas
                    currentContaminationRate += 25;
                    printf("Dia %i: %i infectados (evento: Aglomeracao nas Ruas -> Taxa de contagio sobe para: %.2f%)\n", day, infected, currentContaminationRate);
                } else if ( randomEvent <= 25) {
                    // Evento > Isolamento voluntário
                    currentContaminationRate -= 20;
                    printf("Dia %i: %i infectados (evento: Isolamento Voluntario -> Taxa de contagio desce para: %.2f%)\n", day, infected, currentContaminationRate);
                } else if (randomEvent <= 30) {
                    // Evento > Midia gera um Alerta
                    currentContaminationRate -= 30;
                    printf("Dia %i: %i infectados (evento: Midia gera um Alerta -> Taxa de contagio desce para: %.2f%)\n", day, infected, currentContaminationRate);
                } else if (randomEvent <= 35) {
                    // Evento > Mutação mais Perigosa
                    currentContaminationRate -= 30;
                    printf("Dia %i: %i infectados (evento: Mutacao mais Perigosa -> Taxa de contagio sobe para: %.2f%)\n", day, infected, currentContaminationRate);
                }

                int suceptible = healthyNotVaccinated + healthyVaccinated * (1 - vaccineEffectiveness / 100);

                int newInfected = infected * (1 - currentContaminationRate / 100);
                newInfected = (newInfected < suceptible) ? newInfected : suceptible;

                infected += newInfected;

                healthyNotVaccinated -= newInfected;
                int infectedVaccinated = (newInfected > healthyNotVaccinated) ? (newInfected - healthyNotVaccinated) : 0;
                healthyVaccinated -= infectedVaccinated;

                vaccinatedInfected +- infectedVaccinated;

                printf("Dia %i: %i infectados, %i novos infectados\n", day, infected, newInfected);

                if (suceptible == 0) {
                    printf("Todos os suscetiveis foram infectados!\n");
                    break;
                }
            }

            printf("\nTotal infectados: %i\n", infected);
            printf("População vacinada: %i\n", vaccinated + vaccinatedInfected);
            printf("Vacinados infectados: %i\n", vaccinatedInfected);
            printf("População saudavel: %i\n", population - infected);

        } else if (programOption == 2) {
            break;
        } else {
            printf("Oops! Parece que nao temos esse comando...");
            break;
        }
        

    }
    
    printf("Tchau! Obrigado pelo acesso...");
    return 0;
}

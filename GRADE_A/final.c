#include <stdio.h>
#include <stdlib.h>

// Estrutura pra definir o que um evento possui
typedef struct {
    float novaTaxa;
    const char *descricao;
} Evento;

// Função que gerencia toda a parte de eventos aleatorios
Evento eventos(float taxa) {
    Evento res;
    int chance = rand() % 100;

    if (chance < 5) {
        res.novaTaxa = taxa + taxa * 0.5;  
        res.descricao = "- [ Evento: Mutação mais contagiosa ]";
    } else if (chance < 10) {
        float novaTaxa = taxa - taxa * 0.3; 
        res.novaTaxa = (novaTaxa < 0) ? 0 : novaTaxa;
        res.descricao = "- [ Evento: Mídia gera alerta ]";
    } else if (chance < 20) {
        float novaTaxa = taxa - taxa * 0.2; 
        res.novaTaxa = (novaTaxa < 0) ? 0 : novaTaxa;
        res.descricao = "- [ Evento: Isolamento voluntário ]";
    } else if (chance < 35) {
        res.novaTaxa = taxa + taxa * 0.25;
        res.descricao = "- [ Evento: Aglomeração ]";
    } else {
        res.novaTaxa = taxa;
        res.descricao = "";
    }
    
    return res;
}

int main(int argc, char const *argv[])
{
    // Aqui apenas defino duas constantes, pra que caso no futuro queira trocar os valores
    // de entrar ou sair do programa, só alterar aqui nas constantes dai...
    char CONST_PROGRAMA = '1';
    char CONST_SAIR = '2';

    char menu;

    while (1) {
        // "Limpa" a variavel, botando um valor nulo no lugar
        menu = '\0';

        printf("\n\n1 - Nova Simulação\n");
        printf("2 - Sair do Programa\n");
        printf("--> ");
        scanf(" %c", &menu);

        // Limpo o buffer do char 
        //(faz com que se digitar "carro" por exemplo, ele não repita o código para cada letra da palavra)
        while ((getchar()) != '\n');

        switch (menu)
        {
        case '1':
            int populacao_total, init_infectadas, dias_simulacao;
            float taxa_de_contagio, populacao_vacinada, eficacia_vacina;

            printf("\n--- Início da Simulação ---\n");

            // Entrada de dados com validação
            printf("População total (int > 0): ");
            if (scanf("%d", &populacao_total) != 1 || populacao_total <= 0) {
                printf("Erro: a população deve ser um inteiro maior que zero.\n");
                return -2;
            }
            
            printf("Número de pessoas inicialmente infectadas (int > 0): ");
            if (scanf("%d", &init_infectadas) != 1 || init_infectadas <= 0) {
                printf("Erro: o número inicial de infectados deve ser um inteiro maior que zero.\n");
                return -2;
            }
            
            printf("Taxa de contágio (0 a 100%%): ");
            if (scanf("%f", &taxa_de_contagio) != 1 || taxa_de_contagio < 0 || taxa_de_contagio > 100) {
                printf("Erro: a taxa de contágio deve estar entre 0 e 100.\n");
                return -2;
            }
            
            printf("Porcentagem da população vacinada (0 a 100%%): ");
            if (scanf("%f", &populacao_vacinada) != 1 || populacao_vacinada < 0 || populacao_vacinada > 100) {
                printf("Erro: a porcentagem vacinada deve estar entre 0 e 100.\n");
                return -2;
            }
            
            printf("Efetividade da vacina (0 a 100%%): ");
            if (scanf("%f", &eficacia_vacina) != 1 || eficacia_vacina < 0 || eficacia_vacina > 100) {
                printf("Erro: a eficácia da vacina deve estar entre 0 e 100.\n");
                return -2;
            }
            
            printf("Número de dias da simulação: ");
            if (scanf("%d", &dias_simulacao) != 1 || dias_simulacao <= 0) {
                printf("Erro: o número de dias deve ser maior que zero.\n");
                return -2;
            }

            printf("\n\nDia 1 - Numero de infectados: %d", init_infectadas);

            // TODO: a partir daqui tem que botar a logica de calcular o dia 2 até o dia_simulacao
            
            for(int dia = 2; dia <= dias_simulacao; dia++) {
                // Antes de calcular a população do dia, verifica se ocorre algum evento que modifica a taxa
                Evento evt = eventos(taxa_de_contagio);
                taxa_de_contagio = evt.novaTaxa;

                // Cálculo das pessoas suscetíveis
                int nao_vacinadas = (int)(populacao_total * (100.0 - populacao_vacinada) / 100.0);
                int vacinadas = (int)(populacao_total * populacao_vacinada / 100.0);
                int vacinadas_susceptiveis = (int)(vacinadas * (100.0 - eficacia_vacina) / 100.0);
                int suscetiveis = nao_vacinadas + vacinadas_susceptiveis;

                int novas_infectadas = (int)(init_infectadas * (taxa_de_contagio / 100.0));

                // Limita as novas infecções ao número de pessoas suscetíveis
                if (novas_infectadas > suscetiveis) {
                    novas_infectadas = suscetiveis;
                }

                init_infectadas += novas_infectadas;

            
                // Garante que o número de infectados nunca ultrapasse a população total
                if (init_infectadas >= populacao_total) {
                    init_infectadas = populacao_total;
                    printf("\n\nDia %d - Toda a população foi infectada...", dia);
                    break;
                }
            
                printf("\n\nDia %d - Número de infectados: %d %s", dia, init_infectadas, evt.descricao);
            }

            // Após a simulação, calcula e exibe os resultados finais:
            int total_infectados = init_infectadas;
            int total_vacinados = (int)(populacao_total * populacao_vacinada / 100.0);
            int nao_vacinadas = populacao_total - total_vacinados;
            int vacinados_infectados = (total_infectados > nao_vacinadas) ? total_infectados - nao_vacinadas : 0;
            int populacao_saudavel = populacao_total - total_infectados;

            printf("\n\nTotal infectados: %d\n", total_infectados);
            printf("População vacinada: %d\n", total_vacinados);
            printf("Vacinados infectados: %d\n", vacinados_infectados);
            printf("População saudável: %d\n", populacao_saudavel);

            break;
        
        case '2':
            printf("\nObrigado por participar do programa! Até mais...\n");
            return -1;
        
        default:
            printf("Oops! Esse comando parece inválido...");
            break;
        }

    }

    return 0;
}


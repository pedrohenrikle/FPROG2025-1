#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Inicializao os animais e uma vaiavel temp que será usada para os inputs de dados
    int tatu = 0;
    int gato = 0;
    int tamanua = 0;
    int temp = 0;

    // Itero sobre cada dia, usando uma variavel temporaria como "input" de cada um
    for (int i = 1; i < 7 + 1; i++) {
        temp = 0;
        printf("\n\n=-=-=-- Inicio do dia %d --=-=-=", i);
        printf("\nQuantos Tatus-Canastra forma vistos: ");
        scanf("%d", &temp);
        tatu += temp;

        printf("\nQuantos Gatos-Maracuja forma vistos: ");
        scanf("%d", &temp);
        gato += temp;

        printf("\nQuantos Tamanduas-Bandeira forma vistos: ");
        scanf("%d", &temp);
        tamanua += temp;
    }
        // Aqui faço um resumo dos totais e médias da semana (7 dias) dos animais
        printf("\n\n ------- Resumo Total -------");
        printf("\nO total de Tatus-Canastra foi: %d", tatu);
        printf("\nO total de Gatos-Maracuja foi: %d", gato);
        printf("\nO total de Tamandua-Bandeira foi: %d", tamanua);

        // Acabou que usei a maneira 'explicita' de conversão para float o.o
        printf("\n ------- Resumo das Medias -------");
        printf("\nA media de Tatus-Canastra foi: %.2f", (float)tatu/7);
        printf("\nA media de Gatos-Maracuja foi: %.2f", (float)gato/7);
        printf("\nA media de Tamandua-Bandeira foi: %.2f\n", (float)tamanua/7);

        // Comparo os valores e apresento o maior e o menor animal
        if (tatu >= gato) {
            if (tatu >= tamanua)
                printf("\nEm geral, a especie mais avistada foi: Tatus-Canastra");
            else
                printf("\nEm geral, a especie mais avistada foi: Tamandua-Bandeira");
        } else {
            if (gato >= tamanua)
                printf("\nEm geral, a especie mais avistada foi: Gatos-Maracuja");
            else
            printf("\nEm geral, a especie mais avistada foi: Tamandua-Bandeira");
        }

        // Aqui temos o menor valor, como citado acima
        if (tatu <= gato) {
            if (tatu <= tamanua)
                printf("\nEm geral, a especie menos avistada foi: Tatus-Canastra");
            else
                printf("\nEm geral, a especie menos avistada foi: Tamandua-Bandeira");
        } else {
            if (gato <= tamanua)
                printf("\nEm geral, a especie menos avistada foi: Gatos-Maracuja");
            else
            printf("\nEm geral, a especie menos avistada foi: Tamandua-Bandeira");
        }
    printf("\n\n");
        
    return 0;
}


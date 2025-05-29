#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Uma função simples pra simplificar as contas
int aleatorio(int min, int max) {
    srand(time(NULL));

    int n = min + rand() % (max - min + 1);
    
    printf("\nO valor sorteado entre %d e %d foi %d", min, max, n);
}

int main(int argc, char const *argv[])
{   
    // Defino a 'seed' do meu rand como o tempo atual
    srand(time(NULL));

    // Uso a função criada pra calcular um int dentre de um range
    aleatorio(1,100);
    aleatorio(-100, -1);
    aleatorio(-50, 50);

    // Faço a divisão em int, depois divido por 10 e passo pra float
    float n = -10 + rand() % (10 + 10 + 1);
    printf("\nO valor sorteado entre -1.0 e 1.0 foi %.1f", n/10);

    // Fico fazendo a divisão até achar um valor divisivel por 5
    int calc = 1;
    while (calc % 5 != 0) {
        calc = 50 + rand() % (150 - 50 + 1);
    }

    printf("\nO valor sorteado entre 50 e 150 e divisivel por 5 foi %d", calc);

    return 0;
}

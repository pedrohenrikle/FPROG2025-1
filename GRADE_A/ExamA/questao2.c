// se negativo, faz a exponenciacao e faz 1/ans, usa o double ou float, tanto faz na real

#include <stdio.h>

// Essa função vai ser usada para calcular as potencias, literalmente um novo 'pow()' do math.h
double newpow(int base, int expoente) {
    double retorno = base;

    // Expoente igual a zero
    if (expoente == 0) {
        return (double)1;
    
    // Expoente menor que zero
    // inverto o sinal do expoente, faço a conta normal e no final faço 
    // 1 sobre o valor encontrado (1/Ans)
    } else if (expoente < 0) {
        expoente = expoente * -1;
        for (int i = 1; i < expoente; i++) {
            retorno = retorno * expoente;
        }

        return 1/retorno;

    // Expoente maior que zero
    } else if (expoente > 0) {
        for (int i = 1; i < expoente; i++) {
            retorno = retorno * expoente;
        }

        return retorno;

    // Expoente nem é numero
    } else {
        printf("\nOops, parece que houve algum erro!");
    }
}

int main(int argc, char const *argv[])
{
    // Simplesmente declaro base e expoente, pergunto pro usuario e jogo pra minha função 'newpow'
    int base, expoente;

    printf("\nDigite um valor de base: ");
    scanf("%d", &base);    

    printf("\nDigite um valor de expoente: ");
    scanf("%d", &expoente);    

    // Pego o retorno do 'newpow', ele ja vem como double dai eu só printo ele com duas casas
    double resposta = newpow(base, expoente);
    printf ("\nO valor da sua potencia equivale a %.2lf", resposta);

    return 0;
}

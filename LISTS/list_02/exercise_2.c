#include <stdio.h>

int main(int argc, char const *argv[])
{
    float wealth;
    printf_s("Quantos reais gostaria de converter para dolares americanos: R$");
    scanf("%f", &wealth);
    printf("\nIsso é equivalente a $%.2f dolares (1 dolar = 5.8 reais)", wealth*5.8);
    return 0;
}

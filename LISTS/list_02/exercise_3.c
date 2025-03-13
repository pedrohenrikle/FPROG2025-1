#include <stdio.h>

int main(int argc, char const *argv[]) 
{
    float weigth;
    printf("Quantas gramas tem anotado na comanda? ");
    scanf("%f", &weigth);
    printf("O valor final fica R$%.2f", (weigth/1000)*40);
    return 0;
}
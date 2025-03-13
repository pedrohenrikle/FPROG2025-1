#include <stdio.h>

int main(int argc, char const *argv[])
{
    int time;
    printf("Digite quantos minutos quer converter: ");
    scanf("%d", &time);
    printf("\nTempo em segundos: %ds", time*60); // time in seconds
    return 0;
}

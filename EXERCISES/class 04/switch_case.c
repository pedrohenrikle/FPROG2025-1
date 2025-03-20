#include <stdio.h>

int main(int argc, char const *argv[])
{
    float num1, num2;
    char userOperation;

    printf("Chose a number: ");
    scanf("%f", &num1);
    printf("Chose another number: ");
    scanf("%f", &num2);

    float temp;

    printf("At any time, u can exit just hiting CTRL+C\n");
    while (1)
    {
        printf("\nSo, what type of operation u want to do with them? ");
        printf("\n(u can chose: +, -, * or /)");
        printf("\nAns: ");
        scanf(" %c", &userOperation);

        switch (userOperation)
        {
        case '+':     
            temp = num1+num2;
            printf("The sum of both numbers is: %.2f\n", temp);
            break;
        case '-':
            temp = num1-num2;
            printf("The difference between both numbers is: %.2f\n", temp);
            break;
        case '*':
            temp = num1*num2;
            printf("The first number times the second is: %.2f\n", temp);
            break;
        case '/':
            if (num2 == 0) { printf("Division by zero is impossible...\n"); break;}
            
            temp = num1/num2;
            printf("The first number divided by the second is: %.2f\n", temp);
            break;
        default:
            printf("Sorry, seems u didn't selected a valid option!\n");
            break;
        }

    }

    return 0;
}

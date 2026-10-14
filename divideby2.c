#include <stdio.h>

int main()
{
    char num[100];
    int state = 0;

    printf("Enter a decimal number: ");
    scanf("%s", num);

    for(int i = 0; num[i] != '\0'; i++)
    {
        if(num[i] == '0' || num[i] == '2' ||
           num[i] == '4' || num[i] == '6' ||
           num[i] == '8')
        {
            state = 1;
        }
        else
        {
            state = 0;
        }
    }

    if(state == 1)
        printf("Number is divisible by 2\n");
    else
        printf("Number is not divisible by 2\n");

    return 0;
}
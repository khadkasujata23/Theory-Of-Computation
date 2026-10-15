#include <stdio.h>

int main()
{
    char str[100];
    int state = 0;

    printf("Enter a binary number: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(state == 0)
        {
            if(str[i] == '0')
                state = 0;
            else
                state = 1;
        }
        else if(state == 1)
        {
            if(str[i] == '0')
                state = 2;
            else
                state = 0;
        }
        else if(state == 2)
        {
            if(str[i] == '0')
                state = 1;
            else
                state = 2;
        }
    }

    if(state == 0)
        printf("String Accepted: Divisible by 3\n");
    else
        printf("String Rejected: Not divisible by 3\n");

    return 0;
}
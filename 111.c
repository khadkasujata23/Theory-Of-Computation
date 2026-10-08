#include <stdio.h>

int main()
{
    char str[100];
    int state = 0;

    printf("Enter a binary string: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(state == 0)
        {
            if(str[i] == '1')
                state = 1;
            else
                state = 0;
        }
        else if(state == 1)
        {
            if(str[i] == '1')
                state = 2;
            else
                state = 0;
        }
        else if(state == 2)
        {
            if(str[i] == '1')
                state = 3;
            else
                state = 0;
        }
        else if(state == 3)
        {
            state = 3;
        }
    }

    if(state == 3)
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
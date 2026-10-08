#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int state = 0;

    printf("Enter a binary string: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        switch(state)
        {
            case 0:
                if(str[i] == '0')
                    state = 0;
                else
                    state = 1;
                break;

            case 1:
                if(str[i] == '0')
                    state = 2;
                else
                    state = 1;
                break;

            case 2:
                if(str[i] == '0')
                    state = 0;
                else
                    state = 3;
                break;

            case 3:
                if(str[i] == '0')
                    state = 2;
                else
                    state = 1;
                break;
        }
    }

    if(state == 3)
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], ans[100];
    int i, n, state = 0;

    printf("Enter binary number: ");
    scanf("%s", str);

    n = strlen(str);

    for(i = n - 1; i >= 0; i--)
    {
        if(state == 0)
        {
            if(str[i] == '0')
            {
                ans[i] = '0';
            }
            else
            {
                ans[i] = '1';
                state = 1;
            }
        }
        else
        {
            if(str[i] == '0')
                ans[i] = '1';
            else
                ans[i] = '0';
        }
    }

    ans[n] = '\0';

    printf("2's Complement = %s\n", ans);

    return 0;
}
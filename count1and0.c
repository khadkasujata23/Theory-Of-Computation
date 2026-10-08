#include <stdio.h>

int main()
{
    char str[100];
    int zero = 0, one = 0;

    printf("Enter a binary string: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '0')
            zero++;
        else if(str[i] == '1')
            one++;
    }

    printf("Number of 0's = %d\n", zero);
    printf("Number of 1's = %d\n", one);

    return 0;
}
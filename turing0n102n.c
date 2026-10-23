//accepting01
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0, i;

    printf("Enter a binary string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        if (state == 0) {
            if (str[i] == '0') state = 1;
            else state = 0;
        }
        else if (state == 1) {
            if (str[i] == '0') state = 1;
            else state = 2;
        }
        else if (state == 2) {
            if (str[i] == '0') state = 1;
            else state = 0;
        }
    }

    if (state == 2)
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
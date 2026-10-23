#include <stdio.h>
#include <string.h>

int main() {
    char tape[100];
    int left = 0, right, flag = 1;

    printf("Enter a binary string: ");
    scanf("%s", tape);

    right = strlen(tape) - 1;

    while (left < right) {
        if (tape[left] != tape[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    if (flag)
        printf("String Accepted - Palindrome\n");
    else
        printf("String Rejected - Not a Palindrome\n");

    return 0;
}
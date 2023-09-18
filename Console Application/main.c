#include <stdio.h>

int main() {
    char number1[1], number2[1], number3[1];

    scanf("%c", &number1);
    scanf(" %c", &number2);
    scanf("  %c", &number3); /* The leading whitespace ensures it's the
                          previous newline is ignored */
    printf("number1: %c, number2: %c, number3: %c\n", number1, number2, number3);



    return 0;
}
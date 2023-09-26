#include <stdio.h>

int main() {

    int days, start, i,j;


    printf("number of days in month: ");
    scanf("%d",&days);
    printf("starting day of week (1=Monday, 7=Sunday): ");
    scanf("%d",&start);
    printf("\n");
    for (j = 1; j < start ;j++) {
        printf("   ");

    }

    for (i = 1; i <= days; i++, start++) {

        printf("%2d ", i);
        if (start == 7) {
            printf("\n");
            start = start - 7;
        }
    }
    printf("\n");

    return 0;
}





#include <stdio.h>



int main() {

    int position = 1, leader = 1, eingabe = 1, startnummer = 1;

    while (eingabe != 0 ) {

        printf(": ");
        scanf("%d", &eingabe);
        if (eingabe == 0)
            break;
        startnummer++;
        if (eingabe <= position) {
            position++;
            printf("position #1: %d\n",position);
        }


        if (eingabe == 1) {
            leader = startnummer;
            printf("new leader: #%d\n", leader);
        }





    }
    printf("final position #1: %d\n",position);
    printf("winner: #%d\n",leader);

    return 0;
}

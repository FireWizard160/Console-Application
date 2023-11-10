#include <stdio.h>
#include <stdlib.h>

char scanDirection() {

    char direction;
    printf("walk to:\n");
    scanf(" %c", &direction);

    return direction;
}

void printString(char string[10][10]) {
    int x = 0;

    for (int y = 0, cnt = 0; cnt < 10; ++y) {
        printf("%c", string[x][y]);

        if (y == 9) {
            printf("\n");
            cnt++;
            x++;
            y = -1;
        }


    }


}


int main() {

    char string[10][10];
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                         'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int x = 0;
    for (int y = 0, cnt = 0; cnt < 10; ++y) {
        string[x][y] = '.';

        if (y == 9) {
            cnt++;
            x++;
            y = -1;
        }


    }


    int currentLetter = 1;
    int currentX = 0;
    int currentY = 0;

    string[currentX][currentY] = 'A';


    printString(string);
    while (1) {
        if (currentLetter == 26)
            currentLetter = 0;

        switch (scanDirection()) {


            case 'w': {
                if (currentY == 0 || string[currentX][currentY - 1] != '.') {
                    printf("not possible\n");
                    break;

                }

                string[currentX][--currentY] = alphabet[currentLetter++];
                printString(string);

            }
                break;
            case 's': {
                if (currentX == 9 || string[currentX + 1][currentY] != '.') {
                    printf("not possible\n");
                    break;

                }

                string[++currentX][currentY] = alphabet[currentLetter++];
                printString(string);

            }
                break;
            case 'e': {
                if (currentY == 9 || string[currentX][currentY + 1] != '.') {
                    printf("not possible\n");
                    break;

                }

                string[currentX][++currentY] = alphabet[currentLetter++];
                printString(string);

            }
                break;
            case 'n': {
                if (currentX == 0 || string[currentX - 1][currentY] != '.') {
                    printf("not possible\n");
                    break;

                }

                string[--currentX][currentY] = alphabet[currentLetter++];
                printString(string);


            }
                break;
            case 'x': {
                return 0;
            }


        }
    }
}
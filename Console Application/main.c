#include <stdio.h>
#include <string.h>

#define MAX 80
#define VALID_CHARACTERS "ABCDEFGHIJKLMOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz. \n"

void CntWords(int *array, int LetterNumber) {

    array[LetterNumber] += 1;
}


int CntLetter(char *string, int size, int Startwert) {
    int cnt = 0;




    for (int i = Startwert + 1; i <= size; i++) {

        if (string[i] == ' ' || string[i] == '.')
            break;


        cnt++;
    }
    return cnt;
}

int check(char *string, int cnt) {



    if (cnt > 80) {
        return 1;
    }
    if (cnt == 80) {
        if (string[80] != '.')
            return 1;
    }

    for (int i = 0; i <= MAX; i++){
        if (strchr(VALID_CHARACTERS, string[i]) == NULL)
            return 1;

    }


    return 0;
}


int main() {
    char string[MAX] = {0};

    int cnt = 0;
    char letter;

    printf(": ");
    for (int i = 0; i <= MAX; ++i) {

        scanf("%c", &letter);
        string[i] = letter;

        if (string[i] == '.') {
            break;

        }

        cnt++;

        if (check(string, cnt) == 1) {
            printf("NOT VALID");
            return 0;
        }
    }


    int array[MAX] = {0};



    CntWords(array, CntLetter(string, cnt, -1));
    for (int i = 0; i <= cnt; i++) {
        if (string[i] == ' ' || string[i] == '.') {
            CntWords(array, CntLetter(string, cnt, i));
        }
    }

    for (int i = 1; i <= cnt; i++)
        if (array[i] != 0)
            printf("Length %d: %d\n", i, array[i]);

    return 0;

}

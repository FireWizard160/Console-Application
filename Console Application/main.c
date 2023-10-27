#include <stdio.h>
#include <stdlib.h>

#define MAX 80


void cntwords(int *array, int letternumber) {

    array[letternumber - 1] += 1;
}


int cntletter(char *string, int size, int startwert) {
    int cnt = 0;

    for (int i = startwert; i <= size; i++) {
        cnt++;
        if (string[i] == ' ' || string[i] == '.')
            break;

    }
    return cnt;
}


int main() {
    char string[MAX];

    int cnt = 0;
    char letter;
    for (int i = 0; i <= MAX; ++i) {

        scanf("%c", &letter);
        string[i] = letter;

        if (string[i] == '.') {
            break;

        }


        cnt++;
    }
    int array[cnt];

    for (int i = 0; i <= cnt; i++) {
        if (string[i] == ' ' || string[i] == '.') {
            cntwords(array, cntletter(string, cnt, i));
        }
    }

    for (int i = 0; i <= cnt; i++)
        if (array[i - 1] != 0)
            printf("Length %d: %d\n", i, string[i]);

    return 0;

}

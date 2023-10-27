#include <stdio.h>
#include <stdlib.h>
#define MAX 80




char ueberpruefung (char *string, int size) {

}

void cntwords(int size, int letternumber){
    int array[size];
    array[letternumber] += 1;
}


void cntletter(char *string, int size, int startwert){
    int cnt;
    int i = startwert;
    for (i; i <= size; i++)
        cnt++;
        if (string[i] == ' ' || string [i] == '.' )
            cntwords(size, cnt);



}


int main() {
    char string[MAX];

    int cnt;
    char letter;
    for (int n = 0; n <= MAX; ++n) {

        scanf("%c", &letter);
        string[n] = letter;

        if (string[n] == '.')

            break;


        cnt++;
    }
    for (int i; i <= cnt; i++) {
        if (string[i] == ' ' || string[i] == '.')
            cntletter(string, cnt, i);
    }

    for (int i; i <= cnt; i++)
        if (string [i] != 0)
            printf("Length %d: %d", i, string[i]);
}

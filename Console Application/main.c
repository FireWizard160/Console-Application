#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char **scanWords() {
    char **words = (char **) calloc(1, sizeof(char *)), **tmp;
    int i = 0;
    while (1) {
        char buf[81];
        scanf("%80s", buf);
        if (buf[0] == '-') break;
        if (NULL == (tmp = (char **) realloc(words, sizeof(char *) * (i + 2)))) {
            printf("out of memory");
            break;
        }
        words = tmp;
        words[i] = (char *) calloc(strlen(buf) + 1, sizeof(char));
        strcpy(words[i], buf);
        i++;
    }
    words[i] = (char *) calloc(1, sizeof(char));
    return words;
}


int countWord(char *text, char *word) {

    int cntWords = 0;

    for (int i = 0, j = 0; i < strlen(text); ++i) {
        if (text[i] == word[j]) {
            j++;
        } else {
            j = 0;
        }
        if (j == strlen(word)) {
            cntWords++;
            j = 0;
        }

    }

    return cntWords;
}

void freeAll(char **strngs) {
    int i = 0;
    for (; strlen(strngs[i]); ++i) {

        free(strngs[i]);

    }
    free(strngs[i]);
    free(strngs);

}

int main() {
    char string[1001];
    string[1000] = '\0';

    printf("text: words:");
    for (int i = 0; i < 1000;) {
        scanf("%c", &string[i]);

        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }

        if (isalpha(string[i]) || isspace(string[i])) {
            i++;
        }


    }
    char **words = scanWords();

    for (int i = 0; strlen(words[i]); ++i) {
        printf("\n%s: %d", words[i], countWord(string, words[i]));
    }
    freeAll(words);


    return 0;
}

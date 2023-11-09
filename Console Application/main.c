#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** scanWords() {
    char** words= ( char**)calloc(1, sizeof(char*)), **tmp;
    int i=0;
    while(1) {
        char buf[81];
        scanf("%80s", buf);
        if(buf[0]=='-') break;
        if(NULL==(tmp = ( char**)realloc(words, sizeof(char*)*(i+2)))) {
            printf("out of memory");
            break;
        }
        words=tmp;
        words[i] = ( char*)calloc(strlen(buf)+1, sizeof(char));
        strcpy(words[i], buf);
        i++;
    }
    words[i]=( char*)calloc(1,sizeof(char));
    return words;
}


int countWord(char *text, char* word){
int cnt = 0;
    while (*text != 0){
            cnt++;
        
    }    
return cnt;
}

void freeAll(char** strngs){
    for (int i = 0; strngs[i][0] != '\0' ; ++i) {
        free(strngs[i]);
    }

}

int main()
{
    char string[1000];

    for (int i = 0; i < 1000; ++i) {
        scanf("%c", &string[i]);
    }


    countWord(string,*scanWords());
    return 0;
}

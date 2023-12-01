#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){

    char string[41];
    string[40] = '\0';

    char temp;
    int count = 0;
    printf(": ");

    for (int i = 0; i < 40;) {
        scanf("%c", &temp);


        string[i] = tolower(temp);



        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }

        if (isalpha(string[i])) {
            i++;
            count++;
        }


    }



    for (int i = 0, j = count - 1; i < count - 1; ++i, --j) {
        if (string[j] == '\0'){
            j--;
            j--;
            continue;
        }






        if (string[i] != string[j]){
            printf("false");
            return 0;

        }


    }
    printf("true");
}

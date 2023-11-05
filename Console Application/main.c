#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mirrorString(char *string)
{


    int stringLength = strlen(string);

    char* mirroredString = (char*)malloc(sizeof(char) * stringLength + 1);
    strcpy(mirroredString, string);
    char temp [stringLength];

    int n = 0;
    for (int i = stringLength - 1; i >= 0 ; --i, n++) {

        temp [n] = string[i];

    }
    n = 0;

    for (int i = stringLength/2; i < stringLength ; ++i, n++) {
        mirroredString [i] = temp [i];

    }


    return mirroredString;
}
int main()
{
    char string[30];
    scanf("%s", string);

    char* stringMirrored = mirrorString(string);

    printf("%s", stringMirrored);

    free (stringMirrored);
    return 0;
}
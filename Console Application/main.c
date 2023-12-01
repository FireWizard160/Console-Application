#include <stdio.h>
#include <stdlib.h>


int main() {
    int arraySize1 = 0;
    int arraySize2 = 0;
    printf(": ");

    scanf("%d", &arraySize1);
    scanf("%d", &arraySize2);



    int array1[arraySize1];
    int array2[arraySize2];

    for (int i = 0, temp = 0; i < arraySize1; ++i) {
        scanf("%d", &temp);
        array1[i] = temp;

    }


    for (int i = 0, temp = 0; i < arraySize2; ++i) {
        scanf("%d", &temp);
        array2[i] = temp;

    }

    int diff = 0;
    int smallestDiff = 0;
    int smallestDiffArray1 = 0;
    int smallestDiffArray2 = 0;

    smallestDiff = array1[0] - array2 [0];

    if (smallestDiff < 0) {
        smallestDiff *= -1;
    }

    for (int i = 0; i < arraySize1; ++i) {
        for (int j = 0; j < arraySize2; ++j) {
            diff = array1[i] - array2[j];

            if (diff < 0) {
                diff *= -1;
            }

            if (diff < smallestDiff) {
                smallestDiff = diff;
                smallestDiffArray1 = i;
                smallestDiffArray2 = j;
            }


        }

    }


    printf("%d (%d, %d)", smallestDiff, array1[smallestDiffArray1], array2[smallestDiffArray2]);

    return 0;
}

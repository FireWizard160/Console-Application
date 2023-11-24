#include <stdio.h>
#include <stdlib.h>


int main()
{
    int arraySize1 = 0;
    int arraySize2 = 0;
    printf(":");

    scanf("%d", &arraySize1);
    scanf("%d", &arraySize2);

    printf(":");

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

    int numberOfDiffs = 0;
    int smallestDiff = 0;
    int smallestDiffArray1 = 0;
    int smallestDiffArray2 = 0;

    numberOfDiffs = (arraySize1 * arraySize2) * 2;

    int arrayDiffs[numberOfDiffs];
    int i = 0;
    for (int j = 0,n = 0; i < numberOfDiffs; ++i) {

        if (n == arraySize1 - 1)
            if(arraySize1 != 1){
                break;
            }



        arrayDiffs[i] = array1[n] - array2[j];




        if (i == 0){
            if (arrayDiffs[0] < 0){
                j++;
                if ( j == arraySize2){
                    n++;
                    j = 0;
                }
                continue;
            }
            smallestDiff = arrayDiffs [i];
            smallestDiffArray1 = array1[n];
            smallestDiffArray2 = array2[j];
            j++;
            if ( j == arraySize2){
                n++;
                j = 0;
            }
            continue;
        }


        if (arrayDiffs[i] > - 1 && arrayDiffs [i - 1] < 0) {
            smallestDiff = arrayDiffs [i];
            smallestDiffArray1 = array1[n];
            smallestDiffArray2 = array2[j];

        } else if (arrayDiffs[i] > - 1 && arrayDiffs[i] < smallestDiff){
            smallestDiff = arrayDiffs [i];
            smallestDiffArray1 = array1[n];
            smallestDiffArray2 = array2[j];
        }
        j++;
        if ( j == arraySize2){
            n++;
            j = 0;
        }

    }

    for (int j = 0,n = 0; i < numberOfDiffs; ++i) {

        if (n == arraySize1 - 1)
            if(arraySize1 != 1){
                break;
            }

        arrayDiffs[i] = array2[n] - array1[j];



        if (i == 0){
            if (arrayDiffs[0] < 0){
                j++;
                if ( j == arraySize2){
                    n++;
                    j = 0;
                }
                continue;

            }
            smallestDiff = arrayDiffs [i];
            smallestDiffArray1 = array1[j];
            smallestDiffArray2 = array2[n];
            j++;
            if ( j == arraySize2){
                n++;
                j = 0;
            }
            continue;
        }
        if (arrayDiffs[i] > - 1 && arrayDiffs [i - 1] < 0){
            smallestDiff = arrayDiffs [i];
            smallestDiffArray1 = array1[j];
            smallestDiffArray2 = array2[n];

        } else if (arrayDiffs[i] > - 1 && arrayDiffs[i] < smallestDiff){
            smallestDiff = arrayDiffs [i];
            smallestDiffArray1 = array1[j];
            smallestDiffArray2 = array2[n];
        }

        j++;
        if (j == arraySize2){
            n++;
            j = 0;
        }
    }

    printf("%d (%d, %d)", smallestDiff, smallestDiffArray1, smallestDiffArray2);

    return 0;
}

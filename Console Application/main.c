#include <stdio.h>
#include <stdlib.h>


int* swapElements(int array[], int suffixStart, int length, int variableSwap) {

    int temp;

    for (int i = suffixStart; i < length; ++i) {


        if (suffixStart + 1 == length){
            temp = array[variableSwap];
            array[variableSwap] = array[i];
            array[i] = temp;
            return array;

        }


        if (array[variableSwap] > array[i + 1]) {
            temp = array[variableSwap];
            array[variableSwap] = array[i];
            array[i] = temp;
            return array;
        }


    }

    temp = array[variableSwap];
    array[variableSwap] = array[length - 1];
    array[length - 1] = temp;
    return array;

}

int* sortSuffix(int array[], int length, int suffixStart, int suffixLength) {

    int temp;

    for (int i = 0; i <  (length - suffixStart) / 2; ++i) {
        temp = array[suffixStart + i];
        array[suffixStart + i] = array[length - 1 - i];
        array[length - 1 - i] = temp;


    }
return array;
}

void printArray(int array[], int length){
    for (int i = 0; i < length; i++){
        printf("%d ",array[i]);


    }

}

int main() {
    int length = 0;
    int suffixStart = 0;
    int suffixLength = 0;
    int variableSwap = 0;
    printf(": ");
    scanf("%d", &length);

    int array[length];
    printf(": \n");
    for (int i = 0; i < length; ++i) {
        scanf("%d", &array[i]);

    }

    for (int i = length - 1; i >= 0; --i) {
        if (i == 0){
            printArray(sortSuffix(array, length, suffixStart, suffixLength),length);
            return 0;
        }

        if (array[i - 1] < array[i]) {
            suffixStart = i;
            variableSwap = suffixStart - 1;
            suffixLength = length - i;

            break;
        }

    }





    printArray(sortSuffix(swapElements(array,suffixStart,length, variableSwap), length, suffixStart, suffixLength),length);
    return 0;



}

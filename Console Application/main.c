#include <stdio.h>
#include <stdlib.h>



struct building{

int index;
int height;
};



int main()
{
int input = 0;
int arraySize = 0;


int building[1000];

for(int i = 0; i < 1000; i++){
    scanf(" %d",&input);
    if (input == 0){
       break;
    }


    if(arraySize == 1 || building.height[i] < input){
       building.index[i] = i;
    building.height[i] = input;
    arraySize++;

    } else{

    for(int n = arraySize - 1;n >= 0; n--){

      if(building.height[n] < input){
        continue;


      }
      building.height[n] = input;
      building.index[n] = i;



    }

    }



    building.index[i] = i;
    building.height[i] = input;
    arraySize++;




    for(int j = 0; j <= i; j++){

            if(j + 1 < arraySize - 1 ){
               printf("%d [%d]", array[j], j);
               break;
            }

            if(building.height[j] < building.height[j+1] && ){
            printf("%d [%d]", array[j], j);
            }

    }
}









}

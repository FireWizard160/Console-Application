#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct node {

struct  node* next;
char name;


}typedef node;


node * createNode(char name){

 node* newNode = (struct node*)malloc(sizeof(struct node));
 newNode->name = name;
 newNode->next = NULL;

return newNode;
}

node * addNodeAfter(struct node* newNode, struct node* list){
if (list == NULL){
    newNode->next = NULL;
    return newNode;
}
node* tmp = list;

for(;tmp->next != NULL; tmp = tmp->next){

}

tmp->next = newNode;
return list;
}


void printList(node* list){

    node *temp = list;
        while(temp != NULL)
        {

            printf("%c ",temp->name);
        temp = temp->next;
        }

}

int cntList(node * list){
    int cnt = 0;

    if (list == NULL){
        return cnt;
    }

    if (list->next == NULL){
        cnt++;
        return cnt;
    }
   node* tmp = list;
   for(;tmp != NULL; tmp = tmp->next){
    cnt++;
}
    return cnt;
}





void freeList(node *list) {
    if (list == NULL)
        return;
    freeList(list->next);

    free(list);

}


int main()
{
	// Lists here
	struct node* person = NULL;
	struct node* kassa1 = NULL;
	struct node* kassa2 = NULL;
	struct node* temp = NULL;

    int cntPerson = 0;
    int cntKassa1 = 0;
    int cntKassa2 = 0;


    while(42)
    {
        char n;

        printf(": ");
        scanf(" %c", &n);

        if(n == '-') break;

        // Add person
        person = addNodeAfter(createNode(n), person);
        cntPerson++;

    }



    int run  = 1;
    while(run)
    {
        // Print here
        printf("Personen: %d\n",cntPerson);

        printList(person);



        printf("\nKassa 1: %d\n",cntKassa1);

        printList(kassa1);

        printf("\nKassa 2: %d\n",cntKassa2);

        printList(kassa2);



        char c;
        printf("\n: ");
        scanf(" %c", &c);


        if(c == '-') break;



        switch(c)
        {
        case '-':
            run = 0;
            break;
        case 'a':
            // anstellen


           if(cntKassa1 == cntKassa2 || cntKassa1 < cntKassa2){
            temp = person;

            person = person->next;
            temp->next = NULL;
            kassa1 = addNodeAfter(temp, kassa1);
           }

           if (cntKassa2 < cntKassa1){

            temp = person;

            person = person->next;
            temp->next = NULL;
            kassa2 = addNodeAfter(temp, kassa2);

           }

           cntPerson--;
            cntKassa1 = cntList(kassa1);
            cntKassa2 = cntList(kassa2);
            break;
        case '1':
            // kassa1

            temp = kassa1;

            kassa1 = kassa1->next;



            free(temp);
            cntKassa1 = cntList(kassa1);
            break;
        case '2':
            // kassa2


            temp = kassa2;

            kassa2 = kassa2->next;



            free(temp);
            cntKassa2 = cntList(kassa2);
            break;
        }
    }

    // free list

    freeList(person);
    freeList(kassa1);
    freeList(kassa2);

    return 0;
}




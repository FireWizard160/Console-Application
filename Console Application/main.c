#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int value;
} typedef node;

node *createNode(int value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

node *addAfter(node* newNode, node* list){


    for (node* n = list; n != NULL; n = n->next) {
        if (n->next == NULL){
            n->next = newNode;
            break;
        }



    }



    return newNode;
}

void freeMemory(node *list){
    if (list == NULL)
        return;
    freeMemory(list->next);

    free(list);

}

int main() {
    node *list = NULL;
    int value = 0;

    while (1){
        scanf("%d",&value);
        if(value == 0) {
            break;
        }



        if (list == NULL){
            list = createNode(value);
        } else {
            addAfter(createNode(value),list);
        }



    }

    for (node* n = list; n != NULL; n = n->next) {
        printf("%d ",n->value);

    }
    freeMemory(list);

    return 0;
}

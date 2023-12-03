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

node *addAfter(node *newNode, node *list) {


    for (node *n = list; n != NULL; n = n->next) {
        if (n->next == NULL) {
            n->next = newNode;
            break;
        }


    }


    return newNode;
}

void freeMemory(node *list) {
    if (list == NULL)
        return;
    freeMemory(list->next);

    free(list);

}

void printlist(node *list) {

    for (node *n = list; n != NULL; n = n->next) {
        printf("%d ", n->value);

    }
    printf("\n");
}

int main() {
    node *list = NULL;
    int value = 0;
    int listsize = 0;

    while (1) {
        scanf("%d", &value);
        if (value == 0) {
            break;
        }


        if (list == NULL) {
            list = createNode(value);
        } else {
            addAfter(createNode(value), list);
        }
        listsize++;


    }


    printlist(list);


    while (1) {
        scanf("%d", &value);
        if (value < 0) {

            break;
        }

        if (value > listsize) {
            continue;
        }

        if (value == 0) {
            list = list->next;
            printlist(list);
            listsize--;
            continue;
        }

        node *temp = list;
        node *previous = NULL;
        temp = list;


        if (value == listsize) {
            for (int i = 0; i < value - 1 && temp != NULL; ++i) {
                previous = temp;
                temp = temp->next;
            }

        } else {

            for (int i = 0; i < value && temp != NULL; ++i) {
                previous = temp;
                temp = temp->next;


            }
            previous->next = temp->next;

        }


        printlist(list);
        listsize--;


    }


    freeMemory(list);

    return 0;
}

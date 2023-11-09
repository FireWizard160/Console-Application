#include <stdio.h>
#include <stdlib.h>
struct node {
    int element;
    struct node* next;
};




struct node* addBefore(int value, struct node* head)
{
    struct node* newHead =
            (struct node*)malloc(sizeof(struct node));
    newHead->element = value;
    newHead->next = head;
    return newHead;

}

void size(struct node* head)
{

    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->element);
        temp = temp->next;
    }

}

void freeList(struct node* head) {
    struct node* temp = head;
    while (head != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }
}
int main()
{
    struct node* head = NULL;
int value;


    do {


        scanf("%d",&value);
        if (value != 0)
            head = addBefore(value, head);

    }while (value != 0);




    size(head);
    freeList(head);
    return 0;
}

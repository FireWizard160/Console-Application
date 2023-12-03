#include <stdio.h>
#include <stdlib.h>

enum genre {
    horror = 'h',
    adventure = 'a',
    romance = 'r',
    nonfiction = 'n',
} typedef genre;

struct book {
    char title[32];
    enum genre;
    int year;
    int amount;
};


struct bookNode {
    struct bookNode *next;
    struct book;
} typedef bookNode;

struct borrowNode {
    struct borrowNode *next;
    char title[32];
    char name[32];
} typedef borrowNode;

bookNode *createBookNode(int value) {
    bookNode *newNode = (bookNode *) malloc(sizeof(bookNode));
    //newNode->book = value;
    newNode->next = NULL;
    return newNode;
}

bookNode *addBefore(bookNode *newNode, bookNode *list) {


    for (bookNode *n = list; n != NULL; n = n->next) {
        if (n->next == NULL) {
            n->next = newNode;
            break;
        }


    }


    return newNode;
}

void freeMemory(bookNode *list) {
    if (list == NULL)
        return;
    freeMemory(list->next);

    free(list);

}


void printUngueltigeEingabe(){
    printf("\nUngueltige Eingabe!");
}

bookNode *insertBook() {
    struct book newBook;
    char newTitle[32];
    int input = 0;
    char charInput;

    while (1){
        printf("\nGeben Sie den Titel ein");

        for (int i = 0; i < 32; ++i) {
            scanf("%c", &charInput);
            newBook.title[i] = charInput;
        }
        break;

    }

    while (1){
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4):");
        scanf("%d",&input);
        if(input < 1 || input > 4){
            printUngueltigeEingabe();
            continue;
        }
        newBook.
        break;
    }

    while (1){
        printf("\nGeben Sie das Erscheinungsjahr ein:");
        scanf("%d",&input);

        if(input > 0){
            printUngueltigeEingabe();
            continue;
        }

        break;
    }

    while (1){
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d",&input);

        if(input > 0){
            printUngueltigeEingabe();
            continue;
        }

        break;
    }

}

void borrowBook() {

}

void returnBook() {

}

/*void printList() {
    for (bookNode *n = list; n != NULL; n = n->next) {
        printf("%d ", n->book);

    }
    printf("\n");

}
*/
void printListInOrder() {

}

int main() {
    bookNode* inventoryList;


    char input;

    while (1){
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)");
        printf("\nAuswahl: ");
        scanf(" %c",&input);

        switch (input) {
            case 'n':
                insertBook();

                break;

            case 'b':
                borrowBook();


                break;

            case 'r':
                returnBook();

                break;

            case 'l':
                //printList();

                break;

            case 's':
                printListInOrder();

                break;

            case 'x':
                return 0;

                break;

            default:
                printUngueltigeEingabe();

                break;

        }



    }


    return 0;
}

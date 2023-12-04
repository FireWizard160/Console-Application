#include <stdio.h>
#include <stdlib.h>

enum genre {
    horror = '1',
    adventure = '2',
    romance = '3',
    nonfiction = '4',
} typedef genre;

struct book {
    char title[32];
    int genre;
    int year;
    int amount;
}typedef book;


struct bookNode {
    struct bookNode *next;
    book book;
} typedef bookNode;

struct borrowNode {
    struct borrowNode *next;
    char title[32];
    char name[32];
} typedef borrowNode;

bookNode *createBookNode(book newBook) {
    bookNode *newNode = (bookNode *) malloc(sizeof(bookNode));
    newNode->book = newBook;
    newNode->next = NULL;
    return newNode;
}

bookNode *addBefore(bookNode *newNode, bookNode *inventorylist) {





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
        newBook.genre = input;
        break;
    }

    while (1){
        printf("\nGeben Sie das Erscheinungsjahr ein:");
        scanf("%d",&input);

        if(input > 0){
            printUngueltigeEingabe();
            continue;
        }
        newBook.year = input;
        break;
    }

    while (1){
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d",&input);

        if(input > 0){
            printUngueltigeEingabe();
            continue;
        }
        newBook.amount = input;
        break;
    }
    createBookNode()
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

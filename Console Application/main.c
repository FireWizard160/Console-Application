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
} typedef book;


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
    bookNode *newBookNode = (bookNode *) malloc(sizeof(bookNode));
    newBookNode->book = newBook;
    newBookNode->next = NULL;
    return newBookNode;
}

bookNode *addBookBefore(bookNode *newBookNode, bookNode *inventoryList) {
    newBookNode->next = inventoryList;
    return newBookNode;
}

bookNode *createborrowNode(book newBook) {
    bookNode *newBookNode = (bookNode *) malloc(sizeof(bookNode));
    newBookNode->book = newBook;
    newBookNode->next = NULL;
    return newBookNode;
}

bookNode *addBorrowBefore(bookNode *newBookNode, bookNode *inventoryList) {
    newBookNode->next = inventoryList;
    return newBookNode;
}

void freeMemory(bookNode *list) {
    if (list == NULL)
        return;
    freeMemory(list->next);

    free(list);

}

char *getString(enum genre genreType) {
    switch (genreType) {

        case 1:
            return "Horror";
        case 2:
            return "Abenteuer";
        case 3:
            return "Romantic";
        case 4:
            return "Sachbuch";

    }

    return 0;
}

void printUngueltigeEingabe() {
    printf("\nUngueltige Eingabe!");
}

book insertBook() {
    struct book newBook;
    newBook.title[31] = '\0';
    int input = 0;
    char charInput;

    int checkinput = 0;

    while (1) {
        printf("\nGeben Sie den Titel ein: ");


            scanf("%s", newBook.title);

            if (newBook.title[31] != '\0'){
                printUngueltigeEingabe();

                continue;

            }
        for (int i = 0; i < 32; ++i) {
            if (newBook.title[i] == '\n' && i != 0){
                newBook.title[i] = '\0';
                break;
            }
        }







    }

    while (1) {
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4):");
        scanf("%d", &input);
        if (input < 1 || input > 4) {
            printUngueltigeEingabe();
            continue;
        }
        newBook.genre = input;
        break;


    }

    while (1) {
        printf("\nGeben Sie das Erscheinungsjahr ein:");
        scanf("%d", &input);

        if (input < 0) {
            printUngueltigeEingabe();
            continue;
        }
        newBook.year = input;
        break;
    }

    while (1) {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d", &input);

        if (input < 0) {
            printUngueltigeEingabe();
            continue;
        }
        newBook.amount = input;
        break;
    }
    return newBook;

}

void printList(bookNode inventoryList) {
    int i = 0;
    for (bookNode *n = &inventoryList; n != NULL; n = n->next) {
        i++;

        printf("\n%d: ", i);
        for (int j = 0; j < 32; ++j) {
            if (n->book.title[j] == '\0')
                break;

            printf("%c", n->book.title[j]);

        }
        printf(", %s (%d) ",getString(n->book.genre), n->book.year);

    }


}

void borrowBook(bookNode *inventoryList, int inventoryListSize) {
    int borrowIndex = 0;

    if (inventoryList == NULL){
        printf("\nEs sind keine Buecher im Inventar vorhanden.");
        return;
    }

    printList(*inventoryList);

    while (1){
        printf("\nWelchen Titel moechten Sie leihen? (1-%d): ",inventoryListSize);
        scanf("%d",&borrowIndex);

        if (borrowIndex < 1 || borrowIndex > inventoryListSize){
            printUngueltigeEingabe();
            continue;
        }

        printf("\nGeben Sie Ihren Namen ein: ");

        break;
    }
}

void returnBook() {

}



void printListInOrder() {

}

int main() {
    struct bookNode *inventoryList = NULL;
    int inventoryListSize = 0;

    char input;

    while (1) {
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)");
        printf("\nAuswahl: ");
        scanf(" %c", &input);

        switch (input) {
            case 'n':
                inventoryList = addBookBefore(createBookNode(insertBook()), inventoryList);
                inventoryListSize++;

                break;

            case 'b':
                borrowBook(inventoryList, inventoryListSize);


                break;

            case 'r':
                returnBook();

                break;

            case 'l':
                printList(*inventoryList);

                break;

            case 's':
                printListInOrder();

                break;

            case 'x':
                freeMemory(inventoryList);
                return 0;


            default:
                printUngueltigeEingabe();

                break;

        }


    }


    return 0;
}

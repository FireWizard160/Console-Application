#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct borrowedBook {
    char title[32];
    char name[32];
} typedef borrowedBook;


struct bookNode {
    struct bookNode *next;
    book book;
} typedef bookNode;

struct borrowNode {
    struct borrowNode *next;
    borrowedBook borrowedBook;
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

borrowNode *createBorrowNode(borrowedBook newBorrowedBook) {
    borrowNode* newBorrowNode  = (borrowNode *) malloc(sizeof(borrowNode));
    newBorrowNode->borrowedBook = newBorrowedBook;
    newBorrowNode->next = NULL;
    return newBorrowNode;
}

borrowNode *addBorrowBefore(borrowNode *newBorrowNode, borrowNode *borrowedBookList) {
    newBorrowNode->next = borrowedBookList;
    return newBorrowNode;
}

void freeInventoryMemory(bookNode *inventoryList) {
    if (inventoryList == NULL)
        return;
    freeInventoryMemory(inventoryList->next);

    free(inventoryList);

}

char *getString(enum genre genreType) {
    switch (genreType) {

        case horror:
            return "Horror";
        case adventure:
            return "Abenteuer";
        case romance:
            return "Romantic";
        case nonfiction:
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


    while (1) {
        printf("\nGeben Sie den Titel ein: ");


        scanf("%s", newBook.title);

        if (newBook.title[31] != '\0') {
            printUngueltigeEingabe();

            continue;

        }

        for (int i = 0; i <= strlen(newBook.title); ++i) {
            if (newBook.title[i] == '\0' && i != 0) {
                newBook.title[i] = '\0';
                break;
            }
        }

        break;


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
        printf(", %s (%d) ", getString(n->book.genre), n->book.year);

    }


}

void printBorrowedBookList(borrowNode *borrowedBookList) {

    int i = 0;
    for (borrowNode *n = borrowedBookList; n != NULL; n = n->next) {
        i++;

        printf("\n%d: ", i);

        printf("%s geliehen von %s ", n->borrowedBook.title, n->borrowedBook.name);

    }


}

borrowNode *borrowBook(bookNode *inventoryList, int inventoryListSize, borrowNode *borrowedBookList) {

    int checkInput = 0;
    int borrowIndex = 0;
    char borrowerName[32];
    borrowerName[31] = '\0';
    struct borrowedBook newBorrowedBook;

    if (inventoryList == NULL) {
        printf("\nEs sind keine Buecher im Inventar vorhanden.");
        return 0;
    }

    printList(*inventoryList);

    while (1) {
        printf("\nWelchen Titel moechten Sie leihen? (1-%d): ", inventoryListSize);
        scanf("%d", &borrowIndex);

        if (borrowIndex < 1 || borrowIndex > inventoryListSize) {
            printUngueltigeEingabe();
            continue;
        }

        bookNode *copyInventoryList = inventoryList;
        for (int i = 0; i < borrowIndex;) {
            if (copyInventoryList->next == NULL && borrowIndex == 1)
                break;

            copyInventoryList = copyInventoryList->next;
        }

        if (copyInventoryList->book.amount == 0){
            printf("\nBereits alle Exemplare ausgeliehen!");
        }

        strcpy(newBorrowedBook.title, copyInventoryList->book.title);


        printf("\nGeben Sie Ihren Namen ein: ");

        scanf("%s", borrowerName);

        if (borrowerName[31] != '\0') {
            printUngueltigeEingabe();

            continue;
        }

        strcpy(newBorrowedBook.name, borrowerName);

        for (int i = 0; i <= strlen(borrowerName); ++i) {

            if (borrowerName[i] == '\0') {
                borrowerName[i] = '\0';
                break;
            }
            break;
        }



        if(borrowedBookList != NULL){
            for (borrowNode *n = &borrowedBookList; n != NULL; n = n->next) {
                if (n->borrowedBook.name == borrowerName && newBorrowedBook.name == n->borrowedBook.name){
                    printf("\nSie haben diesen Titel bereits ausgeliehen!");
                    checkInput = 1;
                    break;
                }
            }
        }

        if (checkInput == 1){
            continue;
        }




        borrowedBookList = addBorrowBefore(createBorrowNode(newBorrowedBook), borrowedBookList);
        copyInventoryList->book.amount--;





        break;
    }





    return borrowedBookList;
}

void returnBook(borrowNode *borrowedBookList, bookNode *inventoryList) {
    printBorrowedBookList(borrowedBookList);

}


void printListInOrder() {

}

int main() {
    struct bookNode *inventoryList = NULL;
    struct borrowNode *borrowedBookList = NULL;
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
                borrowedBookList = borrowBook(inventoryList, inventoryListSize, borrowedBookList);


                break;

            case 'r':
                returnBook(borrowedBookList, inventoryList);

                break;

            case 'l':
                printList(*inventoryList);

                break;

            case 's':
                printListInOrder();

                break;

            case 'x':
                freeInventoryMemory(inventoryList);
                return 0;


            default:
                printUngueltigeEingabe();

                break;

        }


    }


    return 0;
}

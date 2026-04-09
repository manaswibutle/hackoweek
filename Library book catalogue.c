#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 5   // Fixed size of library

// Structure for Book
struct Book {
    char title[50];
    char author[50];
};

// Library array and current count
struct Book library[MAX_BOOKS];
int count = 0;

// Function to add a book
void addBook(char title[], char author[]) {
    if (count == MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }
    strcpy(library[count].title, title);
    strcpy(library[count].author, author);
    count++;
    printf("Book added successfully!\n");
}

// Function to search a book by title
void searchBook(char title[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book found!\nTitle: %s\nAuthor: %s\n",
                   library[i].title, library[i].author);
            return;
        }
    }
    printf("Book not found.\n");
}

// Function to remove a book by title
void removeBook(char title[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            // Shift remaining books left
            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }
            count--;
            printf("Book removed successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

// Function to display all books
void displayBooks() {
    if (count == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("\nLibrary Catalogue:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Title: %s, Author: %s\n",
               i + 1, library[i].title, library[i].author);
    }
}

// Main function
int main() {
    int choice;
    char title[50], author[50];

    do {
        printf("\n--- Library Menu ---\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;

                printf("Enter author: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0;

                addBook(title, author);
                break;

            case 2:
                printf("Enter title to remove: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;

                removeBook(title);
                break;

            case 3:
                printf("Enter title to search: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;

                searchBook(title);
                break;

            case 4:
                displayBooks();
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}

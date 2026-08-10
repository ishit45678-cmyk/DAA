//Library Book Management
//• Store the book ID, title, author, total copies, and available copies using structures.
//• Create a menu-driven program to add and search for books, issue and return books, and display
//all books currently unavailable.
#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int total_copies;
    int available_copies;
};

int main() {
    struct Book books[100];
    int count = 0;
    int choice, search_id, i, found, flag;

    while (1) {
        printf("\n--- Library Book Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book by ID\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("\nEnter Book ID: ");
                scanf("%d", &books[count].id);

                printf("Enter Title: ");
                scanf(" %[^\n]", books[count].title);

                printf("Enter Author: ");
                scanf(" %[^\n]", books[count].author);

                printf("Enter Total Copies: ");
                scanf("%d", &books[count].total_copies);

                books[count].available_copies = books[count].total_copies;
                count++;
                printf("Book added successfully!\n");
                break;

            case 2:
                printf("\nEnter Book ID to search: ");
                scanf("%d", &search_id);
                found = 0;

                for (i = 0; i < count; i++) {
                    if (books[i].id == search_id) {
                        printf("\nBook Found:\n");
                        printf("ID: %d\nTitle: %s\nAuthor: %s\nTotal Copies: %d\nAvailable Copies: %d\n",
                               books[i].id, books[i].title, books[i].author,
                               books[i].total_copies, books[i].available_copies);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Book with ID %d not found.\n", search_id);
                }
                break;

            case 3:
                printf("\nEnter Book ID to issue: ");
                scanf("%d", &search_id);
                found = 0;

                for (i = 0; i < count; i++) {
                    if (books[i].id == search_id) {
                        found = 1;
                        if (books[i].available_copies > 0) {
                            books[i].available_copies--;
                            printf("Book issued successfully! Remaining available copies: %d\n", books[i].available_copies);
                        } else {
                            printf("Book is currently unavailable for issuing.\n");
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("Book with ID %d not found.\n", search_id);
                }
                break;

            case 4:
                printf("\nEnter Book ID to return: ");
                scanf("%d", &search_id);
                found = 0;

                for (i = 0; i < count; i++) {
                    if (books[i].id == search_id) {
                        found = 1;
                        if (books[i].available_copies < books[i].total_copies) {
                            books[i].available_copies++;
                            printf("Book returned successfully! Current available copies: %d\n", books[i].available_copies);
                        } else {
                            printf("All copies of this book are already in the library.\n");
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("Book with ID %d not found.\n", search_id);
                }
                break;

            case 5:
                flag = 0;
                printf("\n--- Unavailable Books ---\n");
                for (i = 0; i < count; i++) {
                    if (books[i].available_copies == 0) {
                        printf("ID: %d | Title: %s | Author: %s\n", books[i].id, books[i].title, books[i].author);
                        flag = 1;
                    }
                }
                if (!flag) {
                    printf("No books are currently unavailable.\n");
                }
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
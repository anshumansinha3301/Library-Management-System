#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
    int issued;
};

struct Student {
    int rollNo;
    char name[100];
    int borrowedBookId;
};

struct Book books[100];
struct Student students[100];
int totalBooks = 0;
int totalStudents = 0;

void addBook() {
    printf("Enter book ID: ");
    scanf("%d", &books[totalBooks].id);
    printf("Enter book title: ");
    getchar();
    fgets(books[totalBooks].title, 100, stdin);
    strtok(books[totalBooks].title, "\n");
    printf("Enter book author: ");
    fgets(books[totalBooks].author, 100, stdin);
    strtok(books[totalBooks].author, "\n");
    printf("Enter quantity: ");
    scanf("%d", &books[totalBooks].quantity);
    books[totalBooks].issued = 0;
    totalBooks++;
    printf("Book added successfully!\n");
}

void viewBooks() {
    if (totalBooks == 0) {
        printf("No books available.\n");
        return;
    }
    for (int i = 0; i < totalBooks; i++) {
        printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n", 
            books[i].id, books[i].title, books[i].author, books[i].quantity, books[i].issued);
    }
}

void issueBook() {
    int bookId, rollNo, found = 0;
    printf("Enter student roll number: ");
    scanf("%d", &rollNo);
    printf("Enter book ID to issue: ");
    scanf("%d", &bookId);
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == bookId) {
            if (books[i].quantity > books[i].issued) {
                books[i].issued++;
                students[totalStudents].rollNo = rollNo;
                students[totalStudents].borrowedBookId = bookId;
                printf("Enter student name: ");
                getchar();
                fgets(students[totalStudents].name, 100, stdin);
                strtok(students[totalStudents].name, "\n");
                totalStudents++;
                printf("Book issued successfully!\n");
                found = 1;
            } else {
                printf("No copies left to issue.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void returnBook() {
    int rollNo, found = 0;
    printf("Enter student roll number: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == rollNo) {
            for (int j = 0; j < totalBooks; j++) {
                if (books[j].id == students[i].borrowedBookId) {
                    books[j].issued--;
                    printf("Book returned successfully!\n");
                    found = 1;
                    break;
                }
            }
            break;
        }
    }
    if (!found) {
        printf("No record of borrowing found.\n");
    }
}

void deleteBook() {
    int bookId, found = 0;
    printf("Enter book ID to delete: ");
    scanf("%d", &bookId);
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == bookId) {
            for (int j = i; j < totalBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            totalBooks--;
            printf("Book deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void searchBook() {
    int bookId, found = 0;
    printf("Enter book ID to search: ");
    scanf("%d", &bookId);
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == bookId) {
            printf("Book found! ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n", 
                books[i].id, books[i].title, books[i].author, books[i].quantity, books[i].issued);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

void displayMenu() {
    printf("\n1. Add a Book\n2. View All Books\n3. Issue a Book\n4. Return a Book\n5. Delete a Book\n6. Search a Book\n0. Exit\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                searchBook();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
    return 0;
}

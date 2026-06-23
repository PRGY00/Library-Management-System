#ifndef BOOKS_H // LIBRARY_MANAGEMENT_SYSTEM_BOOKS_H
#define BOOKS_H // LIBRARY_MANAGEMENT_SYSTEM_BOOKS_H

typedef struct {
    int id;
    char title[100];
    char author[100];
} Book;

void addBook(Book b);
void displayBooks();
void deleteBook(int id);

#endif
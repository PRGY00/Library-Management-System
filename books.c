# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# include "books.h"

void addBook(Book b) {  // pass Book struct object as an argument

    FILE* fp;

    // open file for writing
    fp = fopen("books.txt", "a");

    if(fp!=NULL){ // file was successfully opened
        fprintf(fp, "%d;%s;%s\n", b.id, b.title, b.author);
        printf("Book data written successfully\n");
        fclose(fp);
    }
    else {
        perror("fopen");
        return;
    }
}

void displayBooks() {

    // open file for read
    FILE* fp = fopen("books.txt", "r");

    if (fp == NULL) {
        perror("fopen");
        return;
    }

    rewind(fp);

    // setting up a buffer for fgets()
    char buff[203];

    while (fgets(buff, sizeof(buff), fp) != NULL) {
        printf("%s", buff);
    }
    fclose(fp);
}

void deleteBook(int id) {

    // open file for read
    FILE* fp1 = fopen("books.txt", "r");

    if (fp1 == NULL) {
        perror("fopen");
        return;
    }

    // reset the given file pointer to the beginning of a file
    rewind(fp1);

    // setting up a buffer for fgets() and bookID
    char buff[203];
    int bookID;

    FILE* fp2 = fopen("books_copy.txt", "w");

    while (fgets(buff, sizeof(buff), fp1) != NULL) {
        if (sscanf(buff, "%d;", &bookID) == 1) {
            if (bookID != id) {
                fputs(buff, fp2);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);

    char to_be_deleted[] = "books.txt";

    // removing the file
    int remove_flag = remove(to_be_deleted);

    if (remove_flag != 0)
        perror("Deletion Error");

    char old_name[] = "books_copy.txt";
    char new_name[] = "books.txt";

    // renaming the file
    int rename_flag = rename(old_name, new_name);

    if (rename_flag == 0)
        printf("Record deleted successfully\n");
    else
        perror("Rename Error");
}


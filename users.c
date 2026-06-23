# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# include "users.h"

void addUser(User u) {

    FILE* fp_read = fopen("users.txt", "r");

    // setting up a buffer for fgets()
    char buff[205];

    // setting first user's id
    int user_id;

    // checking latest user's id
    if(fp_read!=NULL){ // file was successfully opened
        while (fgets(buff, sizeof(buff), fp_read) != NULL) {
            sscanf(buff, "%d;", &user_id);
        }
        user_id += 1;
        fclose(fp_read);
    }
    else {
        user_id = 1;
    }

    FILE* fp_write = fopen("users.txt", "a");

    // inserting new user's data
    if(fp_write!=NULL){ // file was successfully opened
        fprintf(fp_write, "%d;%s;%s;%d;\n", user_id, u.Name, u.Surname, u.age);
        printf("User added successfully\n");
        fclose(fp_write);
    }
    else {
        perror("fp_write");
        return;
    }
}

void displayUsers() {

    // open file for read
    FILE* fp = fopen("users.txt", "r");

    if (fp == NULL) {
        perror("fopen");
        return;
    }

    rewind(fp);

    // setting up a buffer for fgets()
    char buff[205];

    while (fgets(buff, sizeof(buff), fp) != NULL) {
        printf("%s", buff);
    }
    fclose(fp);
}

void deleteUser(int id) {
    // open file for read
    FILE* fp1 = fopen("users.txt", "r");

    if (fp1 == NULL) {
        perror("fopen");
        return;
    }

    // reset the given file pointer to the beginning of a file
    rewind(fp1);

    // setting up a buffer for fgets() and userID
    char buff[205];
    int userID;

    FILE* fp2 = fopen("users_copy.txt", "w");

    while (fgets(buff, sizeof(buff), fp1) != NULL) {
        if (sscanf(buff, "%d;", &userID) == 1) {
            if (userID != id) {
                // coping content of odl file to the new one (skipping records to be deleted)
                fputs(buff, fp2);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);

    char to_be_deleted[] = "users.txt";

    // removing the file
    int remove_flag = remove(to_be_deleted);

    if (remove_flag != 0)
        perror("Deletion Error");

    char old_name[] = "users_copy.txt";
    char new_name[] = "users.txt";

    // renaming the file
    int rename_flag = rename(old_name, new_name);

    if (rename_flag == 0)
        printf("Record deleted successfully\n");
    else
        perror("Rename Error");
}
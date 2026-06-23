#ifndef USERS_H
#define USERS_H

typedef struct {
    // int id;
    char Name[100];
    char Surname[100];
    int age;
} User;

void addUser(User u);
void deleteUser(int id);

#endif
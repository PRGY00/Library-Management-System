
# USERS MODULE ---------------------------------------------------------------------------------------------------------

Module users contains functions:

addUser(User u) - function responsible for adding user data to the users.txt file.
                  Expected argument is a structure object (here named "User").
                  Each line represents a user with basic data, i.e.
                  - id (type int) added automatically by the function
                  - Name (type sting)
                  - Surname (type string)
                  - age (type int)

displayUsers() - list all users of the library. This function uses while loop
                 to go through all lines of the file until the EOF.

deleteUser(int id) - function responsible for removing user data from the users.txt file.
                     The expected argument is the id of the user that is supposed to be deleted.
                     Function is using while loop to go through the file (line by line) checking
                     if the users id match the one provided as the argument of the function.
                     Positions with different id are copied to the file named "users_copy.txt",
                     line containing id matching the provided id is not copied. At the end
                     function deletes the original "users.txt" file and renames the "users_copy.txt"
                     to the "users.txt".

# BOOKS MODULE ---------------------------------------------------------------------------------------------------------

Module books contains functions:

addUser(Book b) - function responsible for adding book data to the books.txt file.
                  Expected argument is a structure object (here named "Book").
                  Each line represents a user with basic data, i.e.
                  - id (type int) added automatically by the function
                  - title (type sting)
                  - author (type string)

displayBooks() - list all books of the library. This function uses while loop
                 to go through all lines of the file until the EOF.

deleteBook(int id) - function responsible for removing book data from the books.txt file.
                     The expected argument is the id of the book that is supposed to be deleted.
                     Function is using while loop to go through the file (line by line) checking
                     if the books id match the one provided as the argument of the function.
                     Positions with different ids are copied to the file named "books_copy.txt",
                     line containing id matching the provided id is not copied. At the end
                     function deletes the original "books.txt" file and renames the "books_copy.txt"
                     to the "books.txt".
# BookList Application + Extended MovieList Application 

This is a C++ program that implements a **singly linked list** of books. Each node in the list stores:
- A **Title** (`std::string`)
- An **Author** (`std::string`)
- A unique **ISBN** (`int`)

The user interacts with a simple **menu** in `main.cpp` that allows:
1. Displaying all books
2. Adding a new book
3. Searching for a book by ISBN
4. Deleting a book by ISBN
5. Quitting the program

## File Contents

- **BookList.h**  
  Declares the `BookList` class (and the internal `BookNode` struct).
- **BookList.cpp**  
  Defines the methods for `BookList`, such as adding, deleting, searching, printing, etc.
- **main.cpp**  
  Contains the interactive menu loop, which prompts the user for commands and calls `BookList` functions.

## How to Compile

Open a terminal and navigate to the folder that contains the three files. Then run:

```bash
g++ main.cpp booklist.cpp booklistmain.cpp
```

Extension: 
Each node in the list stores:
- A **Title** (`std::string`)
- An **Director** (`std::string`)
- A unique **Publishing Year** (`int`)
Contains the ISBN code with modification to do binary search and sort


The user interacts with a simple **menu** in `moviemain.cpp` that allows:
1. Print all movies
2. Add a new movie
3. Delete a movie by ID
4. Search for a movie by ID
5. Find movies by a specific director
6. Sort and display by release year
8. Quit

## How to Compile

Open a terminal and navigate to the folder that contains the three files. Then run:

```bash
g++ main.cpp movielist.cpp moviemain.cpp
```

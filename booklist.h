#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <string>

class BookList
{
public:
    // constructor
    BookList();

    // destructor
    ~BookList();

    // PutItem: add a new book (Title, Author, ISBN) to the list
    void PutItem(const std::string& t, const std::string& a, int isbn);

    // DeleteItem: delete a book by ISBN. Returns true if found & deleted
    bool DeleteItem(int isbn);

    // IsFull: for a linked list, typically always false unless memory is exhausted
    bool IsFull() const;

    // SearchBook: returns true if a book with given ISBN is found
    bool SearchBook(int isbn) const;

    // EmptyList: delete all nodes
    void EmptyList();

    // PrintList: display the list of books
    void PrintList() const;

private:
    // define a node type for singly‐linked list
    struct BookNode
    {
        std::string title;
        std::string author;
        int isbn;             // unique integer ID
        BookNode* next;       // link pointer
    };

    BookNode* head;  // points to the first node (book) in the list
};

#endif

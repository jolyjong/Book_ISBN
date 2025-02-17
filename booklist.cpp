#include "booklist.h"
#include <iostream>  

using namespace std;

// constructor
BookList::BookList()
    : head(nullptr)
{
}

// destructor
BookList::~BookList()
{
    EmptyList();
}

// insert a new BookNode at the front of the list
void BookList::PutItem(const string& t, const string& a, int isbn)
{
    BookNode* newNode = new BookNode;
    newNode->title  = t;
    newNode->author = a;
    newNode->isbn   = isbn;

    newNode->next = head; // link the new node to the (former) first node
    head = newNode;       // now newNode is the first node
}

// delete book by ISBN
bool BookList::DeleteItem(int isbn)
{
    // if list is empty, there's nothing to delete 
    if (!head)
        return false;

    // if the head is the target
    if (head->isbn == isbn)
    {
        BookNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // or, find a node whose next is the target
    BookNode* curr = head;
    while (curr->next != nullptr && curr->next->isbn != isbn)
    {
        curr = curr->next;
    }

    // if found, curr->next is the node to delete
    if (curr->next && curr->next->isbn == isbn)
    {
        BookNode* temp = curr->next;
        curr->next = temp->next; // bypass the node
        delete temp;
        return true;
    }

    // not found
    return false;
}

// IsFull: Usually false for a linked list unless memory is exhausted
bool BookList::IsFull() const
{
    return false;
}

// return true if we find the given ISBN
bool BookList::SearchBook(int isbn) const
{
    BookNode* curr = head;
    while (curr != nullptr)
    {
        if (curr->isbn == isbn)
            return true;
        curr = curr->next;
    }
    return false;
}

// empty list: delete all nodes
void BookList::EmptyList()
{
    while (head != nullptr)
    {
        BookNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// display all books
void BookList::PrintList() const
{
    if (!head)
    {
        cout << "The book list is empty.\n";
        return;
    }

    BookNode* curr = head;
    cout << "Book List:\n";
    while (curr != nullptr)
    {
        cout << " Title:  " << curr->title  << "\n"
             << " Author: " << curr->author << "\n"
             << " ISBN:   " << curr->isbn   << "\n\n";
        curr = curr->next;
    }
}

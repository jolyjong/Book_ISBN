#include <iostream>
#include <string>
#include "booklist.h"

using namespace std;

int main()
{
    BookList myBooks;
    int choice = 0;

    while (true)
    {
        // menu
        cout << "\n--- BookList Menu ---\n";
        cout << "1. Display all books\n";
        cout << "2. Add a new book\n";
        cout << "3. Search for a book by ISBN\n";
        cout << "4. Delete a book by ISBN\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // check cinn value 
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Invalid input, please try again.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1: {
            // display books
            myBooks.PrintList();
            break;
        }
        case 2: {
            // add new book
            string title, author;
            int isbn;
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            cout << "Enter unique ISBN (integer): ";
            cin >> isbn;

            // isbn check 
            if (myBooks.SearchBook(isbn))
            {
                cout << "ERROR: A book with ISBN " << isbn 
                     << " already exists.\n";
            }
            else
            {
                // insert new book 
                myBooks.PutItem(title, author, isbn);
                cout << "Book added successfully.\n";
            }

            break;
        }
        case 3: {
            // searching 
            int isbn;
            cout << "Enter ISBN to search: ";
            cin >> isbn;

            if (myBooks.SearchBook(isbn))
                cout << "Book with ISBN " << isbn << " found!\n";
            else
                cout << "No book found with ISBN " << isbn << ".\n";

            break;
        }
        case 4: {
            // delete
            int isbn;
            cout << "Enter ISBN of book to delete: ";
            cin >> isbn;

            if (myBooks.DeleteItem(isbn))
                cout << "Book with ISBN " << isbn << " deleted.\n";
            else
                cout << "No book found with ISBN " << isbn << ".\n";

            break;
        }
        case 5: {
            // quit
            cout << "Exiting program...\n";
            return 0; 
        }
        default: {
            cout << "Invalid choice, please try again.\n";
            break;
        }
        }
    }

    return 0;
}

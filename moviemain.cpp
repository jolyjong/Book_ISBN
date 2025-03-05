#include <iostream>
#include <string>
using namespace std;

#include "movielist.h"

int main()
{
    MovieList ml;
    int choice = 0;

    while (true)
    {
        cout << "\n--- MovieList Menu ---\n";
        cout << "1. Print all movies\n"
             << "2. Add a new movie\n"
             << "3. Delete a movie by ID\n"
             << "4. Search for a movie by ID\n"
             << "5. Find movies by a specific director\n"
             << "6. Sort and display by release year\n"
             << "8. Quit\n"
             << "Enter your choice: ";
        cin >> choice;

        if (!cin)
        {
            // inputs not allowed 
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << "Invalid input, please try again.\n";
            continue;
        }
        cin.ignore(1000, '\n'); // discard leftover newline

        switch (choice)
        {
        case 1: {
            //print
            ml.PrintList();
            break;
        }
        case 2: {
            // add new 
            string title, director;
            int releaseYear, movieID;

            cout << "Enter movie title: ";
            getline(cin, title);

            cout << "Enter director: ";
            getline(cin, director);

            cout << "Enter release year: ";
            cin >> releaseYear;
            cout << "Enter unique movie ID: ";
            cin >> movieID;

            // see if the ID exists 
            if (ml.SearchMovie(movieID))
            {
                cout << "ERROR: Movie with ID " << movieID << " already exists.\n";
            }
            else
            {
                ml.AddMovie(title, director, releaseYear, movieID);
                cout << "Movie added.\n";
            }
            break;
        }
        case 3: {
            // delete 
            int movieID;
            cout << "Enter movie ID to delete: ";
            cin >> movieID;

            if (ml.DeleteMovie(movieID))
                cout << "Movie " << movieID << " deleted.\n";
            else
                cout << "No movie found with ID " << movieID << ".\n";
            break;
        }
        case 4: {
            // search 
            int movieID;
            cout << "Enter movie ID to search: ";
            cin >> movieID;

            if (ml.SearchMovie(movieID))
                cout << "Movie with ID " << movieID << " is in the list.\n";
            else
                cout << "No movie found with ID " << movieID << ".\n";
            break;
        }
        case 5: {
            // find director
            cout << "Enter director name: ";
            string director;
            getline(cin, director);

            ml.FindMoviesByDirector(director);
            break;
        }
        case 6: {
            // sort 
            ml.SortByReleaseYear();
            break;
        }
        case 7: {
            // empty list 
            ml.EmptyList();
            cout << "Movie list emptied.\n";
            break;
        }
        case 8: {
            // quit
            cout << "Exiting...\n";
            return 0;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}

#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <iostream>
#include <string>
using namespace std;

class MovieList
{
public:
    
    MovieList();

    // destructor 
    ~MovieList();

    // functions
    void AddMovie(const string& title, const string& director, int releaseYear, int movieID);

    bool DeleteMovie(int movieID);
    bool IsFull() const;
    bool SearchMovie(int movieID) const;
    void EmptyList();
    void PrintList() const;

    void FindMoviesByDirector(const string& director) const;
    void SortByReleaseYear() const; // optional

private:

    struct MovieNode
    {
        string title;
        string director;
        int releaseYear;
        int movieID;
        MovieNode* next;
    };

    MovieNode* head;  
    int getSize() const;
};

#endif

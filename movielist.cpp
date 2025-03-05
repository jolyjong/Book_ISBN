#include "movielist.h"


// constructor
MovieList::MovieList() : head(nullptr)
{

}

// destructor
MovieList::~MovieList()
{
    EmptyList();
}

// functions 
void MovieList::AddMovie(const string& title, const string& director, int releaseYear,int movieID)
{
    //new node 
    MovieNode* newNode = new MovieNode;
    newNode->title       = title;
    newNode->director    = director;
    newNode->releaseYear = releaseYear;
    newNode->movieID     = movieID;
    newNode->next        = nullptr;

    // list is empty -> new node becomes the first one 
    if (!head)
    {
        head = newNode;
        return;
    }

    // if not put it at the end 
    MovieNode* curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }

    curr->next = newNode;
}

bool MovieList::DeleteMovie(int movieID)
{
    if (!head) // if empty
        return false;

    if (head->movieID == movieID)
    {
        MovieNode* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    MovieNode* curr = head;
    while (curr->next && curr->next->movieID != movieID)
    {
        curr = curr->next;
    }
    // if found 
    if (curr->next && curr->next->movieID == movieID)
    {
        MovieNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return true;
    }

    //if not found 
    return false; 
}

bool MovieList::IsFull() const
{
    return false;
}

bool MovieList::SearchMovie(int movieID) const
{
    MovieNode* curr = head;
    while (curr)
    {
        if (curr->movieID == movieID)
            return true;
        curr = curr->next;
    }
    return false;
}

// emptylist
void MovieList::EmptyList()
{
    while (head)
    {
        MovieNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// print entire list 
void MovieList::PrintList() const
{
    if (!head)
    {
        cout << "No movies in the list.\n";
        return;
    }

    cout << "Movie List:\n";
    MovieNode* curr = head;
    while (curr)
    {
        cout << " Title:        " << curr->title << "\n"
             << " Director:     " << curr->director << "\n"
             << " Release Year: " << curr->releaseYear << "\n"
             << " Movie ID:     " << curr->movieID << "\n\n";
        curr = curr->next;
    }
}

// find movie by director 
void MovieList::FindMoviesByDirector(const string& director) const
{
    bool foundAny = false;
    MovieNode* curr = head;
    while (curr)
    {
        if (curr->director == director)
        {
            foundAny = true;
            cout << " Title:        " << curr->title << "\n"
                 << " Release Year: " << curr->releaseYear << "\n"
                 << " Movie ID:     " << curr->movieID << "\n\n";
        }
        curr = curr->next;
    }
    if (!foundAny)
        cout << "No movies found by director \"" << director << "\".\n";
}


int MovieList::getSize() const
{
    int count = 0;
    MovieNode* curr = head;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

// sort 
void MovieList::SortByReleaseYear() const
{
    int size = getSize();
    if (size < 2)
    {
        PrintList();
        return;
    }

    MovieNode** arr = new MovieNode*[size];

    MovieNode* curr = head;
    for (int i = 0; i < size; i++)
    {
        arr[i] = curr;
        curr   = curr->next;
    }

    // bubble sort 
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j]->releaseYear > arr[j + 1]->releaseYear)
            {
                // Swap pointers
                MovieNode* temp = arr[j];
                arr[j]          = arr[j + 1];
                arr[j + 1]      = temp;
            }
        }
    }

    // print out the sorted array 
    cout << "Movies sorted by Release Year:\n";
    for (int i = 0; i < size; i++)
    {
        cout << " Title:        " << arr[i]->title << "\n"
             << " Director:     " << arr[i]->director << "\n"
             << " Release Year: " << arr[i]->releaseYear << "\n"
             << " Movie ID:     " << arr[i]->movieID << "\n\n";
    }

    delete[] arr;
}

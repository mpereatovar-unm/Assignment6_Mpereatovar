
/*Sources: https://www.geeksforgeeks.org/cpp/cpp-linked-list/,
https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/,
https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/,
AI: Chat gpt, claude ai
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "coordinate.h"

using namespace std;

// Count how many coordinates are in the list
int list_length(Coordinate *list_beginning)
{
    int count = 0;
    Coordinate *current = list_beginning->next;

    while (current != nullptr)
    {
        count++;
        current = current->next;
    }

    return count;
}

// Add a new coordinate to the end of the list
void add_coordinate(Coordinate *list_end, float x, float y)
{
    // Find the beginning of the list
    Coordinate *beginning = list_end;

    while (beginning->previous != nullptr)
    {
        beginning = beginning->previous;
    }

    // Create a new coordinate
    Coordinate *newCoord = new Coordinate;

    newCoord->x = x;
    newCoord->y = y;
    newCoord->coord_id = list_length(beginning) + 1;

    // Connect the new coordinate to the list
    newCoord->next = nullptr;
    newCoord->previous = list_end;
    list_end->next = newCoord;
}

// Display coordinates from first to last
void forward_display(Coordinate *list_beginning)
{
    Coordinate *current = list_beginning->next;

    while (current != nullptr)
    {
        cout << "ID: " << current->coord_id
             << " X: " << current->x
             << " Y: " << current->y << endl;

        current = current->next;
    }
}

// Display coordinates from last to first
void backward_display(Coordinate *list_end)
{
    Coordinate *current = list_end;

    // Stop before the dummy starting node
    while (current->previous != nullptr)
    {
        cout << "ID: " << current->coord_id
             << " X: " << current->x
             << " Y: " << current->y << endl;

        current = current->previous;
    }
}

// Delete a coordinate using its ID
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete)
{
    Coordinate *current = list_beginning->next;

    // Search for the coordinate
    while (current != nullptr)
    {
        if (current->coord_id == coord_id_to_delete)
        {
            // Connect the previous node to the next node
            current->previous->next = current->next;

            // Connect the next node to the previous node
            if (current->next != nullptr)
            {
                current->next->previous = current->previous;
            }

            // Free the memory
            delete current;

            cout << "Coordinate deleted." << endl;
            return;
        }

        current = current->next;
    }

    cout << "Coordinate not found." << endl;
}

// Find the coordinate closest to x, y
void closest_to(Coordinate *list_beginning, float x, float y)
{
    Coordinate *current = list_beginning->next;

    if (current == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Coordinate *closest = current;

    // Calculate distance to the first coordinate
    float dx = current->x - x;
    float dy = current->y - y;
    float minDistance = sqrt(dx * dx + dy * dy);

    current = current->next;

    // Check the distance of each remaining coordinate
    while (current != nullptr)
    {
        dx = current->x - x;
        dy = current->y - y;

        float distance = sqrt(dx * dx + dy * dy);

        if (distance < minDistance)
        {
            minDistance = distance;
            closest = current;
        }

        current = current->next;
    }

    // Display the closest coordinate
    cout << "Closest coordinate: ("
         << closest->x << ", " << closest->y << ")" << endl;

    cout << "Distance: " << minDistance << endl;
}

// Main program
int main(int argc, char *argv[])
{
    // Check command-line input
    if (argc != 2 || atoi(argv[1]) < 1)
    {
        cout << "Usage: ./main 10" << endl;
        return 1;
    }

    int n = atoi(argv[1]);

    // Start the random number generator
    srand(time(0));

    // Create an empty starting node (dummy node)
    Coordinate beginning = {};
    Coordinate *tail = &beginning;

    // Generate random coordinates
    for (int i = 0; i < n; i++)
    {
        float x = (float)rand() / RAND_MAX * 100.0f;
        float y = (float)rand() / RAND_MAX * 100.0f;

        // Add coordinate to the list
        add_coordinate(tail, x, y);

        // Move tail to the new coordinate
        tail = tail->next;
    }

    // Display how many coordinates are in the list
    cout << "\nList Length: "
         << list_length(&beginning) << endl;

    // Display coordinates forward
    cout << "\nForward Display:\n";
    forward_display(&beginning);

    // Display coordinates backward
    cout << "\nBackward Display:\n";
    backward_display(tail);

    // Find the closest coordinate to (50, 50)
    cout << "\nClosest to (50, 50):\n";
    closest_to(&beginning, 50, 50);

    // Delete coordinate ID 2
    cout << "\nDeleting coordinate ID 2:\n";
    delete_coordinate(&beginning, 2);

    // Find the last node again after deletion
    tail = &beginning;

    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    // Display the updated list
    cout << "\nList Length After Deletion: "
         << list_length(&beginning) << endl;

    cout << "\nForward Display After Deletion:\n";
    forward_display(&beginning);

    cout << "\nBackward Display After Deletion:\n";
    backward_display(tail);

    // Free all remaining allocated memory
    Coordinate *current = beginning.next;

    while (current != nullptr)
    {
        Coordinate *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

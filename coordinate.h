#ifndef COORDINATE_H
#define COORDINATE_H

struct _corrdinate
{
    float x;
    float y;
    int coord_id;  // Unique identifier for the coordinate
    struct _corrdinate* next;  // Pointer to the next coordinate
    struct _corrdinate* prev;  // Pointer to the previous coordinate

};

    typedef struct _corrdinate Coordinate;

    void add_coordinate(Coordinate *list_end, float x, float y); 
    /*This function adds a new coordinate to the end of the list.
     It creates a new node, stores the x and y values, and assigns an ID based on the list length. 
     It also connects the new node to the previous node using pointers.*/

    void foward_display(Coordinate *list_beginning); 
    /*This function displays all coordinates from beginning to end. 
    It uses the next pointer to move through the list and prints each coordinate's ID, x value, and y value.*/

    void backward_display(Coordinate *list_end); 
    /*This function displays the coordinates in reverse order, starting from the last coordinate.
     It uses the previous pointer to move backward until it reaches the beginning of the list.*/

    void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete); 
    /*This function searches for a coordinate using its ID. 
    When it finds the coordinate, it updates the pointers to keep the list connected and uses delete to free the memory.*/

    int list_length(Coordinate *list_beginning); 
    /*This function counts how many coordinates are in the linked list. 
    It starts at the first coordinate and moves through the list using the next pointer. It returns the total number of coordinates.*/

    void closest_to(Coordinate *list_beginning, float x, float y); 
    /*This function finds the coordinate closest to a given x-y point. 
    It calculates the distance between the given point and each coordinate using the distance formula. 
    It then displays the closest coordinate and its distance.*/
    
    #endif // COORDINATE_H









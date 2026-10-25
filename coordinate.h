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

    void add_coordinate(Coordinate *list_end, float x, float y); // Function to add a coordinate to the list

    void foward_display(Coordinate *list_beginning); // Function to display the coordinates in forward order

    void backward_display(Coordinate *list_end); // Function to display the coordinates in backward order

    void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete); // Function to delete a coordinate from the list by its unique identifier

    int list_length(Coordinate *list_beginning); // Function to get the length of the coordinate list

    void closest_to(Coordinate *list_beginning, float x, float y); // Function to find the closest coordinate to a given point

    #endif // COORDINATE_H


    






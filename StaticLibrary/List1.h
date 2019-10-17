//
// Created by vladead on 15.10.2019.
//

#ifndef PROGRAM1_LIST1_H
#define PROGRAM1_LIST1_H


#include <cstddef>
#include "Node.h"

class List1 {
private:
    Node *head, *current, *tail;
public:
    List1();

    ~List1();

    void push_back(int value);                       // adding element to the end of the list

    void push_front(int value);                      // adding element to the top of the list

    void pop_back();                                 // deleting the last item

    void pop_front();                                // deleting the first item

    void insert(size_t indexOfElement, int value);   // adding an element by index (
                                                     // insertion before the element that
                                                     // was previously available by this index)

    int at(size_t indexOfElement);                   // getting an item by index

    void remove(size_t indexOfElement);              // remove an item by index

    size_t get_size() noexcept ;                     // get list size

    void print_to_console() noexcept;                // outputting list items to the console
                                                     // via the separator

    void clear() noexcept;                           // delete all list items

    void set(size_t indexOfElement, int value);      // replacement of an item by an index

    bool isEmpty() noexcept ;                        // check for empty list

    void push_back(List1& list);                     // inserting another list at the end
};


#endif //PROGRAM1_LIST1_H

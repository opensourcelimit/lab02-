// intlist.cpp
// Implements class IntList
// Jorge Medina), 10/16/2019

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {

for(Node *n= source.first; n!= nullptr; n = n->next)
        {
            append(n->info);


        }

}

// destructor deletes all nodes
IntList::~IntList() {
    Node *temp;
    while (first !=nullptr)
    {
        temp = first->next;
        delete first;
        first = temp;
    }


}


// return sum of values in list
int IntList::sum() const
    {
    int sum = 0;
    for(Node *n = first; n!= nullptr; n =n->next)
    {
        sum = sum + n-> info;
    }
    return sum;
    }



}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    for (Node*n = first; n!= nullptr; n = n->next)
    {
        if(value == n->info)
            return true;
    }

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const

{   // Empty List
    int max_value = 0;
    if (first == nullptr)
        return 0;
    //Else if list is not empty find max info variable
    else
    {
    for(Node *n = first; n!= nullptr; n = n-> next)
      {if (n->info > max_value)
        max_value = n->info;
      }
      return max_value;
    }

}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first == nullptr)
    return 0.0;
    else
        return (1.0*(sum()/(count()));
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node *temp = new Node;
    temp->info= value;
    temp->next = first;
    first = temp;

}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    this->~IntList();



        for(Node *n= source.first; n!= nullptr; n = n->next)
        {
            append(n->info);


        }




    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}

#include <iostream>

using namespace std;

//Heap data structure implemented using an array
class Heap {
  public:
    Heap(); //constructor
    void clear(); //deletes all values from the heap
    void addValue(int); //adds a value to the heap
    int removeValue(); //removes and returns the maximum value in the heap
    void siftUp(int); //if the child value is larger than the parent value, switch the two values' position
    void siftDown(int); //if the parent value is smaller then one of the child values, switch the two values' position
    void display(); //displays all the data values in the heap showing the parent - child relationship for each value
    int getSize(); //gets the number of data values in the heap
  protected:
    int data[1000];
    int size;
};

#include <iostream>

using namespace std;

class Heap {
  public:
    Heap();
    void clear();
    void addValue(int);
    int removeValue();
    void siftUp(int);
    void siftDown(int);
    void display();
    int getSize();
  protected:
    int data[1000];
    int size;
};

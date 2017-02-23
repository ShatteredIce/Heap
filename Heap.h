#include <iostream>

using namespace std;

class Heap {
  public:
    Heap();
    void clear();
    void addValue(int);
    void sift(int);
    void display();
  protected:
    int data[1000];
    int size;
};

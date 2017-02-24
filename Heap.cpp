//Heap data structure class

#include <iostream>
#include "Heap.h"

using namespace std;

Heap::Heap(){
  size = 0;
}

void Heap::clear(){
  fill(data, data+size, 0);
  size = 0;
}

void Heap::addValue(int i){
  data[size] = i;
  size++;
  //cout << "adding value:" << i << "\n";
  siftUp(size - 1);
}

void Heap::siftUp(int index){
  //cout << data[(index-1)/2] << " " << data[index] << endl;
  if(index == 0){
    return;
  }
  else if(data[(index-1)/2] < data[index]){
    int temp = data[index];
    data[index] = data[(index-1)/2];
    data[(index-1)/2] = temp;
    //display();
    siftUp((index-1)/2);
  }
}

int Heap::removeValue(){
  if(size > 0){
    int maxValue = data[0];
    data[0] = data[size - 1];
    data[size - 1] = 0;
    size--;
    siftDown(0);
    return maxValue;
  }
}

void Heap::siftDown(int index){
  if(size < index * 2 + 1){
    return;
  }
  //switch positions of parent and left child if parent < left child and leftchild >= rightchild
  else if(data[index] < data[index * 2 + 1] && data[index * 2 + 1] >= data[index * 2 + 2]){
    int temp = data[index];
    data[index] = data[index * 2 + 1];
    data[index * 2 + 1] = temp;
    //display();
    siftDown(index * 2 + 1);
  }
  //switch positions of parent and right child if parent < right child and rightchild >= leftchild
  else if(data[index] < data[index * 2 + 2] && data[index * 2 + 2] >= data[index * 2 + 1]){
    int temp = data[index];
    data[index] = data[index * 2 + 2];
    data[index * 2 + 2] = temp;
    //display();
    siftDown(index * 2 + 2);
  }
}

void Heap::display(){
  int rowLength = 1;
  int rowPosition = 0;
  for(int i = 0; i < size; i++){
    cout << data[i] << " ";
    rowPosition++;
    if(rowLength == rowPosition && i != size-1){
      cout << "\n";
      rowPosition = 0;
      rowLength *= 2;
    }
  }
  cout << endl;
}

int Heap::getSize(){
  return size;
}

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
  sift(size - 1);
}

void Heap::sift(int index){
  //cout << data[(index-1)/2] << " " << data[index] << endl;
  if(index == 0){
    return;
  }
  else if(data[(index-1)/2] < data[index]){
    int temp = data[index];
    data[index] = data[(index-1)/2];
    data[(index-1)/2] = temp;
    //display();
    sift((index-1)/2);
  }
}

void Heap::display(){
  for(int i = 0; i < size; i++){
    cout << data[i] << " ";
  }
  cout << endl;
}

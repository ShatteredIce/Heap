//C++ Project 9 - Heap - 2/23/17
//Creates a heap data structure in an array
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Heap.h"

using namespace std;

void getInput(char* input);
void trimWhitespace(char* input);

int main(){

  Heap* heap = new Heap();
  bool running = true;
  char input[101];
  char number[11];
  int copyIndex;

  cout << "\n-----Heap Data Structure v1.0-----\n";
  cout << "Stores a string of integers into an array representing a heap data structure\n";
  cout << "C++ Project 9 - Nathan Purwosumarto\n\n";

  while(running){
    cout << "Input: ";
    getInput(input);
    //if input = quit, then end the program
    if(strcmp(input, "quit") == 0){
      cout << "\nProgram Terminated." << endl;
      running = false;
    }
    else{
      heap->clear();
      copyIndex = 0;
      for(int i = 0; i < strlen(input); i++){
        if(isdigit(input[i])){
          number[copyIndex] = input[i];
          copyIndex++;
        }
        else if(copyIndex != 0){
          heap->addValue(strtol(number, NULL, 10));
          fill(number, number + 11, ' ');
          copyIndex = 0;
        }
        else{
          copyIndex = 0;
        }
      }
      if(copyIndex != 0){
        heap->addValue(strtol(number, NULL, 10));
        fill(number, number + 11, ' ');
        copyIndex = 0;
      }
    }
    heap->display();
  }
}

//stores user input into a char*
void getInput(char* input){
  fill(input, input + 101, ' ');
  cin.getline(input, 101);
  trimWhitespace(input);
}

void trimWhitespace(char* text){
  char* newText = text;
  char lastChar = ' ';
  while(*text != '\0'){
    if(!(*text == ' ' && lastChar == ' ')){
      *newText = *text;
      lastChar = *text;
      newText++;
    }
    text++;
  }
  if(*(newText-1) != ' '){
    *newText = '\0';
  }
  else{
    *(newText-1) = '\0';
  }
}

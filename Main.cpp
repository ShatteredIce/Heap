//C++ Project 9 - Heap - 2/23/17
//Creates a heap data structure in an array
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "Heap.h"

using namespace std;

//prototypes
void getInput(char* input);
void trimWhitespace(char* input);

int main(){

  Heap* heap = new Heap();
  bool running = true;
  char input[101];
  char number[11];
  int copyIndex;

  cout << "\n-----Heap Data Structure v1.0-----\n";
  cout << "Stores a string of integers into an array representing a heap data structure.\n";
  cout << "Enter 'file' to use a file as input or 'quit' to exit the program.\n";
  cout << "C++ Project 9 - Nathan Purwosumarto\n\n";

  //gets user input while program is running
  while(running){
    cout << "Input: ";
    getInput(input);
    //if input = quit, then end the program
    if(strcmp(input, "quit") == 0){
      cout << "\nProgram Terminated." << endl;
      running = false;
      break;
    }
    //if the user inputs 'file', prompt for filename
    if(strcmp(input, "file") == 0){
      cout << "Enter filename: ";
      getInput(input);
      fstream myfile(input);
      if (myfile.is_open()){
        //if file is found, copy contents into input
        myfile.getline(input, 101);
        trimWhitespace(input);
        cout << input << endl;
        myfile.close();
      }
      //tell the user if filename is invalid
      else{
        cout << "Unable to open file.\n\n";
        continue;
      }
    }
    //clear previous data from heap
    heap->clear();
    //extracts numbers from the input char array one by one
    copyIndex = 0;
    fill(number, number + 11, ' ');
    for(int i = 0; i < strlen(input); i++){
      if(isdigit(input[i])){
        number[copyIndex] = input[i];
        copyIndex++;
      }
      //add the extracted number into the heap
      else if(copyIndex != 0){
        heap->addValue(strtol(number, NULL, 10));
        fill(number, number + 11, ' ');
        copyIndex = 0;
      }
      else{
        copyIndex = 0;
      }
    }
    //add the extracted number into the heap
    if(copyIndex != 0){
      heap->addValue(strtol(number, NULL, 10));
      fill(number, number + 11, ' ');
      copyIndex = 0;
    }
    //display the full heap after all numbers have been added
    cout << "Full Heap: \n";
    heap->display();
    cout << "Output: ";
    //remove every value from heap and add it to the output
    while(heap->getSize() > 0){
      cout << heap->removeValue() << " ";
      // cout << "Heap: \n";
      // heap->display();
    }
    cout << "\n\n";
  }
}

//stores user input into a char*
void getInput(char* input){
  fill(input, input + 101, ' ');
  cin.getline(input, 101);
  trimWhitespace(input);
}

//trims the whitespace from a char*
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

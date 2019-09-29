// Project:     catacombs(catacombs( ))
// Team:        RuffRiders
// Authors:     Ryan Appleby, Gabby Khan, Moon Skillin, Anuar Beisembayev
// Date:        09-28-2019 (hackUMBC)
// File:        MyStack.cpp, implementation of stack
/* Description: This is the source code for our hackUMBC project, a text
   based adventure game set in fictional catacombs underneath real tunnels
   underneath the UMBC campus. It's a dungeon crawler, with relatively basic
   mechanics, and a constant hard coded map (no random room generation).    */

#include "MyStack.h"

ToFrom::ToFrom(pair<int, int> toFrom){
  m_data = toFrom;
}
MyStack::MyStack(){
  myStack = nullptr;
}

MyStack::~MyStack(){
  while(!isEmpty()){
    pop();
  }
}

// push the values on to stack
void MyStack::push(ToFrom* toFrom){
  // make temp pointer of ToFrom type
  ToFrom* temp = myStack;
  //next is the temp
  toFrom -> m_next = temp;
  // stack top is now that value
  myStack = toFrom;
}

// pop value off of stack
pair<int, int> MyStack::pop(){
  // make temp pointer point to top of stack
  ToFrom* temp = myStack->m_next;
  // delete top
  delete myStack;
  // stack new top = temp m_next
  myStack = temp;
  // return the top

  if (temp != nullptr){
    return temp->m_data;
  }

  else{
    pair<int, int> null = {0, 0};
    return null;
  }

}

// read top of stack
pair<int, int> MyStack::read(){
  // return the top of the data
  return myStack->m_data;
}

bool MyStack::isEmpty(){
  return myStack == nullptr;
}

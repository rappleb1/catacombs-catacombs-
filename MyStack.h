// Project:     catacombs(catacombs( ))
// Team:        RuffRiders
// Authors:     Ryan Appleby, Gabby Khan, Moon Skillin, Anuar Beisembayev
// Date:        09-28-2019 (hackUMBC)
// File:        MyStack.h, header file for keeping track of location
/* Description: This is the source code for our hackUMBC project, a text
   based adventure game set in fictional catacombs underneath real tunnels
   underneath the UMBC campus. It's a dungeon crawler, with relatively basic
   mechanics, and a constant hard coded map (no random room generation).    */
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct ToFrom{
  ToFrom(pair<int, int>);
  pair<int, int> m_data;
  ToFrom* m_next;

};

struct MyStack{
  // stack constructor
  MyStack();

  //stack destructor
  ~MyStack();

  // pushes data onto stack
  void push(ToFrom*);

  // pops pair off of stack
  pair<int, int> pop();

  // reads the top of stack
  pair<int, int> read();

  bool isEmpty();

  // stack
  ToFrom* myStack;

  vector<int> m_path;

};

#endif

/*
typedef std::pair<int,int> src_dest_t;

// Struct for data items on the stack
struct StackEntry {
  src_dest_t src_dest;   // source-dest pair
  StackEntry *next;      // pointer to next entry

  // Default Constructor
  StackEntry( int src = VACANT, int dest = VACANT ) {
    src_dest = std::pair<int,int>(src, dest);
    next = nullptr;
  }

  // Non-Default Constructor
  StackEntry( src_dest_t sd ) {
    src_dest = sd;
    next = nullptr;
  }
};


 class SolveStack {
 public:
   SolveStack();
   ~SolveStack();
   bool empty() const;
   void push(src_dest_t src_dest);
   src_dest_t pop();
   src_dest_t read() const;
 private:
   entry_t *_stack;
 };

private:
 cell_t *_maze;
 int _ncell;

 //
 // MAY ADD PRIVATE FUNCTION PROTOTYPES HERE
 //

};

// push method implementation
void Maze::SolveStack::push(src_dest_t src_dest) {
  // make the new entry to push on
  entry_t * newEntry = new entry_t(src_dest);
  // the next of entry points at temp
  newEntry->next = _stack;
  // head of stack is newEntry
  _stack = newEntry;
}

// pop method implementation
src_dest_t Maze::SolveStack::pop() {
  // if empty stack throw error
  if (_stack == nullptr) {
    throw std::invalid_argument("Stack is empty! No popping!");
  }
  // temp points to top of stack
  entry_t * temp = _stack;
  // _stack points to whats next
  _stack = _stack->next;
  // store the temp value
  src_dest_t tempPair = temp->src_dest;
  // delete temp
  delete temp;
  // return the src type
  return tempPair;
}
*/

/* stack.h ---
   A generic stack data type class
 */

#ifndef INCLUDED_STACK_H
#define INCLUDED_STACK_H 1

#include <iostream>

using namespace std;

template <class Type> class Stack;
template <class Type>
ostream & operator<<(ostream &os, const Stack<Type> &s);

template <class Type>
class Stack
{
private:
  static const int MAX_STACK = 32;
  struct Node
  {
    Type element;
    Node *next;
  };
  Node *stackTop;
  int numItems;

public:
  Stack();
  ~Stack();
  void pop(void);
  void push (Type e);
  void clear(void);
  Type top(void);
  bool isEmpty(void);
  bool isFull(void);
  friend ostream & operator<< <> (ostream &os, const Stack<Type> &s);
};

// Implementation

template <class Type>
Stack<Type>::Stack()        // default constructor
{
  stackTop = new Node;
  stackTop = NULL;
  numItems = 0;
}

template <class Type>
Stack<Type>::~Stack()       // default destructor
{
  delete stackTop;
}

// pop deletes top item of the stack
template <class Type>
void Stack<Type>::pop(void)
{
  if (stackTop != NULL)           // stack not empty
    {
      Node *temp = new Node;
      temp = stackTop;           // move current top to temp to be deleted
      stackTop = stackTop->next;  // move second item to top
      delete temp;
      numItems--;
    }
  else
    cerr << "ssc: Cannont pop an empty stack\n";
}

// pushes an element to the top of the stack
template <class Type>
void Stack<Type>::push(Type e)
{
  // only push if stack not full
  if (numItems < MAX_STACK)
    {
      Node *newNode = new Node;       // create the new node to add
      newNode->element = e;
      newNode->next = stackTop;       // newNode now points to previous top
      stackTop = newNode;             // newNode is now the top
      numItems++;
    }
  else
    cerr << "ssc: cannot push to full stack\n";
  
}

//clear the stack, leaving it empty
template <class Type>
void Stack<Type>::clear(void)
{
  while (stackTop != NULL)
    pop();
}

// return top element of stack w/out changing stack
template <class Type>
Type Stack<Type>::top(void)
{
  if (stackTop == NULL)         // if stack empty return NULL CHAR
    return '\0';
  else
    return stackTop->element;
}

// returns true if empty stack, otherwise false
template <class Type>
bool Stack<Type>::isEmpty(void)
{
  return (stackTop == NULL);
}

// returns true if stack is full, otherwise false
template <class Type>
bool Stack<Type>::isFull(void)
{
  return (numItems == MAX_STACK);
}

// overloads << operator to print entire stack from top
template <class Type>
ostream &operator<< (ostream &os, const Stack<Type> &s)
{
  // create a temp stack to transverse the stack
  Stack<Type> temp;
  temp = s;

  while (temp.stackTop != NULL)     // move through stack until bottom
    {
      os << temp.stackTop->element << " ";
      temp.stackTop = temp.stackTop->next;
    }

  return os;
}

#endif /* INCLUDED_STACK_H */


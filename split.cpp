/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  if (in == nullptr){ //base case to return when null
    return;
  }
  Node* current = in;
  in = nullptr;
  if (current->value % 2 == 0){ //if node is even, make it the current node 
    evens = current;
    split(current->next, odds, evens->next); //goes to next even node
  }
  else{
    odds = current; //makes node current if odd
    split(current->next, odds->next, evens); //goes to next odd node 
  }
}

/* If you needed a helper function, write it here */

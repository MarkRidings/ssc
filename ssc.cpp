/* Simple Stack Calculator by Mark Ridings
   This program implements a stack based, Revese Polish Notation, calculator.
   To ensure accuracy, ssc stores all inputed values as a Rational Number
   having a numerator and a denominator.  The calculator supports 4 mathematical
   operations: addition(+), subtraction(-), multiplication(*) and
   division(/).  The list of complete operations supported is as follows:
   
   Operation      Description
      p           Prints the current top entry on the stack
      P           Pops the top entry from the stack
      f           Prints the entire stack starting with top
      c           Pops all items off the stack (clears stack)
      d           Duplicates the top entry on the stack
      r           Reverses the top two entries on the stack
      s           Show RationalNumber in decimal form
      +           Replaces top 2 entries with their sum
      -           Replaces top 2 entries with their difference
      *           Replaces top 2 entries with their product
      /           Top entry is divided into item below it.  Answer
                  replaces the top two entries

      Rational numbers are inputed, via standard input, in the following forms:
      integer  ->  6 or -5
      decimal  ->  7.63 or -2.0 or 0.38
      fraction ->  8/9 or -6/7 or 11/2
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include "rational.h"
#include "stack.h"

using namespace std;

int main()
{
  Stack<RationalNumber> s;
  char c, ch;                     // chars for input
  RationalNumber first, second;  // for input
  RationalNumber answer;         // for arithmetic operations
  RationalNumber identity(-1);   // for sign conversion
  bool cont = true;
  
  cout << "ssc: enter h for options\n";

  // input loop
  while (cont)
    {
      c = (cin >> ws).peek();   // observe first char of input

      // if at end of file exit
      if (cin.eof())
        return 0;

      // take appropriate action based on stack
      switch (c)
        {
        case 'p':               // print top of stack
          cin >> ch;
          cout << s.top() << endl;
          break;
        case 'P':		// Pop the stack
          cin >> ch;
          s.pop();
          break;
        case 'r':		// reverse top two entries on stack
          cin >> ch;
          first = s.top();
          s.pop();
          second = s.top();
          s.pop();
          s.push(first);
          s.push(second);
          break;
        case 'd':		// duplicate top entry on stack
          cin >> ch;
          s.push(s.top());
          break;
        case 's':		// output top number in decimal form
          cin >> ch;
          first = s.top();
          cout << first.showDecimal() << endl;
          break;
        case 'c':		// clear stack
          cin >> ch;
          while (!s.isEmpty())
            s.pop();
          break;
        case 'f':		// print entire stack starting at top
          cin >> ch;
          cout << s << endl;
          break;
        case 'h':		// list options
          cin >> ch;
          cout << "----------------------------------------------------\n";
          cout << "p   -  Print current top entry on stack\n";
          cout << "P   -  Pop the stack\n";
          cout << "f   -  print entire stack starting with top\n";
          cout << "c   -  Pops all items clearing the stack\n";
          cout << "d   -  Duplicates the top entry on the stack\n";
          cout << "r   -  Reverses the top two entries on the stack\n";
          cout << "s   -  Displays number as a decimal\n";
          cout << "q   -  Exit program\n";
          cout << "----------------------------------------------------\n";
          break;
        case 'q':		// quit program
          cin >> ch;
          cont = false;
          break;
        case '+':		// replace top two items of stack with sum
          cin >> ch;
          first = s.top();
          s.pop();
          second = s.top();
          s.pop();
          answer = second + first;
          s.push(answer);
          break;
        case '-':		// replace top two items of stack with difference
          cin >> ch;

          // determine if '-' is subtraction or negative sign
          c = (cin >> ws).peek();
          if (isdigit(c))               // if c isdigit then '-' is negative sign
            {
              cin >> first;             // input a RationalNumber
              first = first * identity; // format negative number
              s.push(first);
            }
          else                          // '-' is subtraction
            {
              first = s.top();
              s.pop();
              second = s.top();
              s.pop();
              answer = second - first;
              s.push(answer);
            }
          break;
        case '*':		// replace top two items of stack with product
          cin >> ch;
          first = s.top();
          s.pop();
          second = s.top();
          s.pop();
          answer = second * first;
          s.push(answer);
          break;
        case '/':		// replace top two items of stack with quotient
          cin >> ch;
          first = s.top();
          s.pop();
          second = s.top();
          s.pop();

          // check for division by zero
          if (first.isZero())
            {
              cerr << "ssc: undefined division by zero\n";
              s.push(second);
              s.push(first);
            }
          else
            {
              answer = second / first;
              s.push(answer);
            }
          break;
        default: 		// either a number or unimplemented option
          if (isdigit(c))
            {
              cin >> first;	// input RationalNumber
              if (first.isLegal())
                if (s.isFull())
                  cerr << "ssc: stack is full\n";
                else
                  s.push(first);
              else
                cerr << "ssc: undefined number\n";
            }
          else 			// unimplemented option
            {
              cin >> ch;
              cerr << "ssc: " << ch << " not implemented\n";
            }
        } // end of switch
    }     // end of while

  return 0;
}

                

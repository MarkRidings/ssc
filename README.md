ssc
===

   Simple Stack Calculator by Mark Ridings
   This program implements a stack based, Revese Polish Notation, calculator.
   To ensure accuracy, ssc stores all inputed values as a Rational Number
   having a numerator and a denominator.  The calculator supports 4 mathematical
   operations: addition(+), subtraction(-), multiplication(*) and
   division(/).  The list of complete operations supported is as follows:
   
   
   Operation        Description
   *   'p'           Prints the current top entry on the stack
   *   'P'          Pops the top entry from the stack
   *   'f'           Prints the entire stack starting with top
   *   'c'           Pops all items off the stack (clears stack)
   *   'd'           Duplicates the top entry on the stack
   *   'r'           Reverses the top two entries on the stack
   *   's'           Show RationalNumber in decimal form
   *   '+'           Replaces top 2 entries with their sum
   *   '-'           Replaces top 2 entries with their difference
   *   '*'           Replaces top 2 entries with their product
   *   '/'           Top entry is divided into item below it.  Answer
                     replaces the top two entries
   

      Rational numbers are inputed, via standard input, in the following forms:
      * integer  ->  6 or -5
      * decimal  ->  7.63 or -2.0 or 0.38
      * fraction ->  8/9 or -6/7 or 11/2
 


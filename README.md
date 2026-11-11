# RPN-Calculator-C-Practice-
An RPN Calculator meant to be a test of my C++ capabilities. The bare minimum has been implemented so far, and I plan to eventually expand this code, and rewrite within Python and JavaScript.

CALCULATOR (BETA)
 
A small command-line calculator in C++17 with two modes: RPN (Reverse Polish
Notation, the default) and basic, where you type one calculation per line.
 
Main files: 
Calculator.h     
Calculator.cpp   (Class definitions)
main.cpp         Main prompt
 
Command to build and run (VS Code):
 
g++ -std=c++17 -o calc main.cpp Calculator.cpp
./calc
 
Commands:
rpn     (default, can be used to switch to rpn)
basic   (switch to basic mode)
quit    (exit the program)
clear   (empties stack)
 
The prompt shows the current mode: "rpn>" or "basic>".
 
Operators: 
Support for + (add), - (subtract), * (multiply) and / (divide).
 
RPN MODE
 
The operator comes after its numbers. Type numbers and operators
separated by spaces. Numbers are pushed onto a stack, and the operator takes
the top two values and replaces them with the result. After each line the
stack is printed, with the top on the right.
 
  rpn> 3 4 +
  [ 7 ]
  rpn> 2 *
  [ 14 ]
  rpn> clear
  [ ]
 
The stack carries over between lines, so you can keep building on earlier
results. Type "clear" to empty it.
 
For subtraction and division, the second value from the top is the left-hand
side: "10 4 -" is 6 and "20 4 /" is 5.
 
Negative numbers work by typing the minus sign directly before the digits:
"-5 3 +" gives -2.
 
Normal notation to RPN:
 
  3 + 4            ------>   3 4 +
  (3 + 4) * 2      ------>   3 4 + 2 *
  10 - (2 * 3)     ------>   10 2 3 * -
 
Basic mode:
Same as any normal arithmetic:
  basic> 3 + 4
  = 7
  basic> 10 / 4
  = 2.5
 
Switching mode does not clear stack.
 
This is a beta. Not yet supported: parentheses and operator precedence in
basic mode, functions like sqrt, powers, and stack words like dup and swap.

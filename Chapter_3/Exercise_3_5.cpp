/*******************************************************
 ** Exercises from book C++ Crash Cours by Lospinoso. **
 *******************************************************
 * Exercice 3-5.
 * Scan the lsitings in Chatper 2. which methods could be marked as const?
 * Where could you use auto?
 
 * \date last change: 24.09.2021
 * \author            amaia
 */
 
 
 /*
  *  Methodes that could be marked as const:
  * (With a const method the current objects state cannot be changed
     they are read-only methodes.) 

  * Listing 2-20: int get_year const()
  * Listing 2-26: the constructors cannot be const!!!
 
 
 /*
  * Following code WILL NOT compile!!!
  * Error constructors may not be cv-qualified
  * a constructor CANNOT BE const
  
  *     Exercise_3_5.cpp:31:17: error: constructors may not be cv-qualified
        31 |   Taxonomist () const
           |                 ^~~~~
        Exercise_3_5.cpp:36:23: error: constructors may not be cv-qualified
        36 |   Taxonomist (char x) const
           |                       ^~~~~
        Exercise_3_5.cpp:41:22: error: constructors may not be cv-qualified
        41 |   Taxonomist (int x) const
           |                      ^~~~~
        Exercise_3_5.cpp:46:24: error: constructors may not be cv-qualified
        46 |   Taxonomist (float x) const
           |                        ^~~~~
  */
#include <cstdio>

struct Taxonomist 
{
  Taxonomist () const
  {
    printf("(no argument)\n");
  }
  
  Taxonomist (char x) const
  {
    printf("char: %c\n", x);
  }
  
  Taxonomist (int x) const
  {
    printf("int: %d\n", x);
  }
  
  Taxonomist (float x) const
  {
    printf("float: %f\n", x);
  }
};

int main(void) 
{
  Taxonomist t1;
  Taxonomist t2{ 'c' };
  Taxonomist t3{ 65537 };
  Taxonomist t4{ 6.02e23f };
  Taxonomist t5('g');
  Taxonomist t6 = { 'l' };
  Taxonomist t7{};
  Taxonomist t8();
  
  return 0;
}
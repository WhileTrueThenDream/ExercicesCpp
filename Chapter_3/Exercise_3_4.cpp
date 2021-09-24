/*******************************************************
 ** Exercises from book C++ Crash Cours by Lospinoso. **
 *******************************************************
 * Exercice 3-4.
 * Reimplement Listing 3-11 using no explicit types. (Hint: use auto)
 
 * \date last change: 24.09.2021
 * \author:            amaia
 */
 
#include <cstdio>

/* remark: main type cannot be replaced by "auto" it has to be "int"*/
int main(void) 
{
  auto original = 100;
  auto& original_ref = original; /* original_ref will always point to original */
  auto new_value = 200;
  
  printf("Original:  %d\n", original);
  printf("Reference: %d\n", original_ref);
  
  original_ref = new_value;      /* original_ref still refers to original, then the new_value is assigned to original */
  printf("Original:  %d\n", original);
  printf("New Value: %d\n", new_value);
  printf("Reference: %d\n", original_ref);
  
  printf("\n Remark: what you see here is that what a reference (original_ref)\
  points to cannot be changed one initialized, it changes only the value of the pointed object\n");
  

  printf("original address:      %p\n", (void*)&original);
  printf("original_refaddress:   %p\n", (void*)&original_ref); /*It will always refer original object */
  printf("new_value address:     %p\n", (void*)&new_value);
  
  return 0;
}

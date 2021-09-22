
/*******************************************************
 ** Exercises from book C++ Crash Cours by Lospinoso. **
 *******************************************************
 * Exercice 3-3.
 
 * Add an Element* previous to Listing 3-9 to make a 
 * doubly linked list. 
 * Add an insert_before method to Element. 
 * Traverse the list from front to back, then from back to front , 
 * using two separated for loops. 
 * Print the operating_number 
 * inside each group. 
 
 * \date last change: 22.09.2021
 * \author:            amaia
 */
#include <cstdio>

struct Element 
{
  Element* next{}; /* next element */
  Element* prev{}; /* previous element */
  
  char prefix[2];
  short operating_number;
  
  void insert_after(Element* new_element)  /* inserts a new_element after current one. */
  {
    new_element->next  = this->next;
	if((this->next) != 0)
	{
	  (this->next)->prev = new_element;
	}
	
    this->next         = new_element;
	new_element->prev  = this;
  }
  
  void insert_before (Element* new_element) /* inserts a new_element before current one. */
  {
	if((this->prev) != 0)
	{
	  (this->prev)->next = new_element;  
	}
	
	new_element-> prev = this ->prev;
	this ->prev        = new_element;
    new_element->next  = this;
  }
};

int main() 
{
	
  Element trooper1, trooper2, trooper3, trooper1_1, trooper2_1;
  trooper1.prefix[0] = 'T';
  trooper1.prefix[1] = 'K';
  trooper1.operating_number = 421;
  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 2187;
  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 005;
  trooper1_1.prefix[0] = 'A';
  trooper1_1.prefix[1] = 'B';
  trooper1_1.operating_number = 11;
  trooper2_1.prefix[0] = 'C';
  trooper2_1.prefix[1] = 'D';
  trooper2_1.operating_number = 21;
  
  printf("\n*******************************\n");  
  printf("** Test insert_after methode **\n");
  printf("*******************************\n\n");  
  trooper1.insert_after(&trooper2);
  trooper2.insert_after(&trooper3);

  printf("  List from front to back: \n");
  for(Element* cursor = &trooper1; cursor; cursor = cursor->next) 
  {
    printf("   Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
  }
  
  /* Test list from back to front*/
  printf("\n  List from back to front: \n");
  for(Element* cursor = &trooper3; cursor; cursor = cursor->prev) 
  {
    printf("   Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
  }
 
  printf("\n*******************************\n");  
  printf("** Test insert_before methode **\n");
  printf("*******************************\n\n");  
  printf("   (It was inserted a new element before 2 and another before 3)\n\n");
   
  trooper2.insert_before(&trooper1_1); /* reverse the elements*/
  trooper3.insert_before(&trooper2_1);

  printf("  List from front to back: \n");
  for(Element* cursor = &trooper1; cursor; cursor = cursor->next) 
  {
    printf("   Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
  }
  
  /* Test list from back to front*/
  printf("\n  List from back to front: \n");
  for(Element* cursor = &trooper3; cursor; cursor = cursor->prev) 
  {
    printf("   Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
  }  
  
}

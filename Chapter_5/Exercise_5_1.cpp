/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
*******************************************************
* Exercice 5-1.
* Design an interface called AccountDatabase that can 
* retrieve and set amounts in bank accounts.
* Bank accounts are identified by long id.
     
* \date last change: 03.10.2021
* \author            amaia
*/
     
/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
*******************************************************
* Exercice 5-2.
* Generate an InMemoryAccountDataBase that implements 
* AccountDataBase
     
* \date last change: 03.10.2021
* \author            amaia
*/
     
#include <cstdio>

struct AccountDatabase
{
    virtual ~AccountDatabase() = default;
    virtual double get_amount(const long account_id) = 0;	
    virtual void set_amount(const long account_id, double amount) = 0;
};

struct Bank 
{
  int make_transfer(long from, long to, double amount) 
  {
	int ret_val = 0; 
	
	printf(" >>> Transfer %f: %ld -> %ld <<<\n", amount, from, to);
	
	return ret_val;
  }
};


int main(void)
{
  Bank bank;                               /* Constructor injection...*/
  
  bank.make_transfer(122258877, 188258899, 49.95);   
     
  return 0;    
}
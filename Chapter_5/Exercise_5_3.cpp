/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
*******************************************************
* Exercice 5-3.
* Add an AcountDatabase reference member to Bank. Use
* constructor injection to add an InMemoryAccountDatabase to the Bank.
     
* \date last change: 04.10.2021
* \author            amaia
*/
     
#include <cstdio>

struct AccountDatabase
{
    virtual ~AccountDatabase() = default;
    virtual double get_amount(const long account_id) = 0;	
	virtual void set_amount(const long account_id, double amount) = 0;
};

struct InMemoryAccountDatabase: AccountDatabase
{
    double get_amount(const long account_id) override
	{
        double amount = 0;
        /* check that account_id exists */
        /* get amount from Data Base ...*/
        
	    amount = 1000;
        
        printf("[balance]:account: %ld; balance:  %f\n", account_id, amount);
        return amount;
	}	
	
	void set_amount(const long account_id, double amount) override
	{
        /* check that account_id exists */
        printf("[new balance] :account: %ld; balance:  %f\n", account_id, amount);
        /* set amount in data base */
	}
};


struct Bank 
{
  Bank(AccountDatabase& dataBase)
  : dataBase{dataBase} {}

  int make_transfer(long from, long to, double amount) 
  {
	int ret_val = 0;                              /* 0 if transfer performed */
	double balance_from, balance_to;
	
	printf(" >>> Transfer %f: %ld -> %ld <<<\n",amount, from, to);
	
	balance_from = dataBase.get_amount(from);    /* check origin balance */
	balance_to   = dataBase.get_amount(to);      /* check destiny balance */
	
    if(balance_from >= amount)                    /* check if enough money in account */
	{
        dataBase.set_amount(from, (balance_from - amount));  /* substract money from origin*/
	    dataBase.set_amount(to, (balance_to + amount));	  /* add money to destiny */
	}
	else
	{
        printf("[ERROR]: Balance insufficient \n");
        printf("         Balance in %ld:  is : %f \n", from, balance_from);
        printf("         %f could not be transferred \n", amount);
	    ret_val = -1;	                                      /* set error value. */
	}
    
	return ret_val;
  }

  private:
    AccountDatabase& dataBase;
};


int main(void)
{
  InMemoryAccountDatabase dataBase;        /* Declare a dataBase of type AcountDatabase*/
  Bank bank{dataBase};                     /* Constructor injection...*/
  
  bank.make_transfer(122258877, 188258899, 49.95);   
     
  return 0;    
}
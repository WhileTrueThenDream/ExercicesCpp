/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
********************************************************
* Exercice 6-7
* Make account an interface. Implement a CheckingAccount and 
* SavingsAccount. Create a programm with several checking and 
* savings accounts. 
     
* \date last change: 20.10.2021
* \author            amaia
* \note, compile   : g++ 
*/

#include <cstdio>

struct Account
{
  Account(long id):
  id{id}
  {
    //printf("Basic account id %ld \n", id);
  }
   
  double getBalance(void)
  {
    double balance;
    /* connect to data base and get balance from this account id */
	/* lets suppose balance in DB is 1000 */
	balance = 1000; 
	
    return balance;
  }
  
  void setBalance(double balance)
  {
    /* connect to data base and set balance to this account id */
  }
  
  virtual void checking(double amount)
  {
    double balance = getBalance();
    
    balance += amount;
    setBalance(balance);
  }
  
  virtual int withdraw(double amount)
  {
    int ret = 0;
    double balance = getBalance();
    
    if(balance >= amount)
    {
       balance -= amount;  
    }
    else
    {
      ret = -1;
    }
    
    return ret;
  }
  
  long id;  
};

struct SavingsAccount : Account
{
   SavingsAccount(long id):
   Account{id}
   {
     printf("Savings account id: %ld \n", id);
   }
   
   int withdraw(double amount) override
   {
	 /* not permitted to check money from a savings account!*/ 
     return -1;	 
   }
};

struct CheckingAccount : Account
{
  CheckingAccount(long id):
  Account{id}
  {
    printf("Fixed Dep. account id: %ld \n", id);
  }
};

struct Bank 
{
  Bank(Account& account_from, Account& account_to):
  account_from{account_from}, account_to{account_to}  /* constructor injection */
  {
  }

  void make_transfer(double amount) 
  {
    if(-1 != account_from.withdraw(amount)) /* if withdrawal successful then deposit money */
	{
      account_to.checking(amount);
	  printf("money transferred \n");
	}
    else
    {
      /* Error */
      printf("Error, operation denied \n");		
	}
  } 
  private:
    Account& account_from;
    Account& account_to;
};

int main(void) 
{
  SavingsAccount account_1(1221);
  CheckingAccount account_2(2442);
  
  Bank bank_1{account_1,account_2};
  Bank bank_2{account_2,account_1};
  Bank bank_3{account_2,account_2};

  bank_1.make_transfer(49.95);   /* from a savings account , withraw denied*/
  bank_2.make_transfer(49.95);
  bank_3.make_transfer(2000);    /* try to transfer more money (2000) than available (1000) */
}

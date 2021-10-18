/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
********************************************************
* Exercice 6-6
* Implement an Account class and instantiate a Bank<account>
* Implement functions in Account to keep track of balances.
     
* \date last change: 18.10.2021
* \author            amaia
* \note, compile   : g++ 
*/

#include <cstdio>

struct Account
{
  Account(long id)
  :id{id}
  {
    printf("Basic account id %ld \n", id);
  }
  
  double getBalance(void)
  {
    double balance;
    /* connect to data base and get balance from this account id */
    return balance;
  }
  
  void setBalance(double balance)
  {
    /* connect to data base and set balance to this account id */
  }
  
  void checking(double amount)
  {
    double balance = getBalance();
    
    balance += amount;
    setBalance(balance);
  }
  
  int withdraw(double amount)
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



template <typename T_AccountType1, typename T_AccountType2>
struct Bank 
{
  Bank()
  {
  }

  void make_transfer(T_AccountType1 id_from, T_AccountType2 id_to, double amount) 
  {
  id_from.withdraw(amount);
  id_to.checking(amount);
  } 
};

int main() 
{
  Account account_orig{1221};
  Account account_dest{2442};
  
  Bank<Account,Account> bank{};
  
  bank.make_transfer(account_orig, account_dest, 49.95);


}

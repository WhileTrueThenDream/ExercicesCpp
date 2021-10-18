/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
********************************************************
* Exercice 6-5
* Using the example from Chapter 5, make Bank a template
* class that accepts a template parameter. Use this type 
* parameter as the type of an account rather than long. Verify 
* that your code still works using a Bank<long> class.
     
* \date last change: 18.10.2021
* \author            amaia
* \note, compile   : g++ 
*/

#include <cstdio>


template <typename T_AccountType1, typename T_AccountType2>
struct Bank 
{
  Bank()
  {
  }

  void make_transfer(T_AccountType1 id_from, T_AccountType2 id_to, double amount) 
  {
  } 
};

int main() 
{
  
  Bank<long,long> bank{};

  bank.make_transfer(1222, 2222, 49.95);

}

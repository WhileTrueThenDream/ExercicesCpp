/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
*******************************************************
* Exercice 6-4
* Refactor mean in Listing 6-13 to accept an array rather 
* than a pointer and length arguments. 
* Use listing 6-33 as a guide.  
     
* \date last change: 13.10.2021
* \author            amaia
* \note, compile   : g++ 
*/

#include <cstddef>
#include <cstdio>

template <typename T, size_t length>
T mean(const T (&values)[length]) 
{
  T result{};
  for(size_t i{}; i < length; i++) 
  {
    result += values[i];
  }
  return result / length;
}

int main(void) 
{
  const double nums_d[]{ 1.0, 2.0, 3.0, 4.0 };
  const auto result1 = mean(nums_d);
  printf("double: %f\n", result1);

  const float nums_f[]{ 1.0f, 2.0f, 3.0f, 4.0f };
  const auto result2 = mean(nums_f);
  printf("float: %f\n", result2);

  const size_t nums_c[]{ 1, 9, 3, 4 };
  const auto result3 = mean(nums_c);
  printf("size_t: %lu\n", result3);

  return 0;
}

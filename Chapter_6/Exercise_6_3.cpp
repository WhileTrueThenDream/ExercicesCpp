/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
*******************************************************
* Exercice 6-3
* Modify mode to accept an integer concept. Verify that mode
* fails to instantiate with floating types like double.  
     
* \date last change: 13.10.2021
* \author            amaia
* \note, compile   : g++ -fconcepts 
*/

#include <cstdio>
#include <type_traits>

/* concept definition */
template <typename T>
concept bool is_nr_int()
{
    return (std::is_integral<T>::value);
        
}

/* functino template definition */
template <is_nr_int T>
T mode(const T* values, size_t length)
{
    int numb_of_element = 1;                     /* number of elements with value equal to current array index value */
    int *is_val_computed = new int[length]{0};   /* 1 if value was already inspected, 0 if not */
    int mode_index = 0;                          /* mode index of inspected values */
    int numb_of_element_prev = 0;                /* number of most repeated elements among the inspected values */

    for(int j = 0; j < length ; j++)             
    {
        if(is_val_computed[j] == 0)                      /* if value was not yet inspected then ... */
        {
            numb_of_element = 1;                         /* this is the first element with this value */
                
            for(int i = (j + 1) ; i < length; i++)       /* look for values equal to current one with index j */
            {
                if(values[i] == values[j])
                {
                    numb_of_element +=1;                 /* add one if you found another one equal to the one with index j */
                    is_val_computed[i] = 1;              /* mark value as inspected */                  
                }
            }
            
            is_val_computed[j] = 1;                      /* value already inspected */
                               
            if(numb_of_element > numb_of_element_prev)   /* if current inspected value appears more offen, then update values */
            {
                numb_of_element_prev  = numb_of_element;
                mode_index = j;
            }                
        }
        else
        {
            /* continue */
        }
    }
    
    delete is_val_computed;      /* free dynamic allocated array */
    
    return (values[mode_index]); /* return mode */
}

int main(void)
{
    const int size_array = 22;
    
    /* array with int values */
    int array_i[size_array] = {88,25,26,1,0,11,33,5,25,5,6,100,33,21,0,88,22,21,33,21,88,99};
    int val_i = mode<int>(&array_i[0], size_array);
    printf("\n Mode %d \n\n", val_i);
 
 
 /* !!!!!!!!!!!!!!!!!!!!!!!!!! Uncomment following to see compilation error !!!!!!!!!!!!!!!!!!!!!!!!!! */
 #if 0 
    /* array with double values */
    double array_d[size_array] = {88.2,25.2,26.1,1,0.0,11.6,33,5,25.2,5.3,6.3,100,33,21.2,0,88.2,22,21,33,21,88.2,99};
    double val_d = mode<double>(&array_d[0], size_array);
    printf("\n Mode %f \n\n", val_d);
 #endif  
    return 0;
}
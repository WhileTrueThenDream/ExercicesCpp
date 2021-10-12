/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
*******************************************************
* Exercice 6-1.
* The mode of a series of values is the value that appears
* most commonly. Implemenmt a mode function using the following
* signature:
* int mode(const int* values, size_t length).
* If you encounter an error condition,such as input having multiple 
* modes and no values, return zero.
     
* \date last change: 12.10.2021
* \author            amaia
*/

#include <cstdio>

int mode(const int* values, size_t length)
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
            printf("value %d; index(es): %d ", values[j], j);
                
            for(int i = (j + 1) ; i < length; i++)       /* look for values equal to current one with index j */
            {
                if(values[i] == values[j])
                {
                    numb_of_element +=1;                 /* add one if you found another one equal to the one with index j */
                    is_val_computed[i] = 1;              /* mark value as inspected */
                    
                    printf("%d ", i);
                }
            }
            
            is_val_computed[j] = 1;                      /* value already inspected */
            
            printf("; matches: %d\n", numb_of_element);
                    
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
    int array[size_array] = {88,25,26,1,0,11,33,5,25,5,6,100,33,21,0,88,22,21,33,21,88,99};
    int val = mode(&array[0], size_array);
    printf("\n Mode %d \n\n", val);
    
}
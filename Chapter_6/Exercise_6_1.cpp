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
    int numb_of_element = 1;
    int *is_val_computed = new int[length]{0};  
    int mode_index = 0;
    int numb_of_element_prev = 0;

    for(int j = 0; j < length; j++)
    {
        if(is_val_computed[j] == 0)
        {
            numb_of_element = 0;
			printf("value %d; index(es): ", values[j]);
	            
            for(int i = j; i < length; i++)
            {
                if(values[i] == values[j])
                {
                    numb_of_element +=1;
                    is_val_computed[i] = 1;  /* computed value */
					
					printf("%d ", i);
                }
            }
            
            is_val_computed[j] = 1; 
			
            printf("; matches: %d\n", numb_of_element);
                    
            if(numb_of_element > numb_of_element_prev)
            {
                numb_of_element_prev  = numb_of_element;
                mode_index = j;
            }                
        }
        else
        {
            /* continue */;
        }
    }
    
    delete is_val_computed;
    
    return (values[mode_index]);
}

int main(void)
{
    const int size_array = 21;
    int array[size_array] = {88,25,26,1,0,11,33,5,25,5,6,100,33,21,0,88,22,21,33,21,88};
    int val = mode(&array[0], size_array);
    printf("\n Mode %d \n\n", val);
    
}
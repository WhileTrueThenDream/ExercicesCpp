/*******************************************************
 ** Exercises from book C++ Crash Cours by Lospinoso. **
 *******************************************************
 * Exercice 3-2.
 * Add a read_from and a write_to function to listing 3-6. 
 * These functions should read or write to upper or lower as appropriate. 
 * Perform bounds checking to prevent buffer overflows. 
 
 * \date last change: 22.09.2021
 * \author:            amaia
 */

#include <cstdio>
#include <cstring>

#define NUM_ITERATIONS 8   /**< Number of chars to write or be read. */

/*
 *   Reads a character in a given position in a given array.
  
 *   @param[in] ptr:  pointer to char array
 *   @param[in] pos:  position is char array to be read
 *   @param[out] ret: ret value, -1 if out of bounds. 
 
 */
static char read_from(char *ptr, int pos)
{
	char ret = -1; 
    if( (0 <= pos) && (pos < strlen(ptr))) /* check buffer limits */
	{
		ret = ptr[pos];                    /* return character in give index */
	}
	else
	{
		ret = -1;                         /* error, out of bounds. */
	}
	
	return ret;
}

/*
 * Write a character in a given position in a given array. 
 
 * @param[in] ptr:  pointer to char array
 * @param[in] pos:  position is char array to be written
 * @param[in] value:  char to be written in given position
 * @param[out] ret: ret value, -1 if out of bounds. 
 
 */
static char write_to(char *ptr, int pos, char value)
{
	char ret = -1; 
    if( (0 <= pos) && (pos < strlen(ptr)))  /* check buffer limits */
	{
		ptr[pos] = value;                   /* write value */
		ret = 0;                            /* success, return 0 */
	}
	else
	{
		ret = -1;                           /* error, out of bounds */
	}
	
	return ret;
}


int main(void) 
{
  char lower[] = "abc?e";   
  char upper[] = "ABC?E";
  char val;
  
  for(int i = 0; i < NUM_ITERATIONS; i++)     /* Test: read characters from lower array */
  {
    if ( 0 <= (val = read_from(&lower[0],i)))
	{
	  printf("lower = \"%s\" \t lower[%d]: %c \n\n", lower, i, val);	
	}
	else
	{
	  printf("lower[%d]: ERROR: out of bounds; Max index = %d  \n\n", i, ((int)strlen(lower)-1));	
	}
  }

  for(int i = 0; i < NUM_ITERATIONS; i++)   /* Test: write characters from upper array */
  {
	printf("Before: upper: %s \n", upper);
	if ( 0 == (val = write_to(&upper[0],i,'A' + i)))
	{
	  printf("write upper[%d] = %c \t", i, ('A' + i));	
	  printf("Now: upper: %s \n\n", upper);
	}
	else
	{
	  printf("upper[%d]: ERROR: out of bounds; Max index = %d  \n\n", i, ((int)strlen(upper)-1));
	}
  }

}

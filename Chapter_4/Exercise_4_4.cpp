/*******************************************************
 ** Exercises from book C++ Crash Course by Lospinoso. **
 *******************************************************
 * Exercice 4-4.
 * Implement a move constructor and a move assignment operator
 * for TimerClass. A moved-from TimerClass shouldnt print any output to
 * the console when it gets destructed.  
 
 * \date last change: 27.09.2021
 * \author            amaia
 */
 
#include <ctime>
#include <cstdio>
#include <unistd.h>
#include <utility>
 
struct TimerClass
{
    
    TimerClass(void)
    {
        timestamp =  std::time(0);        
    }
    
    TimerClass(const TimerClass& other)              /* Copy constructor */
    : timestamp {other.timestamp}
    {        
    }
        
    TimerClass& operator=(const TimerClass& other)   /* Copy assignment operator */
    {
        if(this == &other) 
        {
            /* do nothing */
        }
        else
        {
            this->timestamp = other.timestamp;
        }
         		 
        return *this;                
    }
	
    TimerClass(const TimerClass&& other)               /* Move constructor */
	: timestamp {other.timestamp}
	{
		printf("Move constructor invoked:       %ld \n", timestamp);
	}   

    TimerClass& operator=(const TimerClass&& other)    /* Move assignment operator*/
    {
        if(this == &other) 
        {
            /* do nothing */
        }
        else
        {
            this->timestamp = other.timestamp;
        }
		
        printf("Move assignment operator invoked: %ld \n", timestamp); 		 
        return *this;                
    }
	
    ~TimerClass(void)
    {
        time_t end_time = std::time(0);
        
        end_time =  std::time(0);  /* save current time*/  
        printf("destructor called \n");		
    }
     
    private:
    time_t timestamp;              /* timestamp of objects creation time */
};
 
int main(void)
{
    TimerClass myTimer;              
	TimerClass myTimer_2 = std::move(myTimer);  /*myTimer has to be converted to rvalue first*/
	TimerClass myTimer_3{std::move(myTimer_2)}; 
}
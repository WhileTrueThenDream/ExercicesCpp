/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
*******************************************************
* Exercice 4-4.
* Implement a copy constructor and a copy assignment operator for TimerClass.
* The copies should share timestamp values. 
* 
* for TimerClass. A moved-from TimerClass shouldnt print any output to
* the console when it gets destructed.  
     
* \date last change: 30.09.2021
* \author            amaia
*/
     

#include <utility>
#include <cstdio>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
     
struct TimerClass
{   
    TimerClass(void)
    {
        gettimeofday(&s_timestamp,0);                /* it returns an struct with seconds and milliseconds*/

		printf("Constructor invoked; timestamp: %lds; %ldms\n", s_timestamp.tv_sec, s_timestamp.tv_usec);
    }
     
      
    TimerClass(const TimerClass& other)              /* Copy constructor */
    : s_timestamp {other.s_timestamp}
    {    
        printf("Copy constructor invoked. timestamp: %lds; %ldms\n", s_timestamp.tv_sec, s_timestamp.tv_usec);  
    }
	
    TimerClass& operator=(const TimerClass& other)   /* Copy assignment operator */
    {
        if(this == &other) 
        {
            /* do nothing */
        }
        else
        {
            this->s_timestamp = other.s_timestamp;
        }
		
        printf("Copy assignment operator invoked. timestamp: %lds; %ldms\n", s_timestamp.tv_sec, s_timestamp.tv_usec);   		 
        return *this;                
    }
    		
    ~TimerClass(void)
    {
        timeval s_endtime, s_dif; 

        gettimeofday(&s_endtime,0);        
        timersub(&s_endtime ,&s_timestamp , &s_dif);
		
        printf("** Timer destructor invoked **\n");
		printf("Initial time: %lds; %ldms\n", s_timestamp.tv_sec, s_timestamp.tv_usec); 
		printf("End time:     %lds; %ldms\n", s_endtime.tv_sec, s_endtime.tv_usec); 
        printf("Elapsed time: %lds; %ldms\n\n", s_dif.tv_sec, s_dif.tv_usec);  			
    }

    private:
    timeval s_timestamp;           /* struct timeval with two fields, seconds and us*/
};
     
int main(void)
{
    TimerClass myTimer_1;	
    TimerClass myTimer_2;
    myTimer_2 =	myTimer_1;  

    TimerClass myTimer_4{myTimer_2};  	
		
	
	return 0;
}
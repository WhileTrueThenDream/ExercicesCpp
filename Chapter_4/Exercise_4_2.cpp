/*******************************************************
 ** Exercises from book C++ Crash Course by Lospinoso. **
 *******************************************************
 * Exercice 4-2.
 * In the destructor of TimerClass, record the current time and 
 * substract the time at construction. This time is roughly the age 
 * of the timer. Print that value. 
 
 * \date last change: 26.09.2021
 * \author            amaia
 
 * timersub(..)
 * https://man7.org/linux/man-pages/man3/timeradd.3.html
 */
 
#include <cstdio>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

struct TimerClass
{
    
    TimerClass(void)
    {
        gettimeofday(&s_timestamp,0);    /* it returns an struct with seconds and milliseconds*/
    }
    
 
    ~TimerClass(void)
    {
		timeval s_endtime, s_dif; 

        gettimeofday(&s_endtime,0);    /* it returns an struct with seconds and microsenconds*/        
		timersub(&s_endtime ,&s_timestamp , &s_dif);
		
        printf("Elapsed time:  %lds; %ldms\n", s_dif.tv_sec, s_dif.tv_usec);

        
    }
	
    private:
    timeval s_timestamp;           /* struct timeval with two fields, seconds and us*/
};
 
int main(void)
{
    TimerClass myTimer;           /* object myTimer is created */
    sleep(3);
}
    

     

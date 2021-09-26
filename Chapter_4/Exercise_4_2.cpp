/*******************************************************
 ** Exercises from book C++ Crash Course by Lospinoso. **
 *******************************************************
 * Exercice 4-2.
 * In the destructor of TimerClass, record the current time and 
 * substract the time at construction. This time is roughly the age 
 * of the timer. Print that value. 
 
 * \date last change: 26.09.2021
 * \author            amaia
 */
 
#include <ctime>
#include <cstdio>
#include <unistd.h>
 
struct TimerClass
{
    
    TimerClass(void)
    {
        timestamp =  std::time(0);  /* save current time*/
        
        printf("timestamp creation in saved format:    %ld \n", timestamp);
        printf("timestamp creation in readable format: %s \n",std::asctime(std::localtime(&(this->timestamp)))); /* print it in a human readable format*/        
    }
    
    
    ~TimerClass(void)
    {
        time_t end_time = std::time(0);
        
        end_time =  std::time(0);  /* save current time*/
        
        printf("timestamp destruction in saved format: %ld \n", end_time);
        printf("timestamp difference in seconds:       %ld \n",  end_time - (this->timestamp));
        
    }
     
    private:
    time_t timestamp;              /* timestamp of objects creation time */
};
 
int main(void)
{
    TimerClass myTimer;           /* object myTimer is created */
    sleep(5);                      /* wait some seconds before invoking destructor */
}
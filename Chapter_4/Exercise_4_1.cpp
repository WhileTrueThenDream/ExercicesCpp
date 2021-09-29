/*******************************************************
 ** Exercises from book C++ Crash Course by Lospinoso. **
 *******************************************************
 * Exercice 4-1.
 * Create a struct TimerClass. In its constructor, record the current time
 * in a field called timestamp (compare with the POSIX function gettimeofday).
 
 * \date last change: 25.09.2021
 * \author            amaia
 * 
 *  Read:
 *  time(...) . Time in seconds
 * https://man7.org/linux/man-pages/man2/time.2.html
 
 * gettimeofday(...); Time and seconds and milliseconds
 * https://man7.org/linux/man-pages/man2/settimeofday.2.html
 */
 
//#include <ctime>
#include <cstdio>
#include <sys/time.h>
#include <time.h>

struct TimerClass
{
    
    TimerClass(void)
    {
        timestamp =  time(0);       /* save current time, precission is only seconds!!*/
		gettimeofday(&s_timestamp,0);    /* it returns an struct with seconds and milliseconds*/
    }
    
    void PrintCreationTime(void)
    {
        printf("time returns:    %lu \n", timestamp);
        printf("gettimeofday(..) returns: %lu, %lu \n",s_timestamp.tv_sec, s_timestamp.tv_usec);
        printf("timestamp in readable format: %s \n",asctime(localtime(&(this->timestamp)))); /* print it in a human readable format*/
		
		
	}
     
    private:
    time_t timestamp;              /* timestamp in seconds of objects creation time */
	timeval s_timestamp;
};
 
int main(void)
{
    TimerClass myTimer;           /* object myTimer is created */
    myTimer.PrintCreationTime();  /* print time of object creation */
}
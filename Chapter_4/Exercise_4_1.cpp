/*******************************************************
 ** Exercises from book C++ Crash Course by Lospinoso. **
 *******************************************************
 * Exercice 4-1.
 * Create a struct TimerClass. In its constructor, record the current time
 * in a field called timestamp (compare with the POSIX function gettimeofday).
 
 * \date last change: 25.09.2021
 * \author            amaia
 */
 
#include <ctime>
#include <cstdio>
 
struct TimerClass
{
    
    TimerClass(void)
    {
        timestamp =  std::time(0);  /* save current time*/
    }
    
    void PrintCreationTime(void)
    {
        printf("timestamp in saved format:    %ld \n", timestamp);
        printf("timestamp in readable format: %s \n",std::asctime(std::localtime(&(this->timestamp)))); /* print it in a human readable format*/
    }
     
    private:
    time_t timestamp;              /* timestamp of objects creation time */
};
 
int main(void)
{
    TimerClass myTimer;           /* object myTimer is created */
    myTimer.PrintCreationTime();  /* print time of object creation */
}
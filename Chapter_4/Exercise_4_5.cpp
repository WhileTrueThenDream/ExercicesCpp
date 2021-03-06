/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
*******************************************************
* Exercice 4-5.
* Elaborate the TimerClass constructor to accept an additional const char* name paramter. 
* When TimerClass is destructed and prints to stdout, include the name of the timer in the output.
     
* \date last change: 28.09.2021
* \author            amaia
*/
     
#include <utility>
#include <cstdio>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <cstring>
     
struct TimerClass
{      
    TimerClass(const char* name)
    {
        gettimeofday(&s_timestamp,0);  
        strncpy(&timername[0], name, (sizeof(timername)-1));                         
    }

    TimerClass(const TimerClass& other)              /* Copy constructor */
    : s_timestamp {other.s_timestamp}
      
    {    
        strncpy(&timername[0], other.timername, (sizeof(timername)-1));   
    }
    
    TimerClass& operator=(const TimerClass& other)   /* Copy assignment operator */
    {
        if(this == &other) 
        {
            /* do nothing */
        }
        else
        {
            strncpy(&timername[0], other.timername, (sizeof(timername)-1)); 
            this->s_timestamp = other.s_timestamp;
        }
                    
        return *this;                
    }

    TimerClass(const TimerClass&& other)               /* Move constructor */
    : s_timestamp {other.s_timestamp},
      moved_from{true}
    {
        strncpy(&timername[0], other.timername, (sizeof(timername)-1));
    }   
    
    TimerClass& operator=(const TimerClass&& other)    /* Move assignment operator*/
    {
        if(this == &other) 
        {
            /* do nothing */
        }
        else
        {
            this->moved_from  = true;            
            this->s_timestamp   = other.s_timestamp;
            strncpy(&timername[0], timername, (sizeof(timername)-1));
        }
        
        return *this;                
    }
    
    ~TimerClass(void)
    {
        timeval s_endtime, s_dif; 

        gettimeofday(&s_endtime,0);        
        timersub(&s_endtime ,&s_timestamp , &s_dif);
        
        printf("Timer: %s Init: %lds; %ldms;\t End: %lds; %ldms;\n",&timername[0], s_timestamp.tv_sec, s_timestamp.tv_usec,s_endtime.tv_sec,s_endtime.tv_usec);
        printf("       >> diff: %lds; %ldms;\n", s_dif.tv_sec, s_dif.tv_usec);      
        if(moved_from) printf("This timer was moved-from !!! \n\n");
    }
         
    private:
        timeval s_timestamp;           /* struct timeval with two fields, seconds and us */
        char timername[10];            /* timers name, 9 chars length max. */
        bool moved_from = false;       /* true if you were moved from, false if not */
};
     
int main(void)
{
    TimerClass Timer_1{"Timer_1"};  
    TimerClass Timer_2{Timer_1};     
    TimerClass Timer_3{std::move(Timer_2)}; 

    return 0;    
}

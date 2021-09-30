/*******************************************************
** Exercises from book C++ Crash Course by Lospinoso. **
*******************************************************
* Exercice 4-4.
* Implement a move constructor and a move assignment operator
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
        moved_from = false;
        printf("Constructor invoked. \n");
    }
     
      
    TimerClass(const TimerClass& other)              /* Copy constructor */
    : s_timestamp {other.s_timestamp},
      moved_from{false}
    {    
        printf("Copy constructor invoked. \n");    
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
            this->moved_from  = false;
        }
                
        printf("Copy assignment operator invoked. \n");                      
        return *this;                
    }
            
    TimerClass(const TimerClass&& other)               /* Move constructor */
    : s_timestamp {other.s_timestamp},
      moved_from{true}
    {
        printf("Move constructor invoked. \n");
    }   
    
    TimerClass& operator=(const TimerClass&& other)    /* Move assignment operator*/
    {
        if(this == &other) 
        {
            /* do nothing */
        }
        else
        {
            this->s_timestamp   = other.s_timestamp;
            this->moved_from  = true;
        }
                
        printf("Move assignment operator invoked. \n");
                
        return *this;                
    }
        
    ~TimerClass(void)
    {
        if(moved_from == false)          
        {
            timeval s_endtime, s_dif; 

            gettimeofday(&s_endtime,0);        
            timersub(&s_endtime ,&s_timestamp , &s_dif);
        
            printf("\nElapsed time:  %lds; %ldms\n", s_dif.tv_sec, s_dif.tv_usec);                          
        }
        else
        {
            /* Do nothing if you were moved from. */                        
        }
    }

    private:
      timeval s_timestamp;           /* struct timeval with two fields, seconds and us*/
      bool moved_from;               /* true if you were moved from, false if not */
};
     
int main(void)
{
    printf("code:\t TimerClass myTimer_1; \n");    
    TimerClass myTimer_1;
        
    printf("\ncode:\n\t TimerClass myTimer_2;\n\t myTimer_2 = myTimer_1; \n");        
    TimerClass myTimer_2;
    myTimer_2 =        myTimer_1;  

    printf("\ncode:\t TimerClass myTimer_3 = myTimer_1; \n");        
    TimerClass myTimer_3 = myTimer_1;
        
    printf("\ncode:\t TimerClass myTimer_4{myTimer_2}; \n");        
    TimerClass myTimer_4{myTimer_2};          
        
    printf("\ncode:\n\tTimerClass myTimer_5;\n\t myTimer_5 = std::move(myTimer_1);  \n");        
    TimerClass myTimer_5;
    myTimer_5 = std::move(myTimer_1);        

    printf("\ncode:\n\t TimerClass myTimer_6;\n\t myTimer_6 = std::move(myTimer_2);  \n");        
    TimerClass myTimer_6 = std::move(myTimer_2);        
        
    printf("\ncode:\t TimerClass myTimer_7{std::move(myTimer_3)}; \n");                
    TimerClass myTimer_7{std::move(myTimer_3)}; 
                
        
    return 0;
}

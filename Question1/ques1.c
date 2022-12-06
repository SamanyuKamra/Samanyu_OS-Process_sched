#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int priority1 = 0;
int priority2 = 1;
int priority3 = 1;
void* CountA()
{
        struct sched_param *s;
        struct timespec a1;
        s = (struct sched_param*)malloc(sizeof(struct sched_param));
        
        s->sched_priority = priority1;
        pthread_setschedparam(pthread_self(),SCHED_OTHER,s);
        clock_gettime(CLOCK_REALTIME,&a1);
        nice(0);
        long long ThrA = pow(2,32);
        for(long long i = 0; i<ThrA; i++)
        {
            if(priority1)
            {
                continue;
            }
        }
        struct timespec a2;
        clock_gettime(CLOCK_REALTIME,&a2);
        printf("CountA = %f\n",(a2.tv_sec - a1.tv_sec)+(a2.tv_nsec - a1.tv_nsec)/1e9);
        
        return NULL;


}

void* CountB()
{
    struct sched_param *s;
        struct timespec b1;
        s = (struct sched_param*)malloc(sizeof(struct sched_param));
        
        s->sched_priority = priority2;
        pthread_setschedparam(pthread_self(),SCHED_RR,s);
        struct timespec b2;
        clock_gettime(CLOCK_REALTIME,&b1);
        
        long long ThrB = pow(2,32);
        for(long long j = 0; j<ThrB; j++){

        
            if(priority2)
            {
                continue;
            }
        }
        clock_gettime(CLOCK_REALTIME,&b2);
        printf("CountB = %f\n",(b2.tv_sec - b1.tv_sec)+(b2.tv_nsec - b1.tv_nsec)/1e9);
    
        return NULL;

}

void* CountC()
{
    struct sched_param *s;
        struct timespec c1;
        s = (struct sched_param*)malloc(sizeof(struct sched_param));
        
        s->sched_priority = priority3;
        pthread_setschedparam(pthread_self(),SCHED_FIFO,s);
        struct timespec c2;
        clock_gettime(CLOCK_REALTIME,&c1);
        
        long long ThrC = pow(2,32);
        for(long long k = 0; k<ThrC; k++){

        
            if(priority3)
            {
                continue;
            }
        }
        clock_gettime(CLOCK_REALTIME,&c2);
        printf("CountC = %f\n",(c2.tv_sec - c1.tv_sec)+(c2.tv_nsec - c1.tv_nsec)/1e9);
    
        return NULL;



}
int main()
{
    pthread_t A;
    pthread_t B;
    pthread_t C;
    pthread_create(&A , NULL , &CountA, NULL);
    pthread_create(&B, NULL , &CountB , NULL);
    pthread_create(&C, NULL , &CountC , NULL);
    pthread_join(A,NULL);
    pthread_join(B,NULL);
    pthread_join(C,NULL);

    return 0;


}

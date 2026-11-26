#ifndef ORA_H
#define ORA_H
#define CLOCK_MONOTONIC 1
#define CLOCK_REALTIME 0
#define SEC true
#define NSEC false
#define ONE_SEC 286000000
#define ONE_NSEC 1000000000
struct timespec{
    unsigned long long tv_sec;
    unsigned long long tv_nsec;
};
inline unsigned long long gettime(unsigned long long cid, timespec* t){
    register unsigned long long x0 asm("x0") = cid;
    register timespec* x1 asm("x1") = t;
    register unsigned long long x8 asm("x8") = 113;
    asm volatile(
        "svc #0"
        : "+r"(x0)
        : "r"(x1), "r"(x8)
        : "memory"
    );
    return x0;
}
inline long long elapse(bool time,int persec){
    timespec start,end;
    gettime(CLOCK_MONOTONIC,&start);
    for(int i=0;i<persec;i++){}
    gettime(CLOCK_MONOTONIC,&end);
    long long sec,nsec,res;
    sec=end.tv_sec-start.tv_sec;
    nsec=end.tv_nsec-start.tv_nsec;
    if(nsec<0){
        sec--;
        nsec+=ONE_NSEC;
    }
    if(time){
        res=sec;
    }else{
        res=nsec;
    }
    return res;
}
#endif
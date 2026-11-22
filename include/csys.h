#ifndef CSYS_H
#define CSYS_H

inline void execve(const char* buf){
    char arg[100];
    int count=0;
    while(buf[count+5]!='\0'&&count<99){
        arg[count]=buf[count+5];
        count++;
    }
    arg[count]='\0';
    count=0;
    char cmd[100];
    while(buf[count]!=' '&&count<99){
        cmd[count]=buf[count];
        count++;
    }
    cmd[count]='\0';
    count=0;
    char path[100]="/bin/";
    while(cmd[count]!='\0'){
        path[count+5]=cmd[count];
        count++;
    }
    path[count+5]='\0';
    count=0;
    
    const char* argv[]={path,arg,nullptr};
    const char* envp[]={"PATH=/bin:/usr/bin",nullptr};
    asm volatile(
        "mov x0,%0\n\t"
        "mov x1,%1\n\t"
        "mov x2,%2\n\t"
        "mov x8,#221\n\t"
        "svc #0\n\t"
        :
        :"r"(path),"r"(argv),"r"(envp)
        :"x0","x1","x2","x8","memory"
    );
}

inline char* getcwd_(char* buf,unsigned long size){
    long ret;
    asm volatile(
        "mov x0,%1\n\t"
        "mov x1,%2\n\t"
        "mov x8,#17\n\t"
        "svc #0\n\t"
        :"=&r"(ret)
        :"r"(buf),"r"(size)
        :"x0","x1","x8","memory"
    );
    if(ret<0)return nullptr;
    return buf;
}
inline char* getcwd(){
    char buf[256];
    unsigned long size=sizeof(buf)/sizeof(buf[0]);
    char* ret=getcwd_(buf,size);
    return ret;
}

inline void chdir(const char* buf){
    asm volatile(
        "mov x0,%0\n\t"
        "mov x8,#49\n\t"
        "svc #0"
        :
        :"r"(buf)
        :"x0","x8","memory"
    );
}
#endif
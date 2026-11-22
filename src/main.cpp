#include<csys.h>
#include<wori>
#include<dttool>
//flags
#define 0_RDONLY 0
#define 0_WRONLY 1
#define 0_RDWR 2
void openat(int dfd,const char* filename,int flags,unsigned int mode){
    
}


void installAll(){
    char include[]="include";
    chdir(include);
    char* pwd=getcwd();
    execve("ls .");newL;
}

int main(int argc,char** argv){
    if(argc==1){
        installAll();
    }
    return 0;
}
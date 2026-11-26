#ifndef CSTR_H
#define CSTR_H
#include<dttool.h>

struct cstr{
private:
    char* text;
    unsigned int size;
public:
    cstr(const char* buf){
        size=length(buf);
        text=new char[size+1];
        
        for(int i=0;i<=size;i++){
            text[i]=buf[i];
        }
    }
    
    cstr(){
        size=0;
        text=new char[1];
        text[0]='\0';
    }
    
    cstr(cstr&& buf){
        size=buf.size;
        text=buf.text;
        buf.text=nullptr;
        buf.size=0;
    }
    //cstr a=cstr b;
    cstr(const cstr& buf){
        size=length(buf);
        text=new char[size+1];
        
        for(int i=0;i<=size;i++){
            text[i]=buf[i];
        }
    }
    
    operator const char*() const{
            return text?text:"";
    }
    
    //get value by index
    char& operator[](unsigned int index){
        //if(index>=size)return '\0';
        return text[index];
    }
    
    //equality
    bool operator==(const char* buf)const{
        if(size!=length(buf))return false;
        for(int i=0;i<size;i++){
            if(text[i]!=buf[i])return false;
        }
        return true;
    }
    
    //inequality
    bool operator!=(const char* buf)const{
        if(size!=length(buf))return true;
        for(int i=0;i<size;i++){
            if(text[i]!=buf[i])return true;
        }
        return false;
    }
    
    //non modifying concat
    //cstr+const char*
    cstr operator+(const char* buf)const{
        cstr result=text;
        result+=buf;
        return result;
    }
    
    //cstr+cstr
    cstr operator+(const cstr& buf)const{
        cstr result=text;
        result+=buf;
        return result;
    }
    
    //a=b
    cstr& operator=(const cstr& buf){
        if(this == &buf) return *this;
        unsigned bufsize=length(buf);
        delete[] text;
        text=new char[bufsize+1];
        for(int i=0;i<=bufsize;i++){
            text[i]=buf[i];
        }
        size=bufsize;
        return *this;
    }
    
    //a=const char*
    cstr& operator=(const char* buf){
        unsigned bufsize=length(buf);
        delete[] text;
        text=new char[bufsize+1];
        for(int i=0;i<=bufsize;i++){
            text[i]=buf[i];
        }
        size=bufsize;
        return *this;
    }
    
    cstr& operator=(cstr&& buf){
        if(this==&buf)return *this;
        delete[] text;
        text=buf.text;
        size=buf.size;
        buf.text=nullptr;
        buf.size=0;
        return *this;
    }
        
    //concat
    cstr& operator+=(const char* buf){
        unsigned int bufsize=length(buf);
        char* tmp=text;
        text=new char[size+bufsize+1];
        //text=hello.....\0
        //buf=world
        //size=10,bs=5
        for(int i=0;i<size;i++){
            text[i]=tmp[i];
        }
        for(int i=0;i<bufsize;i++){
            text[size+i]=buf[i];
        }
        text[size+bufsize]='\0';
        size+=bufsize;
        delete[] tmp;
        return *this;
    }
    
    void clear(){
        delete[] text;
        size=0;
        text=new char[1];
        text[0]='\0';
    }
    
    bool empty(){
        return size==0;
    }
    
    unsigned int capacity(){
        return size;
    }
    
    ~cstr(){
        delete[] text;
        size=0;
    }
};

//non modifying concat
//const char* + cstr
cstr operator+(const char* lhs,const cstr& rhs){
    cstr result=lhs;
    result+=rhs;
    return result;
}

#endif
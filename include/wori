#pragma once
#include<type_traits>
#include<adclib>

#define newL ass_out("\n",1)
#define clr ass_out("\033[2J\033[H",11)

inline long ass_in(char* buf,unsigned long len);
inline void ass_out(const char* buf,unsigned long len);

template<typename T>
inline void wrout(const T& input){
    using U=std::decay_t<T>;
    if constexpr(std::is_convertible_v<T,const char*>){
        const char* text=input;
        long length=0;
        while(text[length]!='\0'){
            length++;
        }
        ass_out(text,length);
    }else
    if constexpr(std::is_arithmetic_v<U>){
        long length;
        char buffer[128];
        if constexpr(std::is_same_v<U,bool>){
            length=bool_char(input,buffer);
        }else
        if constexpr(std::is_floating_point_v<U>){
            length=float_char(input,buffer,5);
        }else
        if constexpr(std::is_same_v<U,char>){
            length=1;
            buffer[0]=input;
        }else{
            length=int_char(input,buffer);
        }
        ass_out(buffer,length);
    }
}

template<typename C>
inline C rin(){
    using U=std::decay_t<C>;
    C resultA;
    U resultB;
    static char buffer[4096];
    int count=0;
    while(count<sizeof(buffer)-1){
        char c;
        long byte=ass_in(&c,1);
        if(byte<=0||c=='\n'){
            buffer[count]='\0';
            break;
        }
        buffer[count++]=c;
    }
    if constexpr(std::is_arithmetic_v<U>){
        if constexpr(std::is_same_v<U,bool>){
            char_bool(buffer,&resultB);
            return resultB;
        }else
        if constexpr(std::is_floating_point_v<U>){
            char_float(buffer,&resultB);
            return resultB;
        }else
        if constexpr(std::is_same_v<U,char>){
            return buffer[0];
        }else{
            char_int(buffer,&resultB);
            return resultB;
        }
    }else
    if constexpr(std::is_convertible_v<C,const char*>){
        const char* text=buffer;
        return text;
    }
    return resultA;
}

long ass_in(char* buf,unsigned long len){
    long result;
    asm volatile(
        "mov x0,#0\n\t"
        "mov x1,%1\n\t"
        "mov x2,%2\n\t"
        "mov x8,#63\n\t"
        "svc #0\n"
        :"=r"(result)
        :"r"(buf),"r"(len)
        :"x0","x1","x2","x8","memory"
    );
    return result;
}

inline void ass_out(const char* buf,unsigned long len){
    asm volatile(
      "mov x0,#1\n\t"
      "mov x1,%0\n\t"
      "mov x2,%1\n\t"
      "mov x8,#64\n\t"
      "svc #0\n"
      :
      :"r"(buf),"r"(len)
      :"x0","x1","x2","x8","memory"
    );
}
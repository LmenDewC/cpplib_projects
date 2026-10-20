#pragma once
#include<unistd.h>
#include<type_traits>
#include<adclib.hpp>

template<typename T>
inline void wrout(const T& input){
    using U=std::decay_t<T>;
    if constexpr(std::is_convertible_v<T,const char*>){
        const char* text=input;
        ssize_t length=0;
        while(text[length]!='\0'){
            length++;
        }
        write(STDOUT_FILENO,text,length);
    }else
    if constexpr(std::is_arithmetic_v<U>){
        ssize_t length;
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
        write(STDOUT_FILENO,buffer,length);
    }
}
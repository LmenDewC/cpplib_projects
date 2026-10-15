#pragma once
#include <unistd.h>
#include <type_traits>
#include <string.h>
#include <cstdio>
#include<cstdlib>

template<typename T>
void wrout(const T& input){
    using U = std::decay_t<T>;

    if constexpr(std::is_convertible_v<T, const char*>){
        const char* text = input;
        ssize_t length = 0;

        while(text[length] != '\0'){
            length++;
        }

        write(STDOUT_FILENO, text, length);
    }
    else if constexpr(std::is_arithmetic_v<U>){
        char buffer[128];
        int length;

        if constexpr(std::is_same_v<U, bool>){
            const char* text = input ? "true" : "false";
            length = snprintf(buffer, sizeof(buffer), "%s", text);
        }
        else if constexpr(std::is_floating_point_v<U>){
            length = snprintf(buffer, sizeof(buffer), "%g",
                              static_cast<double>(input));
        }
        else{
            length = snprintf(buffer, sizeof(buffer), "%lld",
                              static_cast<long long>(input));
        }

        if(length > 0){
            ssize_t count = length < sizeof(buffer)
                ? length : sizeof(buffer) - 1;
            write(STDOUT_FILENO, buffer, count);
        }
    }
}

void newL(){
    write(STDOUT_FILENO,"\n",1);
}

template<typename scan>
scan rin(){
    scan input;
    using U=std::decay_t<scan>;
    if constexpr(std::is_convertible_v<scan,const char*>){
        static char buffer[4096];
        ssize_t length=0;
        while(length<=sizeof(buffer)-1){
            char c;
            ssize_t byte=read(STDIN_FILENO,&c,1);
            if(byte<=0||c=='\n'){
                buffer[length]='\0';
                return buffer;
            }
            buffer[length++]=c;
        }
    }else
    if constexpr(std::is_arithmetic_v<U>){
        if constexpr(std::is_same_v<U,bool>){
            static char buffer[4096];
            ssize_t length=0;
            while(length<=sizeof(buffer)-1){
                char c;
                ssize_t byte=read(STDIN_FILENO,&c,1);
                if(byte<=0||c=='\n'){
                    buffer[length]='\0';
                    if(strcmp(buffer,"true")==0||strcmp(buffer,"1")==0){
                        return true;
                    }else
                    if(strcmp(buffer,"false")==0||strcmp(buffer,"0")==0){
                        return false;
                    }else{
                        break;
                    }
                }
                buffer[length++]=c;
            }
        }else
        if constexpr(std::is_floating_point_v<U>){
            static char buffer[4096];
            ssize_t length=0;
            while(length<=sizeof(buffer)-1){
                char c;
                ssize_t byte=read(STDIN_FILENO,&c,1);
                if(byte<=0||c=='\n'){
                    buffer[length]='\0';
                    if constexpr(std::is_same_v<U,float>){
                        return static_cast<float>(strtof(buffer,nullptr));
                    }else
                    if constexpr(std::is_same_v<U,double>){
                        return static_cast<double>(strtod(buffer,nullptr));
                    }else
                    if constexpr(std::is_same_v<U,long double>){
                        return static_cast<long double>(strtold(buffer,nullptr));
                    }else {
                        break;
                    }
                }
                buffer[length++]=c;
            }
        }else{
            static char buffer[4096];
            ssize_t length=0;
            while(length<sizeof(buffer)-1){
                char c;
                ssize_t byte=read(STDIN_FILENO,&c,1);
                if(byte<=0||c=='\n'){
                    buffer[length]='\0';
                    int num=atoi(buffer);
                    return num;
                }
                buffer[length++]=c;
            }
        }
    }
    return input;
}

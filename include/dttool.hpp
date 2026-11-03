#pragma once
#include<cmath.hpp>
#include<type_traits>

template<typename dtl>
inline int length(const dtl& input){
    using U=std::decay_t<dtl>;
    int count=0;
    if constexpr(std::is_convertible_v<dtl,const char*>){
        while(input[count]!='\0'){
            count++;
        }
    }else
    if constexpr(std::is_arithmetic_v<U>){
        U tmp=input;
        if constexpr(std::is_same_v<U,bool>){
            //
        }else
        if constexpr(std::is_floating_point_v<U>){
            //
        }else
        if constexpr(std::is_same_v<U,char>){
            count++;
        }else{
            if(tmp==0){
                return count;
            }
            while(tmp!=0){
                tmp/=10;
                count++;
            }
        }
    }
    return count;
}
inline bool cchar_cmpr(const char* csl1,const char* csl2){
    bool result;
    if(length(csl1)==length(csl2)){
        for(int i=0;i<sizeof(csl1);i++){
            if(csl1[i]==csl2[i]){
                result=true;
                continue;
            }else{
                result=false;
                break;
            }
        }
    }else{
        result=false;
    }
    return result;
}
#ifndef DTTOOL_H
#define DTTOOL_H
#include<cmath.h>
#include<type_shit>

template<typename dtl>
inline int length(const dtl& input){
    using U=ts::decay_t<dtl>;
    int count=0;
    if constexpr(ts::is_conv<dtl,const char*>{}){
        while(input[count]!='\0'){
            count++;
        }
    }else
    if constexpr(ts::is_arithmetic<U>{}){
        U tmp=input;
        if constexpr(ts::is_same<U,bool>{}){
            const char* text=input?"true":"false";
            while(text[count]!='\0'){
                count++;
            }
            return count;
        }else
        if constexpr(ts::is_floating_pnt<U>{}){
            //
        }else
        if constexpr(ts::is_same<U,char>{}){
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
#endif
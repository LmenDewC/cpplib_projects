#pragma once
#include<dttool>
inline int char_int(const char* input,int* output){
    int sign=1;
    int pos=0;
    *output=0;
    if(input[pos]=='-'){
        sign=-1;
        pos++;
    }
    while(input[pos]!='\0'){
        int digit=input[pos]-'0';
        *output=*output*10+digit;
        pos++;
    }
    *output=*output*sign;
    return pos;
}

inline int int_char(int input,char* output){
    int pos=0;
    int start=0;
    if(input==0){
        output[pos++]='0';
    }else
    if(input<0){
        output[pos++]='-';
        input=input*-1;
        start=1;
    }
    while(input!=0){
        int digit=input%10;
        output[pos]='0'+digit;
        input/=10;
        pos++;
    }
    output[pos]='\0';
    for(int i=start;i<(pos+start)/2;i++){
    char temp=output[i];
    output[i]=output[pos-1-i+start];
    output[pos-1-i+start]=temp;
    }
    return pos;
}

inline int bool_char(bool input,char* output){
    const char* text=input?"true":"false";
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }
    for (int i = 0; i <= length; i++) {
        output[i] = text[i];
    }
    return length;
}

inline int float_char(double input, char* output, int precision){
    int pos=0;
    if(input<0){
        output[pos++]='-';
        input=-input;
    }
    long long whole=(long long)input;
    double decimal=input-whole;
    if(whole==0){
        output[pos++]='0';
    }else{
        int start = pos;
        while(whole!=0){
            output[pos++]='0'+(whole % 10);
            whole/=10;
        }
        for(int i=start,j=pos-1;i<j;i++,j--){
            char temp=output[i];
            output[i]=output[j];
            output[j]=temp;
        }
    }
    if(precision>0){
        output[pos++]='.';
        for(int i=0;i<precision;i++){
            decimal*=10;
            int digit=(int)decimal;
            output[pos++]='0'+digit;
            decimal-=digit;
        }
    }
    output[pos]='\0';
    return pos;
}

inline int char_bool(const char* input,bool* output){
    int length;
    if(cchar_cmpr(input,"true")||cchar_cmpr(input,"1")){
        *output=true;
        length=4;
    }else
    if(cchar_cmpr(input,"false")||cchar_cmpr(input,"0")){
        *output=false;
        length=5;
    }else{
        length=0;
    }
    return length;
}

inline int char_float(const char* input,float* output){
    static char wholeChar[128],decimalChar[128];
    int pos=0;
    int wcount=0;
    int dcount=0;
    int sign=1;
    if(input[pos]=='-'){
        sign=-1;
        pos++;
    }else if(input[pos]=='+'){
        pos++;
    }
    while(input[pos]!='\0'&&input[pos]!='.'){
        if(wcount>=127)return -1;
        wholeChar[wcount++]=input[pos++];
    }
    wholeChar[wcount]='\0';
    if(input[pos]=='.'){
        pos++;
        while(input[pos]!='\0'){
            if(dcount>=127)return -1;
            decimalChar[dcount++]=input[pos++];
        }
    }
    decimalChar[dcount] = '\0';

    if(wcount==0&&dcount==0) return -1;
    int wholeInt=0;
    int decimalInt=0;
    if(wcount>0){
        if(char_int(wholeChar,&wholeInt)<=0)
            return -1;
    }
    int n=0;
    if(dcount>0){
        n=char_int(decimalChar,&decimalInt);
        if(n!=dcount)return -1;
    }
    int x = 1;
    for(int i=0;i<dcount;i++){
        x*=10;
    }
    float result=(float)wholeInt;
    if(dcount>0){
        result+=(float)decimalInt/x;
    }
    *output=result*sign;
    return pos;
}


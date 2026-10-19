#pragma once
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
    int pos = 0;

    if(input < 0){
        output[pos++] = '-';
        input = -input;
    }

    long long whole = (long long)input;
    double decimal = input - whole;

    // Convert whole part
    if(whole == 0){
        output[pos++] = '0';
    }else{
        int start = pos;

        while(whole != 0){
            output[pos++] = '0' + (whole % 10);
            whole /= 10;
        }

        for(int i = start, j = pos - 1; i < j; i++, j--){
            char temp = output[i];
            output[i] = output[j];
            output[j] = temp;
        }
    }

    if(precision > 0){
        output[pos++] = '.';

        for(int i = 0; i < precision; i++){
            decimal *= 10;
            int digit = (int)decimal;

            output[pos++] = '0' + digit;
            decimal -= digit;
        }
    }

    output[pos] = '\0';
    return pos;
}

inline bool char_cmpr(const char* csl1,const char* csl2){
    bool result;
    if(sizeof(csl1)==sizeof(csl2)){
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
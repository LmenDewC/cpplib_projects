#pragma once
inline int char_int(const char* input){
    int buffer=0;
    int sign=-1;
    int pos=0;
    if(input[pos]=='-'){
        sign=-1;
        pos++;
    }
    while(input[pos]!='\0'){
        int digit=input[pos]-'0';
        buffer=buffer*10+digit;
        pos++;
    }
    return buffer;
}

inline char* int_char(int input){
    static char buffer[100];
    int pos=0;
    if(input==0){
        buffer[pos++]='0';
    }
    while(input!=0){
        int digit=input%10;
        buffer[pos]='0'+digit;
        input/=10;
        pos++;
    }
    buffer[pos]='\0';
    for(int i = 0; i < pos / 2; i++){
    char temp = buffer[i];
    buffer[i] = buffer[pos - 1 - i];
    buffer[pos - 1 - i] = temp;
    }
    return buffer;
}
inline int bool_char_d(bool input,char* output){
    const char* text;
    if(input){
        text="true";
    }else{
        text="false";
    }
    int length = 0;
    while (text[length] != '\0') {
        length++;
    }
    for (int i = 0; i <= sizeof(text); i++) {
        output[i] = text[i];
    }
    return length;
}

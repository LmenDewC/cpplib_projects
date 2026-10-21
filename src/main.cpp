#include<wori.hpp>
#include<dtcmpr.hpp>
#include<iostream>
int char_float(const char* input,float* output){
    static char whole[128],decimal[128];
    int point;
    int count=0;
    while(count<=cchar_length(input)-1){
        if(input[count]=='.'){
            whole[count]='\0';
            point=count+1;     
            count++;
            for(int i=0;i<cchar_length(input);i++){
                decimal[i]=input[count];
                count++;
            }
            decimal[count]='\0';
            break;
        }
        whole[count]=input[count];
        count++;
    }

    int wholeN;
    int decimalN;
    char_int(whole,&wholeN);
    char_int(decimal,&decimalN);
    return decimalN;
}

int main(){
    char input[]="1";
    int output;
    char_int(input,&output);
    std::cout<<output<<'\n';
}

#pragma once
inline int expon(int x,int n){
    int multiplier=0;
    for(int i=0;i<n;i++){
        multiplier*=x;
    }
    return multiplier;
}
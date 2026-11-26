#ifndef CMATH_H
#define CMATH_H
inline int expon(int x,int n){
    int result;
    asm volatile(
        "mov w1,#0\n\t"
        "mov %w0,#1\n\t"
        "mov w3,%w1\n\t"
        "mov w4,%w2\n\t"
        "lp:\n\t"
        "cmp w1,w4\n\t"
        "b.eq end\n\t"
        "mul %w0,%w0,w3\n\t"
        "add w1,w1,#1\n\t"
        "b lp\n\t"
        "end:\n\t"
        :"=&r"(result)
        :"r"(x),"r"(n)
        :"w0","w1","w2","w3","w4","memory"
    );
    return result;
}

inline int factorial(int x){
    int result;
    asm volatile(
        "mov %w0,#1\n\t"//result
        "mov w1,#1\n\t"//i
        "add %w1,%w1,#1\n\t"
        "lp:\n\t"
        "cmp w1,%w1\n\t"//if i==x
        "b.eq end\n\t"
        "mul %w0,%w0,w1\n\t"
        "add w1,w1,#1\n\t"
        "b lp\n\t"
        "end:\n\t"
        :"=&r"(result)
        :"r"(x)
        :"w1","cc"
    );
    return result;
}
inline int gcf(int a,int b){
    int result;
    asm volatile(
        "lp:\n\t"
        "cmp %w2,#0\n\t"
        "b.eq break\n\t"
        "mov w5,%w2\n\t"
        "udiv w3,%w1,%w2\n\t"
        "msub w4,w3,%w2,%w1\n\t"
        "mov %w2,w4\n\t"
        "mov %w1,w5\n\t"
        "b lp\n\t"
        "break:\n\t"
        "mov %w0,%w1\n\t"
        :"=&r"(result)
        :"r"(a),"r"(b)
        :"w3","w4","w5","cc"
    );
    return result;
}
#endif
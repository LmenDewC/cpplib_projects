.global _start
.section .text
_start:
    mov w2, #1
    mov w3, #0

loop:
    cmp w3, w1
    b.ge end

    mul w2, w2, w0
    add w3, w3, #1

    b loop

end:
    
    inline int expon(int x,int n){
    int result;
    asm volatile(
        "mov w0,%w2\n\t"
        "mov w1,%w1\n\t"
        "mov w2,#1\n\t"
        "mov w3,#0\n\t"
        
        "loop:\n\t"
        "cmp w3,w1\n\t"
        "b.ge end\n\t"
        "mul w2,w2,w0\n\t"
        "add w3,w3,#1\n\t"
        "b loop\n\t"
        
        "end:\n\t"
        "mov %w0,w2\n\t"
        :"=&r"(result)
        :"r"(n),"r"(x)
        :"w0","w1","w2","w3","cc","memory"
    );
    return result;
}
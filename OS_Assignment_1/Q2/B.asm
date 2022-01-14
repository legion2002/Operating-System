    global B
    
section .text
extern C

 B: 
    
    
    mov [number], rdi
   ;Prints the message that B function has started
    mov rax, 1                
    mov rdi, 1                  
    mov rsi, message            
    mov rdx, 27            
    syscall 
    ;Prints the number as an ASCII 
    mov rax, 1
    mov rdi, 1
    mov rsi, number
    mov rdx, 8
    syscall
    pop r9
    push C    
    ret

        section   .data
message:  db        "You are now in B function ", 10

        section .bss
number resb 8



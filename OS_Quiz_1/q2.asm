global func

segment .text
extern printf

fmt:
        db  "%llx", 10, 0 ;This specifies a hexadecimal format for the printf

func:
    

push rsi
push rax
mov rdi, 0x0 
mov rsi, rdi  

push rdi
  mov rdi, fmt             ;we move the format into rdi ( according to printf convention ) 
                 ;we move the value to be printed into rsi
    call printf
pop rdi
jmp rdi                 ;we save this updated value of rax on the stack

  
pop rax
pop rsi

ret
    


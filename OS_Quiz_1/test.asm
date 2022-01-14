

segment .text
    extern printf
    mov rax, 0x1234567812345678
    xor ax, 0x11
    mov rdi, ax
    call printf
    xor rax, 0x11
    mov rdi, rax
    call printf
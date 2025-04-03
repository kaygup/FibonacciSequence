section .data
    fmt db "%d ", 0  
section .bss
    num resb 16  
section .text
    global _start  
    extern printf  

_start:
    mov rdi, 10
    call fibonacci
    mov rax, 60
    xor rdi, rdi
    syscall  

fibonacci:
    mov rsi, num
    mov dword [rsi], 0
    mov dword [rsi+4], 1
    mov rcx, 2

.loop:
    cmp rcx, rdi
    jge .done
    mov eax, [rsi+4*(rcx-1)]
    add eax, [rsi+4*(rcx-2)]
    mov [rsi+4*rcx], eax
    inc rcx
    jmp .loop

.done:
    mov rcx, rdi
    mov rsi, num
    call print_fibonacci
    ret  

print_fibonacci:
    cmp rcx, 0
    je .exit
    push rcx
    mov rdi, fmt
    mov rsi, [num]
    call printf
    add num, 4
    pop rcx
    loop print_fibonacci
.exit:
    ret  

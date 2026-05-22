; main.asm
%include "C:\pbn\Parcial 2\libreria_archivos.inc"

extern _getchar, _exit

section .data
    msg_menu db 10, "***** Menu *****", 10, "1. Escribir archivo", 10, "2. Leer archivo", 10, "3. Salir", 10, "Opcion: ", 0
    opcion_selec dd 0

section .text
global _main

_main:
    push ebp
    mov ebp, esp

    ; Capturar argumentos
    mov ecx, [ebp + 8]      ; argc
    cmp ecx, 2             
    jl mostrar_menu_bucle   ; Si no hay, ir al menú normal

    ; Si hay argumento, procesarlo
    mov edx, [ebp + 12]     
    mov eax, [edx + 4]      
    movzx eax, byte [eax]   
    sub eax, '0'            
    mov [opcion_selec], eax
    jmp procesar_opcion

mostrar_menu_bucle:
    call imprimir_menu
    push opcion_selec
    push fmt_i
    call _scanf
    add esp, 8

procesar_opcion:
    mov eax, [opcion_selec]
    cmp eax, 1
    je exec_escribir
    cmp eax, 2
    je exec_leer
    cmp eax, 3
    je salir
    jmp mostrar_menu_bucle

exec_escribir:
    call escribir_archivo
    jmp mostrar_menu_bucle

exec_leer:
    leer_archivo
    jmp mostrar_menu_bucle

salir:
    mov esp, ebp
    pop ebp
    xor eax, eax
ret
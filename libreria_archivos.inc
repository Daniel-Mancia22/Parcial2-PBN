; libreria_archivos.inc

extern _fopen, _fclose, _fgets, _fprintf, _printf, _scanf, _gets

section .data
    fmt_s db "%s", 0
    fmt_i db "%i", 0
    modo_r db "r", 0
    modo_w db "w", 0
    msg_error db "Error: No se pudo abrir el archivo.", 10, 0
    prompt_file db "Nombre del archivo: ", 0
    prompt_text db "Texto a escribir: ", 0

section .bss
    buffer_archivo resb 255
    nombre_file resb 100
    texto_escribir resb 255

section .text

; Función para imprimir el menú
imprimir_menu:
    push ebp
    mov ebp, esp
    
    push msg_menu
    call _printf
    add esp, 4
    
    leave
ret

; Opción 1: Escribir archivo(Función)
escribir_archivo:
    push ebp
    mov ebp, esp

    ; Pidiendo el nombre
    push prompt_file
    call _printf
    add esp, 4
    push nombre_file
    push fmt_s
    call _scanf
    add esp, 8

    ; Limpiar buffer
    call _getchar

    ; Pidiento el texto
    push prompt_text
    call _printf
    add esp, 4
    push texto_escribir
    call _gets     
    add esp, 4

    ; Abrir y escribir
    push modo_w
    push nombre_file
    call _fopen
    add esp, 8
    
    test eax, eax
    jz .error

    mov ebx, eax ; 
    push texto_escribir
    push fmt_s
    push ebx
    call _fprintf
    add esp, 12

    push ebx
    call _fclose
    add esp, 4
    jmp .fin

.error:
    push msg_error
    call _printf
    add esp, 4
    
.fin:
    leave
ret

; Opción 2: Leer archivo(Macro)
%macro leer_archivo 0

    ; Pidiendo nombre
    push prompt_file
    call _printf
    add esp, 4
    push nombre_file
    push fmt_s
    call _scanf
    add esp, 8

    ; Abrir para lectura
    push modo_r
    push nombre_file
    call _fopen
    add esp, 8
    
    test eax, eax
    jz %%error_leer

    mov ebx, eax
    
%%loop_leer:
    push ebx
    push 254
    push buffer_archivo
    call _fgets
    add esp, 12
    
    test eax, eax
    jz %%cerrar_leer

    push buffer_archivo
    call _printf
    add esp, 4
    jmp %%loop_leer

%%cerrar_leer:
    push ebx
    call _fclose
    add esp, 4
    jmp %%fin_macro

%%error_leer:
    push msg_error
    call _printf
    add esp, 4
    
%%fin_macro:
%endmacro
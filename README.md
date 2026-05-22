# Manejo de Archivos en Ensamblador (NASM) – Parcial 2

## Descripción

Este proyecto consiste en el desarrollo de un programa en **ensamblador (NASM)** que permite la manipulación básica de archivos mediante un menú interactivo en consola.

El sistema permite al usuario:

- Crear y escribir en archivos
- Leer contenido de archivos existentes
- Salir del programa

Además, el programa soporta la ejecución mediante **argumentos por línea de comandos**, lo que permite automatizar la selección de opciones.

## Tecnologías Utilizadas

- Lenguaje: **Assembly (NASM)**
- Plataforma: **Windows (Win32)**
- Librerías externas (C estándar):
  - `_printf`
  - `_scanf`
  - `_fopen`
  - `_fclose`
  - `_fgets`
  - `_fprintf`
  - `_gets`
- Ensamblador: **NASM**
- Compilador: **GCC (MinGW / Win32)**

## Estructura del Proyecto

```
Proyecto
│
├── main.asm
├── libreria_archivos.inc
└── Documentación.md
```

## Funcionamiento del Programa

El programa inicia verificando si se ingresó un argumento en la línea de comandos:

- Si **NO hay argumentos** → muestra el menú interactivo
- Si **hay argumento** → ejecuta directamente la opción

## Menú

```
***** Menu *****
1. Escribir archivo
2. Leer archivo
3. Salir
```

## Opción 1: Escribir archivo

1. Solicita el nombre del archivo
2. Solicita el texto a escribir
3. Crea o sobrescribe el archivo
4. Guarda el contenido ingresado

## Opción 2: Leer archivo

1. Solicita el nombre del archivo
2. Abre el archivo en modo lectura
3. Muestra el contenido línea por línea

## Opción 3: Salir

Finaliza la ejecución del programa.

## Características

- Uso de funciones externas de C desde ensamblador
- Implementación de funciones y macros
- Manejo de archivos con:
  - `fopen`
  - `fprintf`
  - `fgets`
- Uso de estructuras de control (`cmp`, `jmp`)
- Manejo de argumentos (`argc`, `argv`)

## Requisitos

- NASM instalado
- GCC (MinGW o similar)

## Compilación

```bash
nasm -f win32 main.asm
gcc main.obj -o main.exe
```

## Conceptos Aplicados
- Programación de bajo nivel
- Manejo de pila (stack)
- Convención de llamadas (cdecl)
- Entrada y salida en consola
- Manejo de archivos en ensamblador

## Desarrollador
- [Daniel Mancia](https://github.com/Daniel-Mancia22) - DevMadCode

## Conclusión

Este proyecto demuestra la integración entre ensamblador y C, permitiendo manipular archivos y entender el funcionamiento interno del sistema a bajo nivel.

# Práctica: Búsqueda Paralela en Arreglos con OpenMP

## Objetivo

Completar un programa en C que realiza la búsqueda de un número dentro de un arreglo de forma paralela, utilizando la biblioteca OpenMP.

Esta práctica está diseñada para que aprendas:

- Cómo dividir el trabajo entre múltiples hilos con OpenMP.
- Cómo generar números aleatorios de forma segura en entornos paralelos.
- Cómo manejar condiciones de carrera con secciones críticas.
- Cómo cancelar tareas paralelas cuando ya no es necesario seguir ejecutando.

---

## Archivos

El archivo base que debes completar se llama:  
`busqueda_paralela.c`

---

## Instrucciones

1. Completa los bloques marcados como `// TODO` en el archivo.
2. Utiliza las directivas de OpenMP para paralelizar la inicialización del arreglo y la búsqueda.
3. Asegúrate de usar `rand_r()` con una semilla diferente por hilo.
4. Usa `#pragma omp critical` para proteger el acceso compartido a la variable `resultado`.
5. (Opcional) Implementa cancelación temprana con `#pragma omp cancel for` si usas OpenMP 4.0 o superior.

---

## Cómo compilar y ejecutar

Debes tener instalado GCC con soporte para OpenMP.

```bash
gcc -fopenmp -o busqueda busqueda_paralela.c
./busqueda


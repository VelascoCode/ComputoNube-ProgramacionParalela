# Suma de Arreglos en Paralelo con OpenMP (C++)

## Descripción del proyecto
Este proyecto implementa la **suma paralela de dos arreglos numéricos** utilizando **C++ y la librería OpenMP**, con el objetivo de demostrar cómo la programación paralela permite reducir el tiempo de ejecución en operaciones independientes cuando se trabaja con grandes volúmenes de datos.

La suma de arreglos es una operación sencilla desde el punto de vista algorítmico, pero su costo computacional crece linealmente conforme aumenta el número de elementos. Aprovechando que cada suma es independiente, el problema se presta de forma natural a la **paralelización mediante múltiples hilos (threads)**.

---

## Objetivos de aprendizaje

El desarrollo de esta actividad contribuye al cumplimiento de los siguientes objetivos:

- Diseñar algoritmos paralelos, implementándolos para resolver problemas numéricos y no numéricos.
- Seleccionar modelos de paralelización apropiados y aplicarlos en la creación de una versión paralela correcta que explote el ambiente de cómputo paralelo de última generación.

---

## Planteamiento del problema

Dado:
- Un arreglo **A** de *N* elementos.
- Un arreglo **B** de *N* elementos.

Se desea calcular un tercer arreglo **C**, donde cada elemento cumple:

C[i] = A[i] + B[i]


En una versión secuencial, esta operación se realiza elemento por elemento en orden.  
Cuando *N* es muy grande (millones de elementos), el tiempo de ejecución aumenta considerablemente.

Dado que **cada suma es independiente**, es posible dividir el trabajo entre múltiples hilos y ejecutar las operaciones en paralelo, reduciendo el tiempo total de cómputo.

---

## Tecnologías utilizadas

- **Lenguaje:** C++
- **Entorno de desarrollo:** Visual Studio
- **Modelo de paralelización:** OpenMP
- **Paradigma:** Programación paralela basada en memoria compartida (shared memory)

---

## Configuración del proyecto

1. Crear un proyecto de **Aplicación de Consola en C++** en Visual Studio.
2. Habilitar el soporte para OpenMP:
   - `Project Properties → C/C++ → Language → OpenMP Support → Yes (/openmp)`
3. Compilar preferentemente en **modo Release** para observar un mejor rendimiento.

---

## Implementación

El programa realiza los siguientes pasos:

1. Define tres arreglos:
   - `a`: primer arreglo
   - `b`: segundo arreglo
   - `c`: arreglo resultado
2. Inicializa los arreglos `a` y `b` con valores numéricos.
3. Ejecuta un ciclo `for` paralelo usando **OpenMP**, donde cada hilo calcula una parte del arreglo `c`.
4. Imprime los primeros elementos de cada arreglo para validar la correcta ejecución.

Ejemplo de paralelización utilizada:

```cpp
#pragma omp parallel for default(none) shared(a,b,c) schedule(static, CHUNK)
for (int i = 0; i < static_cast<int>(N); ++i) {
    c[i] = a[i] + b[i];
}
```
---

## Validación de resultados

Para comprobar la correcta ejecución del programa:

Se imprimen los primeros k elementos de los arreglos a, b y c.

Se verifica que cada elemento del arreglo c corresponde a la suma correcta de a[i] + b[i].

## Conclusión

Este proyecto demuestra cómo un problema sencillo puede beneficiarse significativamente del uso de programación paralela. Mediante OpenMP, es posible aprovechar múltiples núcleos del procesador para distribuir el trabajo y mejorar el rendimiento, manteniendo un código claro, legible y fácil de mantener.

La suma de arreglos es un ejemplo representativo de problemas embarrassingly parallel, ideales para introducir los conceptos fundamentales del cómputo paralelo.

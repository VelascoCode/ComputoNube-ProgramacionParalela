// sumaArreglosParalelo.cpp
// ------------------------------------------------------------
// Este programa muestra cómo sumar dos arreglos numéricos
// utilizando programación paralela con OpenMP.
//
// La idea principal es:
// - Tener dos arreglos (a y b)
// - Sumar elemento por elemento
// - Guardar el resultado en un tercer arreglo (c)
// - Usar varios "hilos" del procesador para acelerar el proceso
// ------------------------------------------------------------

#include <array>     // Permite usar arreglos modernos y seguros (std::array)
#include <iostream>  // Permite imprimir mensajes en pantalla (cout)
#include <omp.h>     // Biblioteca para programación paralela con OpenMP

// --------------------
// Constantes del programa
// --------------------

// Número de elementos que tendrá cada arreglo
// constexpr indica que el valor se conoce desde la compilación
constexpr std::size_t N = 20100;

// Tamaño del bloque de trabajo que se asigna a cada hilo
// (usado por OpenMP para repartir las iteraciones)
constexpr int CHUNK = 150;

// Cantidad de elementos que se mostrarán en pantalla
// (para no imprimir todo el arreglo)
constexpr int MOSTRAR = 12;

// ------------------------------------------------------------
// Función para imprimir los primeros elementos de un arreglo
// Recibe un arreglo de tipo std::array<float, N>
// ------------------------------------------------------------
void imprimeArreglo(const std::array<float, N>& d) {
    // Imprime solo los primeros MOSTRAR elementos
    for (int x = 0; x < MOSTRAR; ++x) {
        std::cout << d[x] << " - ";
    }
    std::cout << '\n';
}

int main() {

    // Mensaje inicial para el usuario
    std::cout << "Sumando Arreglos en Paralelo!\n";

    // --------------------------------------------------------
    // Declaración de los arreglos
    //
    // a -> primer arreglo
    // b -> segundo arreglo
    // c -> arreglo donde se guardará la suma
    //
    // std::array garantiza tamaño fijo y mayor seguridad
    // --------------------------------------------------------
    std::array<float, N> a{}, b{}, c{};

    // --------------------------------------------------------
    // Inicialización de los arreglos a y b
    //
    // Se recorren los arreglos uno por uno y se les asignan
    // valores numéricos usando fórmulas simples
    // --------------------------------------------------------
    for (std::size_t i = 0; i < N; ++i) {
        a[i] = static_cast<float>(i) * 5.0f;
        b[i] = (static_cast<float>(i) + 0.5f) * 2.1f;
    }

    // --------------------------------------------------------
    // BUCLE PARALELO CON OPENMP
    //
    // #pragma omp parallel for
    //  - Indica que este ciclo "for" se ejecutará en paralelo
    //  - El trabajo se reparte entre varios hilos del procesador
    //
    // default(none)
    //  - Obliga a declarar explícitamente qué variables son compartidas
    //
    // shared(a, b, c)
    //  - Los arreglos a, b y c serán compartidos por todos los hilos
    //
    // schedule(static, CHUNK)
    //  - Las iteraciones se dividen en bloques de tamaño CHUNK
    // --------------------------------------------------------
    #pragma omp parallel for default(none) shared(a,b,c) schedule(static, CHUNK)
    for (int i = 0; i < static_cast<int>(N); ++i) {

        // Cada hilo suma una parte del arreglo
        // No hay conflicto entre hilos porque cada uno trabaja
        // con posiciones distintas del arreglo
        c[i] = a[i] + b[i];
    }

    // --------------------------------------------------------
    // Impresión de resultados para verificación
    // Solo se muestran los primeros MOSTRAR valores
    // --------------------------------------------------------
    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo a:\n";
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo b:\n";
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo c:\n";
    imprimeArreglo(c);

    // Finaliza el programa correctamente
    return 0;
}

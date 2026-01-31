// sumaArreglosParalelo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <array>
#include <iostream>
#include <omp.h>

constexpr std::size_t N = 10000;
constexpr int CHUNK = 200;
constexpr int MOSTRAR = 8;

void imprimeArreglo(const std::array<float, N>& d) {
    for (int x = 0; x < MOSTRAR; ++x) {
        std::cout << d[x] << " - ";
    }
    std::cout << '\n';
}

int main() {
    std::cout << "Sumando Arreglos en Paralelo!\n";

    std::array<float, N> a{}, b{}, c{};

    for (std::size_t i = 0; i < N; ++i) {
        a[i] = static_cast<float>(i) * 10.0f;
        b[i] = (static_cast<float>(i) + 2.5f) * 3.6f;
    }

    #pragma omp parallel for default(none) shared(a,b,c) schedule(static, CHUNK)
    for (int i = 0; i < static_cast<int>(N); ++i) {
        c[i] = a[i] + b[i];
    }


    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo a:\n";
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo b:\n";
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo c:\n";
    imprimeArreglo(c);

    return 0;
}

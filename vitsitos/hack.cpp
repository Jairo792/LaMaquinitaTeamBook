/*
 * Bit Hacks
 * Técnicas útiles para trabajar con máscaras de bits.
 * Muy utilizadas en programación competitiva para problemas de conjuntos, DP con bitmasks, combinatoria, etc.
 */

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

/*
 * next_bits_permutation(x)
 * Devuelve la siguiente máscara con el mismo número de bits encendidos (1s) en orden lexicográfico.
 * Útil para generar todas las combinaciones de k elementos como máscaras de bits.
 *
 * Ejemplo:
 * x = 0b00111 (representa una combinación de 3 elementos)
 * next_bits_permutation(x) → 0b01011, luego 0b01101, etc.
 */
ull next_bits_permutation(ull x) {
    ull c = __builtin_ctzll(x);         // Cuenta los ceros a la derecha de x
    ull r = x + (1ULL << c);            // Añade 1 al bit menos significativo que está en 1
    return (r ^ x) >> (c + 2) | r;      // Calcula la siguiente permutación
}

/*
 * subsets(s)
 * Itera sobre todos los subconjuntos propios (no incluye s) de un conjunto dado s.
 * El conjunto s se representa como una máscara de bits.
 *
 * Ejemplo:
 * s = 0b1011 (conjunto {0,1,3})
 * Se recorrerán los subconjuntos: 1010, 1001, 1000, 0011, 0010, 0001
 */
void subsets(ull s) {
    for (ull x = s; x;) {
        --x &= s;
        // Aquí puedes trabajar con cada subconjunto x
        // Por ejemplo, imprimirlo:
        // cout << bitset<4>(x) << '\n';
    }
}


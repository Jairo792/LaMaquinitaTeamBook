#include <iostream>
#include <vector>
#include <iomanip> // para setw
using namespace std;

// Función para calcular combinaciones C(n, k)
int combinacion(int n, int k) {
    if (k == 0 || k == n) return 1;
    int res = 1;
    for (int i = 1; i <= k; ++i) {
        res *= n--;
        res /= i;
    }
    return res;
}

int main() {
    int filas;
    cout << "Introduce el número de filas: ";
    cin >> filas;

    for (int i = 0; i < filas; ++i) {
        // Imprimir espacios para centrar
        cout << setw((filas - i) * 2);
        for (int j = 0; j <= i; ++j) {
            cout << setw(4) << combinacion(i, j);
        }
        cout << endl;
    }

    return 0;
}


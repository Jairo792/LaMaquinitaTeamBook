#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Introduce el número de filas (n): ";
    cin >> n;
    cout << "Introduce el número de columnas (m): ";
    cin >> m;

    vector<vector<int>> matriz(n, vector<int>(m));
    int valor = 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Izquierda a derecha
            for (int j = 0; j < m; j++) {
                matriz[i][j] = valor++;
            }
        } else {
            // Derecha a izquierda
            for (int j = m - 1; j >= 0; j--) {
                matriz[i][j] = valor++;
            }
        }
    }

    // Imprimir la matriz
    cout << "\nMatriz viborita:\n";
    for (const auto& fila : matriz) {
        for (int x : fila) {
            cout << x << "\t";
        }
        cout << "\n";
    }

    return 0;
}


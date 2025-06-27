#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    vector<vector<int>> matriz(n, vector<int>(m));
    int valor = 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Left to right
            for (int j = 0; j < m; j++) {
                matriz[i][j] = valor++;
            }
        } else {
            // Right to left
            for (int j = m - 1; j >= 0; j--) {
                matriz[i][j] = valor++;
            }
        }
    }

    // Print the matrix
    cout << "\nSnake matrix:\n";
    for (const auto& fila : matriz) {
        for (int x : fila) {
            cout << x << "\t";
        }
        cout << "\n";
    }

    return 0;
}


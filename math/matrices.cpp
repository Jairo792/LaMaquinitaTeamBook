#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

using Matrix = vector<vector<double>>;

// Función para imprimir matriz
void printMatrix(const Matrix &mat) {
    for (const auto &row : mat) {
        for (double val : row) cout << setw(10) << val << " ";
        cout << "\n";
    }
}

// Intercambia filas r1 y r2 en la matriz
void swapRows(Matrix &mat, int r1, int r2) {
    std::swap(mat[r1], mat[r2]);
}

// Calcula el determinante con eliminación Gaussiana
double determinant(Matrix mat) {
    int n = (int)mat.size();
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        // Buscar fila con pivote no cero
        int pivot = i;
        while (pivot < n && fabs(mat[pivot][i]) < 1e-12) pivot++;
        if (pivot == n) return 0;  // matriz singular

        if (pivot != i) {
            swapRows(mat, i, pivot);
            det = -det;  // cambiar signo si intercambiamos filas
        }

        det *= mat[i][i];
        if (fabs(mat[i][i]) < 1e-12) return 0;

        // Eliminar debajo del pivote
        for (int r = i + 1; r < n; r++) {
            double factor = mat[r][i] / mat[i][i];
            for (int c = i; c < n; c++) {
                mat[r][c] -= factor * mat[i][c];
            }
        }
    }

    return det;
}

// Calcula la inversa usando Gauss-Jordan
bool inverse(const Matrix &input, Matrix &inv) {
    int n = (int)input.size();
    Matrix mat = input;
    inv.assign(n, vector<double>(n, 0));

    // Crear matriz identidad en inv
    for (int i = 0; i < n; i++) inv[i][i] = 1.0;

    for (int i = 0; i < n; i++) {
        // Encontrar pivote
        int pivot = i;
        for (int r = i + 1; r < n; r++) {
            if (fabs(mat[r][i]) > fabs(mat[pivot][i])) pivot = r;
        }

        if (fabs(mat[pivot][i]) < 1e-12) return false;  // matriz singular

        if (pivot != i) {
            swapRows(mat, i, pivot);
            swapRows(inv, i, pivot);
        }

        double pivot_val = mat[i][i];
        for (int c = 0; c < n; c++) {
            mat[i][c] /= pivot_val;
            inv[i][c] /= pivot_val;
        }

        // Eliminar otros elementos en columna i
        for (int r = 0; r < n; r++) {
            if (r != i) {
                double factor = mat[r][i];
                for (int c = 0; c < n; c++) {
                    mat[r][c] -= factor * mat[i][c];
                    inv[r][c] -= factor * inv[i][c];
                }
            }
        }
    }

    return true;
}

// Ejemplo de uso
int main() {
    Matrix arr = {
        {4, 7, 2},
        {3, 6, 1},
        {2, 5, 1}
    };

    cout << "Matriz original:\n";
    printMatrix(arr);

    double det = determinant(arr);
    cout << "\nDeterminante: " << det << "\n";

    if (fabs(det) < 1e-12) {
        cout << "La matriz no tiene inversa (det = 0)\n";
    } else {
        Matrix inv;
        if (inverse(arr, inv)) {
            cout << "\nMatriz inversa:\n";
            printMatrix(inv);
        } else {
            cout << "No se pudo calcular la inversa\n";
        }
    }

    return 0;
}


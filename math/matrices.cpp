#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

using Matrix = vector<vector<double>>;

// Function to print matrix
void printMatrix(const Matrix &mat) {
    for (const auto &row : mat) {
        for (double val : row) cout << setw(10) << val << " ";
        cout << "\n";
    }
}

// Swap rows r1 and r2 in the matrix
void swapRows(Matrix &mat, int r1, int r2) {
    std::swap(mat[r1], mat[r2]);
}

// Calculate determinant using Gaussian elimination
double determinant(Matrix mat) {
    int n = (int)mat.size();
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        // Find row with nonzero pivot
        int pivot = i;
        while (pivot < n && fabs(mat[pivot][i]) < 1e-12) pivot++;
        if (pivot == n) return 0;  // singular matrix

        if (pivot != i) {
            swapRows(mat, i, pivot);
            det = -det;  // change sign if rows are swapped
        }

        det *= mat[i][i];
        if (fabs(mat[i][i]) < 1e-12) return 0;

        // Eliminate below the pivot
        for (int r = i + 1; r < n; r++) {
            double factor = mat[r][i] / mat[i][i];
            for (int c = i; c < n; c++) {
                mat[r][c] -= factor * mat[i][c];
            }
        }
    }

    return det;
}

// Calculate inverse using Gauss-Jordan
bool inverse(const Matrix &input, Matrix &inv) {
    int n = (int)input.size();
    Matrix mat = input;
    inv.assign(n, vector<double>(n, 0));

    // Create identity matrix in inv
    for (int i = 0; i < n; i++) inv[i][i] = 1.0;

    for (int i = 0; i < n; i++) {
        // Find pivot
        int pivot = i;
        for (int r = i + 1; r < n; r++) {
            if (fabs(mat[r][i]) > fabs(mat[pivot][i])) pivot = r;
        }

        if (fabs(mat[pivot][i]) < 1e-12) return false;  // singular matrix

        if (pivot != i) {
            swapRows(mat, i, pivot);
            swapRows(inv, i, pivot);
        }

        double pivot_val = mat[i][i];
        for (int c = 0; c < n; c++) {
            mat[i][c] /= pivot_val;
            inv[i][c] /= pivot_val;
        }

        // Eliminate other elements in column i
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

// Example usage
int main() {
    Matrix arr = {
        {4, 7, 2},
        {3, 6, 1},
        {2, 5, 1}
    };

    cout << "Original matrix:\n";
    printMatrix(arr);

    double det = determinant(arr);
    cout << "\nDeterminant: " << det << "\n";

    if (fabs(det) < 1e-12) {
        cout << "Matrix has no inverse (det = 0)\n";
    } else {
        Matrix inv;
        if (inverse(arr, inv)) {
            cout << "\nInverse matrix:\n";
            printMatrix(inv);
        } else {
            cout << "Could not compute the inverse\n";
        }
    }

    return 0;
}


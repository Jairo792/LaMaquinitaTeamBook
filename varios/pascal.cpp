#include <iostream>
#include <vector>
#include <iomanip> // for setw
using namespace std;

// Function to calculate combinations C(n, k)
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
    cout << "Enter the number of rows: ";
    cin >> filas;

    for (int i = 0; i < filas; ++i) {
        // Print spaces to center
        cout << setw((filas - i) * 2);
        for (int j = 0; j <= i; ++j) {
            cout << setw(4) << combinacion(i, j);
        }
        cout << endl;
    }

    return 0;
}


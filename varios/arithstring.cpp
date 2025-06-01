#include <iostream>
#include <string>
#include <algorithm>

// Suma de strings que representan números enteros positivos
std::string sumaStrings(const std::string &a, const std::string &b) {
    std::string res;
    int carry = 0;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;

    while(i >= 0 || j >= 0 || carry) {
        int x = i >= 0 ? a[i] - '0' : 0;
        int y = j >= 0 ? b[j] - '0' : 0;
        int suma = x + y + carry;
        carry = suma / 10;
        res.push_back((suma % 10) + '0');
        i--; j--;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

// Compara si a >= b (ambos positivos y sin ceros a la izquierda)
bool mayorIgual(const std::string &a, const std::string &b) {
    if (a.size() != b.size()) return a.size() > b.size();
    return a >= b;
}

// Resta de strings a - b (suponiendo a >= b)
std::string restaStrings(const std::string &a, const std::string &b) {
    if (!mayorIgual(a, b)) return "Error: a < b";

    std::string res;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int borrow = 0;

    while(i >= 0) {
        int x = a[i] - '0' - borrow;
        int y = j >= 0 ? b[j] - '0' : 0;

        if (x < y) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res.push_back((x - y) + '0');
        i--; j--;
    }

    // Quitar ceros a la izquierda
    while(res.size() > 1 && res.back() == '0') res.pop_back();
    std::reverse(res.begin(), res.end());
    return res;
}

// Multiplicación de strings
std::string multiplicacionStrings(const std::string &a, const std::string &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    std::string res(n + m, '0');

    for(int i = n - 1; i >= 0; i--) {
        int carry = 0;
        int x = a[i] - '0';
        for(int j = m - 1; j >= 0; j--) {
            int y = b[j] - '0';
            int suma = (res[i + j + 1] - '0') + x * y + carry;
            res[i + j + 1] = (suma % 10) + '0';
            carry = suma / 10;
        }
        res[i] += carry;
    }

    // Quitar ceros a la izquierda
    int pos = 0;
    while (pos < (int)res.size() - 1 && res[pos] == '0') pos++;
    return res.substr(pos);
}

// Prueba rápida
int main() {
    std::string A = "123456789123456789";
    std::string B = "987654321987654321";

    std::cout << "Suma: " << sumaStrings(A, B) << "\n";
    std::cout << "Resta (B - A): " << restaStrings(B, A) << "\n";  // B > A
    std::cout << "Multiplicacion: " << multiplicacionStrings(A, B) << "\n";

    return 0;
}


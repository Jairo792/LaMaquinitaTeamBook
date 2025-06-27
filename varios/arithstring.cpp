#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

// Sum of strings representing positive integers
string sumaStrings(const string &a, const string &b) {
    string res;
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
    reverse(res.begin(), res.end());
    return res;
}

// Compare if a >= b (both positive and without leading zeros)
bool mayorIgual(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() > b.size();
    return a >= b;
}

// Subtract strings a - b (assuming a >= b)
string restaStrings(const string &a, const string &b) {
    if (!mayorIgual(a, b)) return "Error: a < b";

    string res;
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

    // Remove leading zeros
    while(res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

// Multiplication of strings
string multiplicacionStrings(const string &a, const string &b) {
    int n = (int)a.size();
    int m = (int)b.size();
    string res(n + m, '0');

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

    // Remove leading zeros
    int pos = 0;
    while (pos < (int)res.size() - 1 && res[pos] == '0') pos++;
    return res.substr(pos);
}

// Quick test
int main() {
    string A = "123456789123456789";
    string B = "987654321987654321";

    cout << "Sum: " << sumaStrings(A, B) << "\n";
    cout << "Subtraction (B - A): " << restaStrings(B, A) << "\n";  // B > A
    cout << "Multiplication: " << multiplicacionStrings(A, B) << "\n";

    return 0;
}


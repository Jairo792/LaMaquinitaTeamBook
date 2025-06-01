#include <iostream>
#include <iomanip> // std::fixed, std::setprecision
using namespace std;

int main() {
    double pi = 3.1415926535;
    cout << fixed << setprecision(3) << pi << '\n'; // Output: 3.142
}


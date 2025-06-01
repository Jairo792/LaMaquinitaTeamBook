#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "ProgramacionCompetitiva";
    
    string sub1 = s.substr(0, 11);  // "Programacion"
    string sub2 = s.substr(11, 11); // "Competitiva"
    string sub3 = s.substr(5);      // desde el índice 5 hasta el final: "amacionCompetitiva"

    cout << sub1 << '\n';
    cout << sub2 << '\n';
    cout << sub3 << '\n';

    return 0;
}


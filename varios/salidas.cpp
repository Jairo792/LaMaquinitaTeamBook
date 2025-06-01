#include <iostream>
using namespace std;

int main() {
    // \n: salto de linea
    cout << "Hola\nMundo" << endl;

    // \t: tabulacion horizontal
    cout << "Nombre\tEdad\nJuan\t20\n";

    // \\: imprime el backslash
    cout << "Ruta: C:\\Users\\Jairo\\Documentos\n";

    // \": imprime comillas dobles
    cout << "Dijo: \"Hola mundo\"\n";

    // \': imprime comillas simples
    cout << "Letra: \'A\'\n";

    // \a: beep (no siempre funciona en todas consolas)
    cout << "\a"; // intento de alerta sonora

    // \b: retroceso (borra el caracter anterior en algunas consolas)
    cout << "ABC\bD\n"; // imprime ABD (borra la C visualmente)

    // \r: retorno de carro (reinicia al inicio de la linea)
    cout << "Sobrescribe\rHola\n"; // Holaescribe

    // \f y \v: no tienen mucho efecto visible en terminales modernas
    cout << "Primera linea\fSegunda (form feed)\n";
    cout << "Primera linea\vSegunda (vertical tab)\n";

    // \0: caracter nulo, marca fin de cadena en arreglos de char
    char palabra[] = {'H', 'o', 'l', 'a', '\0'};
    cout << "Cadena terminada por nulo: " << palabra << endl;

    return 0;
}


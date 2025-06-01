/*
 * Geometria basica: calculo de areas y subareas
 * Autor: Jairo Flores
 */

#include <bits/stdc++.h>
using namespace std;

// Area de un triangulo dado base y altura
double area_triangulo(double base, double altura) {
    return (base * altura) / 2.0;
}

// Area de un rectangulo dado base y altura
double area_rectangulo(double base, double altura) {
    return base * altura;
}

// Area de un cuadrado dado lado
double area_cuadrado(double lado) {
    return lado * lado;
}

// Area de un circulo dado radio
double area_circulo(double radio) {
    const double PI = acos(-1);
    return PI * radio * radio;
}

// Area de un trapecio (bases mayor y menor, altura)
double area_trapecio(double base_mayor, double base_menor, double altura) {
    return ((base_mayor + base_menor) * altura) / 2.0;
}

// Area de un rombo dado diagonal mayor y menor
double area_rombo(double diagonal_mayor, double diagonal_menor) {
    return (diagonal_mayor * diagonal_menor) / 2.0;
}

// Area de un poligono regular (n lados) con apotema y perimetro
double area_poligono_regular(int n_lados, double apotema, double perimetro) {
    return (perimetro * apotema) / 2.0;
}

// Area de un poligono regular usando solo lado y numero de lados (formula basada en apotema)
double area_poligono_regular_lado(int n_lados, double lado) {
    const double PI = acos(-1);
    double apotema = lado / (2 * tan(PI / n_lados));
    double perimetro = n_lados * lado;
    return (perimetro * apotema) / 2.0;
}

// Area de sector circular (radio y angulo en grados)
double area_sector_circular(double radio, double angulo_grados) {
    const double PI = acos(-1);
    return (PI * radio * radio) * (angulo_grados / 360.0);
}

// Area de segmento circular (radio y angulo en grados)
double area_segmento_circular(double radio, double angulo_grados) {
    const double PI = acos(-1);
    double angulo_radianes = angulo_grados * PI / 180.0;
    double area_sector = (radio * radio * angulo_radianes) / 2.0;
    double area_triangulo = (radio * radio * sin(angulo_radianes)) / 2.0;
    return area_sector - area_triangulo;
}

// Perimetro de circulo (circunferencia)
double perimetro_circulo(double radio) {
    const double PI = acos(-1);
    return 2 * PI * radio;
}

// Perimetro de poligono regular (n lados y lado)
double perimetro_poligono_regular(int n_lados, double lado) {
    return n_lados * lado;
}

// Ejemplo de uso
int main() {
    cout << fixed << setprecision(4);
    cout << "Area triangulo (base=5, altura=3): " << area_triangulo(5,3) << "\n";
    cout << "Area circulo (radio=2): " << area_circulo(2) << "\n";
    cout << "Area trapecio (bases=3,5, altura=4): " << area_trapecio(5,3,4) << "\n";
    cout << "Area poligono regular (hexagono, lado=2): " << area_poligono_regular_lado(6, 2) << "\n";
    cout << "Area sector circular (radio=4, angulo=90): " << area_sector_circular(4, 90) << "\n";
    return 0;
}


/*
 * Trigonometria basica para Programacion Competitiva
 * Autor: Jairo Flores
 */

#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

// Funciones trigonométricas
// ángulos en radianes (usar grados * PI/180 para convertir)

// Convertir grados a radianes
double deg_to_rad(double deg) {
    return deg * PI / 180.0;
}

// Convertir radianes a grados
double rad_to_deg(double rad) {
    return rad * 180.0 / PI;
}

// Calcular hipotenusa con pitagoras
double hypotenusa(double a, double b) {
    return sqrt(a*a + b*b);
}

// Ley de senos: a/sin(A) = b/sin(B) = c/sin(C)
double ley_de_senos(double a, double A_rad, double B_rad) {
    // Por ejemplo, dado lado a y angulo A, calcula lado b dado angulo B
    return a * sin(B_rad) / sin(A_rad);
}

// Ley de cosenos: c^2 = a^2 + b^2 - 2ab cos(C)
double ley_de_cosenos(double a, double b, double C_rad) {
    return sqrt(a*a + b*b - 2*a*b*cos(C_rad));
}

// Area de un triangulo con dos lados y angulo entre ellos: (1/2)*ab*sin(C)
double area_triangulo_trig(double a, double b, double C_rad) {
    return 0.5 * a * b * sin(C_rad);
}

// Calculo de angulos (ejemplo)
double angulo_entre_vectores(double x1, double y1, double x2, double y2) {
    // Producto punto = |v1||v2|cos(theta)
    double dot = x1*x2 + y1*y2;
    double mag1 = sqrt(x1*x1 + y1*y1);
    double mag2 = sqrt(x2*x2 + y2*y2);
    return acos(dot / (mag1*mag2)); // devuelve radianes
}

// Distancia entre dos puntos (x1,y1) y (x2,y2)
double distancia(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

// Ejemplo de uso:
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A_deg = 30.0, B_deg = 45.0;
    double a = 5.0; // lado a
    double A = deg_to_rad(A_deg);
    double B = deg_to_rad(B_deg);

    cout << fixed << setprecision(4);
    cout << "Lado b usando ley de senos: " << ley_de_senos(a, A, B) << "\n";

    double c = ley_de_cosenos(a, ley_de_senos(a, A, B), deg_to_rad(60));
    cout << "Lado c usando ley de cosenos: " << c << "\n";

    double area = area_triangulo_trig(a, ley_de_senos(a, A, B), deg_to_rad(60));
    cout << "Area triangulo con lados y angulo: " << area << "\n";

    double angulo = angulo_entre_vectores(1, 0, 0, 1);
    cout << "Angulo entre vectores (1,0) y (0,1): " << rad_to_deg(angulo) << " grados\n";

    return 0;
}


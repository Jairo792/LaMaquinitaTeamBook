/*
 * Basic trigonometry for competitive programming
 * Author: Jairo Flores
 */

#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

// Trigonometric functions
// Angles in radians (use degrees * PI/180 to convert)

// Convert degrees to radians
double deg_to_rad(double deg) {
    return deg * PI / 180.0;
}

// Convert radians to degrees
double rad_to_deg(double rad) {
    return rad * 180.0 / PI;
}

// Calculate hypotenuse with Pythagoras
double hypotenuse(double a, double b) {
    return sqrt(a*a + b*b);
}

// Law of sines: a/sin(A) = b/sin(B) = c/sin(C)
double law_of_sines(double a, double A_rad, double B_rad) {
    // For example, given side a and angle A, calculates side b given angle B
    return a * sin(B_rad) / sin(A_rad);
}

// Law of cosines: c^2 = a^2 + b^2 - 2ab cos(C)
double law_of_cosines(double a, double b, double C_rad) {
    return sqrt(a*a + b*b - 2*a*b*cos(C_rad));
}

// Area of a triangle with two sides and the angle between them: (1/2)*ab*sin(C)
double triangle_area_trig(double a, double b, double C_rad) {
    return 0.5 * a * b * sin(C_rad);
}

// Angle between vectors (example)
double angle_between_vectors(double x1, double y1, double x2, double y2) {
    // Dot product = |v1||v2|cos(theta)
    double dot = x1*x2 + y1*y2;
    double mag1 = sqrt(x1*x1 + y1*y1);
    double mag2 = sqrt(x2*x2 + y2*y2);
    return acos(dot / (mag1*mag2)); // returns radians
}

// Distance between two points (x1,y1) and (x2,y2)
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

// Example usage:
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double A_deg = 30.0, B_deg = 45.0;
    double a = 5.0; // side a
    double A = deg_to_rad(A_deg);
    double B = deg_to_rad(B_deg);

    cout << fixed << setprecision(4);
    cout << "Side b using law of sines: " << law_of_sines(a, A, B) << "\n";

    double c = law_of_cosines(a, law_of_sines(a, A, B), deg_to_rad(60));
    cout << "Side c using law of cosines: " << c << "\n";

    double area = triangle_area_trig(a, law_of_sines(a, A, B), deg_to_rad(60));
    cout << "Triangle area with sides and angle: " << area << "\n";

    double angle = angle_between_vectors(1, 0, 0, 1);
    cout << "Angle between vectors (1,0) and (0,1): " << rad_to_deg(angle) << " degrees\n";

    return 0;
}


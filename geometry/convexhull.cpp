/*
 * Convex Hull - Algoritmo Graham Scan
 * Autor: Jairo Flores
 * Entrada: vector de puntos (x, y)
 * Salida: vector de puntos que forman el hull convexo en orden ccw
 */

#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    bool operator<(const Point& p) const {
        return y < p.y || (y == p.y && x < p.x);
    }
};

// Producto cruzado (vectorial) de AB x AC
long long cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x);
}

// Funcion que calcula el convex hull y devuelve los vertices en orden ccw
vector<Point> convexHull(vector<Point> pts) {
    int n = (int)pts.size();
    if (n <= 1) return pts;

    // Paso 1: encontrar punto base (con menor y, si empate menor x)
    sort(pts.begin(), pts.end());
    Point base = pts[0];

    // Paso 2: ordenar por angulo polar respecto a base
    sort(pts.begin() + 1, pts.end(), [&](const Point &a, const Point &b) {
        long long c = cross(base, a, b);
        if (c == 0) // si son colineales, el mas cercano va primero
            return (a.x - base.x)*(a.x - base.x) + (a.y - base.y)*(a.y - base.y) <
                   (b.x - base.x)*(b.x - base.x) + (b.y - base.y)*(b.y - base.y);
        return c > 0;
    });

    // Paso 3: construir el hull usando stack
    vector<Point> hull;
    for (auto &p : pts) {
        while ((int)hull.size() > 1 && cross(hull[hull.size()-2], hull.back(), p) <= 0)
            hull.pop_back();
        hull.push_back(p);
    }

    return hull;
}

// Ejemplo de uso
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++)
        cin >> pts[i].x >> pts[i].y;

    vector<Point> hull = convexHull(pts);

    cout << (int)hull.size() << "\n";
    for (auto &p : hull)
        cout << p.x << " " << p.y << "\n";

    return 0;
}


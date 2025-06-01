/*
 * Union-Find (Disjoint Set Union - DSU)
 * Operaciones eficientes de unión y búsqueda de conjuntos disjuntos.
 * Soporta compresión de caminos y unión por tamaño o rango.
 * Complejidad amortizada: O(α(n)) por operación
 */

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]); // compresión de caminos
        return parent[u];
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (size[u] < size[v]) swap(u, v); // unión por tamaño
        parent[v] = u;
        size[u] += size[v];
        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }
};


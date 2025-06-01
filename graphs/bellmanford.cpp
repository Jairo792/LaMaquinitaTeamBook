/*
 * Bellman-Ford Algorithm
 * Calcula la distancia más corta desde un nodo origen, detecta ciclos negativos.
 * Complejidad: O(V * E)
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, w;
};

vector<int> bellman_ford(int n, int src, const vector<Edge>& edges) {
    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int i = 1; i < n; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    // Detección de ciclo negativo
    for (auto [u, v, w] : edges) {
        if (dist[u] < INF && dist[v] > dist[u] + w)
            throw runtime_error("Negative weight cycle detected");
    }

    return dist;
}


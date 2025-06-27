/*
 * Bellman-Ford Algorithm
 * Calculates the shortest distance from a source node, detects negative cycles.
 * Complexity: O(V * E)
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

    // Negative cycle detection
    for (auto [u, v, w] : edges) {
        if (dist[u] < INF && dist[v] > dist[u] + w)
            throw runtime_error("Negative weight cycle detected");
    }

    return dist;
}


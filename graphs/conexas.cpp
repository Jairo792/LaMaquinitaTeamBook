/*
 * Conteo de componentes conexas en grafo no dirigido
 */

#include <bits/stdc++.h>
using namespace std;

int count_components(int n, const vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    int count = 0;
    for (int u = 0; u < n; ++u) {
        if (!visited[u]) {
            dfs(u, adj, visited);
            ++count;
        }
    }
    return count;
}


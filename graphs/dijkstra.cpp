/*
 * Dijkstra's Algorithm
 * Finds the minimum distances from a source node in a weighted graph with no negative weights.
 * Complexity: O((V + E) log V)
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
using pii = pair<int, int>; // {dist, node}

vector<int> dijkstra(int n, int src, const vector<vector<pii>>& adj) {
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return dist;
}


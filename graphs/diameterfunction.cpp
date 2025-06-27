// Returns the diameter of an undirected unweighted graph
// n: number of nodes (1-based), edges: list of {u, v}
int graph_diameter(int n, const vector<pair<int, int>>& edges) {
    const int INF = 1e9;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    for (auto [u, v] : edges) {
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (dist[i][j] < INF)
                ans = max(ans, dist[i][j]);
    return ans;
}

// Example usage:
// int n = 4;
// vector<pair<int,int>> edges = {{1,2},{2,3},{3,4}};
// int d = graph_diameter(n, edges); // d ==
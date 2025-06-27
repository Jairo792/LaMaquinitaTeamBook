/*
 * Union-Find (Disjoint Set Union - DSU)
 * Efficient operations for union and find on disjoint sets.
 * Supports path compression and union by size or rank.
 * Amortized complexity: O(alpha(n)) per operation
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
            parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (size[u] < size[v]) swap(u, v); // union by size
        parent[v] = u;
        size[u] += size[v];
        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }
};


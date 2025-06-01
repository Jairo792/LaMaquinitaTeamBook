#include <bits/stdc++.h>
using namespace std;
vector <int>tabla(10000);
int __find(int x) {
    if (tabla[x] != x)
        tabla[x] = __find(tabla[x]);
    return tabla[x];
}
void __union(int a, int b) {
    a = __find(a);
    b = __find(b);
    if (a != b)
      tabla[b] = a;
}
int main() {
    int n;
    scanf("%d", &n);
    vector<int> dx(n + 10);
    vector<int> dy(n + 10);
    vector<int> dr(n + 10);
    for (int i = 0; i < n;i++) {
        scanf("%d %d %d",&dx[i],&dy[i],&dr[i]);
        tabla[i] = i; 
    }
    for (int i = 0; i < n; i++) {
     for (int j = i + 1; j < n; j++) {
            int hx = dx[i] - dx[j];
            int hy = dy[i] - dy[j];
            double tagoras = abs(sqrt(pow(hx,2) + pow(hy,2)));
            if (tagoras <= dr[i] + dr[j]) {
                __union(i, j);
             }
          }
    }
    int ans = 0;
    for (int u = 0;u < n; u++) {
        if (__find(u) == u)
            ans++;
    }
    printf("%d\n",ans);
}


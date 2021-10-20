// https://cses.fi/problemset/task/1668
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int n, m, cnt = 0, d[N], f[N];
vector <int> a[N];
 
struct DSU
{
    int f[N];
    void init(int n) {for (int i = 1; i <= n; i++) f[i] = -1;}
    int rt(int u) {return f[u] < 0 ? u : f[u] = rt(f[u]);}
    bool kt(int u, int v) {return rt(u) == rt(v);}
    void mer(int u, int v)
    {
        if (kt(u, v)) return;
        int ru = rt(u), rv = rt(v);
        if (f[ru] > f[rv]) swap(ru, rv);
        f[ru] += f[rv];
        f[rv] = ru;
    }
} dsu;
 
void dfs(int x, int y)
{
    if (f[x])
    {
        if (f[x] != y)
        {
            cout << "IMPOSSIBLE"; exit(0);
        }
        return;
    }
    f[x] = y;
    for (int i : a[x])
        dfs(i, 3 - f[x]);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    dsu.init(n);
    for (int i = 1; i <= n; i++)
        if (!f[i]) dfs(i, 1);
    for (int i = 1; i <= n; i++) cout << f[i] << " ";
 
    return 0;
}

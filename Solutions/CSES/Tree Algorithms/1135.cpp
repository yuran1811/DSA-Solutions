// https://cses.fi/problemset/task/1135
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
 
const int N = 2e5 + 5, LOG = 20;
 
vector <int> a[N];
 
int subtask, n, m;
long long high[N], par[N][LOG + 1], d[N];
 
void dfs(int u)
{
    for (int v : a[u])
        if (v != par[u][0])
        {
            par[v][0] = u;
            d[v] = d[u] + 1;
            high[v] = high[u] + 1;
            dfs(v);
        }
}
 
void sparse_table()
{
    for (int j = 1; j <= LOG; j++)
        for (int i = 1; i <= n; i++)
            par[i][j] = par[par[i][j - 1]][j - 1];
}
 
int lca(int u, int v)
{
    if (high[u] < high[v]) swap(u, v);
    for (int i = LOG; i >= 0; i--)
        if (high[par[u][i]] >= high[v])
            u = par[u][i];
    if (u == v) return u;
 
    for (int i = LOG; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i],
            v = par[v][i];
    return par[u][0];
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v,
        a[u].push_back(v),
        a[v].push_back(u);
        
    dfs(1);
    sparse_table();
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        cout << d[u] + d[v] - 2 * d[lca(u, v)] << '\n';
    }
    return 0;
}

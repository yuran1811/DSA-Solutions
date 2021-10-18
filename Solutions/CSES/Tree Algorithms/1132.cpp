// https://cses.fi/problemset/task/1132
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
vector <int> a[N];
int g[N], f[N];
int degree[N];
int n, m;
 
bool mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}
 
void Load_Tree()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v,
        a[u].push_back(v),
        a[v].push_back(u);  
    for (int i = 1; i <= n; i++) degree[i] = a[i].size();
}
 
void Mnz_Tree()
{
    queue <int> q;
    for (int i = 1; i <= n; i++)
        if (degree[i] == 1) q.push(i);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : a[u])
            if (--degree[v] == 1) q.push(v);
    }
}
 
void calcF(int u, int p)
{
    f[u] = 0;
    for (int v : a[u])
        if (v != p)
        {
            calcF(v, u);
            mxm(f[u], f[v] + 1);
        }
}
 
void calcG(int u, int p)
{
    int F_fi = -1, F_se = -1;
    for (int v : a[u])
        if (v != p)
            f[v] > F_fi ? F_se = F_fi, F_fi = f[v] : mxm(F_se, f[v]);
 
    for (int v : a[u])
        if (v != p)
        {
            g[v] = max(1, g[u] + 1);
            mxm(g[v], (f[v] == F_fi ? F_se : F_fi) + 2);
            calcG(v, u);
        }
}
 
void Solve()
{
    calcF(1, -1);
    calcG(1, -1);
    for (int i = 1; i <= n; i++)
        cout << max(f[i], g[i]) << ' ';
}
 
int main()
{
    Load_Tree();
    Mnz_Tree();
    Solve();
    return 0;
}

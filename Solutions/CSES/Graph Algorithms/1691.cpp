// https://cses.fi/problemset/task/1691
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
 
int n, m;
vector <int> a[N], res;
 
struct DUS
{
    int f[N];
    void init(int n) {for (int i = 1; i <= n; i++) f[i] = -1;}
    int rt(int u) {return f[u] < 0 ? u : f[u] = rt(f[u]);}
    bool kt(int i, int j) {return rt(i) == rt(j);}
    void mer(int u, int v)
    {
        if (kt(u, v)) return;
        int ru = rt(u), rv = rt(v);
        if (f[ru] > f[rv]) swap(ru, rv);
        f[ru] += f[rv];
        f[rv] = ru;
    }
} dsu;
 
void eulerpath(int u)
{
    while (a[u].size())
    {
        int v = *a[u].begin();
        a[u].erase(a[u].begin());
        auto pos = find(a[v].begin(), a[v].end(), u);
        a[v].erase(pos);
        dsu.mer(u, v);
        eulerpath(v);
    }
    res.push_back(u);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    dsu.init(n);
    for (int i = 1, u, v; i <= m; i++)
    {   
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
 
    for (int i = 1; i <= n; i++)
        if (int (a[i].size()) % 2)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
 
    eulerpath(1);
    if (int (res.size()) != m + 1) 
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    for (int x : res) cout << x << " ";
    return 0;
}

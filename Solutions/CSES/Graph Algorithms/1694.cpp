// https://cses.fi/problemset/task/1694
#include <bits/stdc++.h>
using namespace std;
 
const int N = 505;
const long long oo = 2e18;
 
vector <int> a[N];
long long c[N][N], f[N][N];
int n, m, d[N], dfs[N], cnt = 0;
 
bool bfs()
{
    memset(d, 0, sizeof d); d[1] = 1;
    queue <int> q; q.push(1);
    while (q.size())
    {
        int u = q.front(); q.pop();
        if (u == n) return true;
        for (int v : a[u])
            if (!d[v] && f[u][v] < c[u][v]) 
                d[v] = d[u] + 1, q.push(v);
    }
    return false;
}
 
long long vs(int u, long long minn)
{
    if (u == n) return minn;
    if (dfs[u] != cnt) dfs[u] = cnt; else return 0;
    for (int v : a[u])
        if (f[u][v] < c[u][v])
            if (dfs[v] != cnt && d[v] == d[u] + 1)
                if (long long x = vs(v, min(minn, c[u][v] - f[u][v])))
                {
                    f[u][v] += x;
                    f[v][u] -= x;
                    return x;
                }
    return 0;
}
 
void dinic()
{
    long long res = 0;
    while (bfs())
        while (long long x = (cnt++, vs(1, oo)))
            res += x;
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        a[u].push_back(v);
        a[v].push_back(u);
        c[u][v] += w;
        // c[v][u] += w;
    }
 
    dinic();
    return 0;
}

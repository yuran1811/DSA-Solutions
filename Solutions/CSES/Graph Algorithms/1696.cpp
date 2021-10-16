// https://cses.fi/problemset/task/1696
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, oo = 1e9 + 7;
 
int n, m, k;
vector <int> a[N];
int mx[N], my[N], d[N];
vector <pair <int, int>> ans;
 
bool bfs()
{
    queue <int> q;
    for (int u = 1; u <= n; u++)
        if (!mx[u]) d[u] = 0, q.push(u);
        else d[u] = oo;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : a[u])
            if (!my[v]) return true; else
            if (d[my[v]] == oo)
                d[my[v]] = d[u] + 1, q.push(my[v]);
    }
    return false;
}
 
bool match(int u)
{
    if (d[u] == oo) return false;
    for (int v : a[u])
        if (!my[v] || (d[my[v]] == d[u] + 1 && match(my[v])))
        {
            mx[u] = v;
            my[v] = u;
            return true;
        }
    return false;
}
 
void matching()
{
    int res = 0;
    while (bfs())
        for (int u = 1; u <= n; u++)
            if (!mx[u]) res += match(u);
    cout << res << '\n';
    for (int i = 1; i <= n; i++)
        if (mx[i]) cout << i << " " << mx[i] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k; 
    for (int i = 1, u, v; i <= k; i++)
        cin >> u >> v,
        a[u].push_back(v);
    matching();
    return 0;
}

// https://cses.fi/problemset/task/1666
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
vector <int> a[N], res;
int n, m, d[N];
 
void bfs(int i)
{
    queue <int> q; q.push(i);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : a[u])
            if (!d[v])
                d[v] = u, q.push(v);
    }
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
 
    for (int i = 1; i <= n; i++)
        if (!d[i]) bfs(i), res.push_back(i);
 
    cout << int (res.size()) - 1 << '\n';
    for (int i = 0; i < int (res.size()) - 1; i++)
        cout << res[i] << " " << res[i + 1] << '\n';
    return 0;
}

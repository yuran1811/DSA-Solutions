// https://cses.fi/problemset/task/1672
#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const long long oo = 1e18;
 
int n, m, q;
long long a[N][N];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = (i == j ? 0 : oo);
 
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        a[u][v] = a[v][u] = min(a[v][u], 1LL * w);
    }
 
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
 
    for (int i = 1, u, v; i <= q; i++)
    {
        cin >> u >> v;
        cout << (a[u][v] != oo ? a[u][v] : -1) << '\n';
    }
    return 0;
}

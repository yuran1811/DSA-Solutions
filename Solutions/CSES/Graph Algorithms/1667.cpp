// https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
vector <int> a[N];
int n, m, d[N];
 
bool bfs()
{
    queue <int> q; q.push(1);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : a[u])
            if (!d[v])
            {
                d[v] = u, q.push(v);
                if (v == n) return true;
            }
    }
    return false;
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
 
    if (!bfs()) cout << "IMPOSSIBLE"; else
    {
        vector <int> res;
        do
        {
            res.push_back(n);
            n = d[n];
        } while (n != 1);
        res.push_back(1);
        reverse(res.begin(), res.end());
        cout << int (res.size()) << '\n';
        for (int i : res) cout << i << " ";
    }
    return 0;
}

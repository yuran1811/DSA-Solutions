// https://cses.fi/problemset/task/1671
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const long long oo = 1e18;
 
int n, m;
vector <pair <int, int>> a[N];
 
void dijk(int s, int t)
{
    priority_queue <pair <long long, int>> q;
    vector <long long> d(n + 1, oo); d[s] = 0;
    q.push({0, s}); 
 
    while (q.size())
    {
        int u = q.top().second;
        long long du = -q.top().first;
        q.pop();
 
        if (du != d[u]) continue;
 
        for (auto x : a[u])
            if (d[x.first] > d[u] + x.second)
                d[x.first] = d[u] + x.second, q.push({-d[x.first], x.first});
    }
    for (int i = 1; i <= n; i++) cout << d[i] << " ";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++)
        cin >> u >> v >> w,
        a[u].push_back({v, w});
    dijk(1, n);
    return 0;
}

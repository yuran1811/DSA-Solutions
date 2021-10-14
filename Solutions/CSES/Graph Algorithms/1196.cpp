// https://cses.fi/problemset/task/1196
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
 
typedef long long ll;
typedef pair <ll, int> pii;
 
int n, m, k, cnt[N];
vector <pair <int, int>> a[N];
 
void dijk()
{
    priority_queue <pii, vector <pii>, greater <pii>> q;
    q.push({0, 1});
    while (q.size())
    {
        int u = q.top().second;
        ll du = q.top().first;
        q.pop();
 
        if (cnt[u] == k) continue;
        cnt[u]++;
        
        if (u == n) 
        {
            cout << du << ' ';
            if (cnt[n] == k) exit(0);
        }
        for (auto x : a[u]) q.push({du + x.second, x.first});
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("I.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1, u, v, c; i <= m; i++)
    {
        cin >> u >> v >> c;
        a[u].push_back({v, c});
    }
    dijk();
    return 0;
}

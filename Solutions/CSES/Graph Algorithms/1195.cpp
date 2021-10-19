// https://cses.fi/problemset/task/1195
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, int> plli;
 
const int N = 1e6 + 5;
const ll oo = 1e18 + 5LL;
 
struct Edge {int u, v, c;} e[N];
vector <pii> a[N], b[N];
vector <ll> d1, d2;
int n, m, cnt[N];
 
ll mnz(ll &a, ll b) {return a > b ? a = b, 1 : 0;}
 
void Dijk(int s, vector <ll> &d, vector <pii> a[])
{
    priority_queue <plli> q; q.push({0, s});
    d.assign(n + 5, oo); d[s] = 0;
    vector <bool> Vst(n + 5, 0);
    
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (Vst[u]) continue; 
        Vst[u] = 1;
 
        for (pii x : a[u])
        	if (mnz(d[x.first], d[u] + x.second))
        		q.push({-d[x.first], x.first});
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v, c; i <= m; i++)
    {
        cin >> u >> v >> c;
        e[i] = {u, v, c};
        a[u].push_back({v, c});
        b[v].push_back({u, c});
    }
    Dijk(1, d1, a);
    Dijk(n, d2, b);
    ll res = oo;
    for (int i = 1; i <= m; i++)
    	mnz(res, d1[e[i].u] + d2[e[i].v] + e[i].c / 2);
    cout << res;
    return 0;
}

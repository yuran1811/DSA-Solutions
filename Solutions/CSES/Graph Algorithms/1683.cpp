// https://cses.fi/problemset/task/1683
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5, oo = 1e9 + 7;
 
int n, m, pos[N];
vector <int> a[N];
 
int Low[N], Num[N], cnt = 0;
stack <int> s;
 
int sz = 0;
vector <int> res[N];
 
void tj(int u)
{
    Low[u] = Num[u] = ++cnt;
    s.push(u);
    for (int v : a[u])
        if (!Num[v])
        {
            tj(v); Low[u] = min(Low[u], Low[v]);
        } else     Low[u] = min(Low[u], Num[v]);
 
    if (Low[u] == Num[u])
    {
        sz++;
        int V;
        do
        {
            V = s.top(); s.pop();
            Num[V] = Low[V] = oo;
            pos[V] = sz;
        } while (V != u);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
        cin >> u >> v, a[u].push_back(v);
    for (int i = 1; i <= n; i++)
        if (!Num[i]) tj(i);
    cout << sz << '\n';
    for (int i = 1; i <= n; i++) cout << pos[i] << " ";
    return 0;
}

// https://cses.fi/problemset/task/1673
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int N = 2600, oo = 1e9 + 7;
 
int n, m, x, y, z, kt;
 
struct graph {int u, v, c;};
vector <graph> ar(N * 2);

vector <bool> f1(N, 0), f2(N, 0);
vector <vector <int>> a(N), b(N);
vector <ll> d(N, 1e18);
 
void visit(vector <vector <int>> f, vector <bool> &ff, int g)
{
    ff[g] = true;
    for (int y: f[g])
        if (!ff[y])
            visit(f, ff, y);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
 
    for (int i=1; i<=m; i++)
    {
        cin >> x >> y >> z;
        a[x].push_back(y);
        b[y].push_back(x);
        ar[i]={x, y, -z};
    }
 
    visit(a, f1, 1);
    visit(b, f2, n);
 
    d[1]=kt=0;
    for (int i=1; i<=n; i++)
        for (graph x: ar)
            if (f1[x.u] && f2[x.v] && (d[x.u]+x.c < d[x.v]))
            {        
                d[x.v] = d[x.u] + x.c;
                if (i == n) kt = 1;
            }
    if (!kt) cout << -d[n]; else cout << -1;
    return 0;
}

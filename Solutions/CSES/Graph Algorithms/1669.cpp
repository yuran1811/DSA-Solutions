// https://cses.fi/problemset/task/1669
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int n, m;
int Start, End;
vector <int> Par, Vst, a[N];
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
}
 
bool DFS(int v, int p)
{
	Vst[v] = true;
    for (int u : a[v])
    {
        if (u == p) continue;
        if (Vst[u])
        {
            End = v;
            Start = u;
            return true;
        }
        Par[u] = v;
        if (DFS(u, Par[u])) return true;
    }
    return false;
}
 
void Searching()
{
    Vst.assign(n + 5, 0);
    Par.assign(n + 5, -1);
    Start = -1;
 
    for (int v = 0; v < n; v++)
        if (!Vst[v] && DFS(v, Par[v])) break;
 
    if (Start == -1) return void (cout << "IMPOSSIBLE" << endl); 
 
    vector <int> cycle;
    cycle.push_back(Start);
    for (int v = End; v != Start; v = Par[v]) cycle.push_back(v);
    cycle.push_back(Start);
    reverse(cycle.begin(), cycle.end());
 
    cout << cycle.size() << '\n';
    for (int v : cycle) cout << v << " ";
}
 
int Solve()
{
	Load_Data();
	Searching();
	return 0;
}
 
int main() {Solve();}

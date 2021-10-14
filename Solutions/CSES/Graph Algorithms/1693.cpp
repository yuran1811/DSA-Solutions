// https://cses.fi/problemset/task/1693
#include <algorithm>
#include <iostream>
#include <vector>
#define sz(s) (int (s.size()))
using namespace std;
 
const int N = 1e5 + 5;
 
int n, m, In[N], Out[N];
vector <int> res, a[N];
 
void DFS(int u)
{
    while (sz(a[u]))
    {
        int v = a[u].back();
        a[u].pop_back();
        DFS(v);
    }
    res.push_back(u);
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, a[u].push_back(v), 
		In[v]++, Out[u]++;
}
 
int Solve()
{
	Load_Data();
	int a = 0, b = 0, c = 0, Start = 0, End = 0;
    for (int i = 1; i <= n; i++)
    {
        if (In[i] == Out[i]) c++;
        if (In[i] == Out[i] + 1) b++, End = i;
        if (In[i] + 1 == Out[i]) a++, Start = i;
    }
    if ((Start != 1 || End != n) || (!(c == n - 2 && a == 1 && b == 1))) return cout << "IMPOSSIBLE", 0;
    
    DFS(1);
    if (sz(res) != m + 1) return cout << "IMPOSSIBLE", 0;
    reverse(res.begin(), res.end()); for (auto x : res) cout << x << " ";
	return 0;
}
 
int main() {Solve();}

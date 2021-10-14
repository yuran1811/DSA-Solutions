// https://cses.fi/problemset/task/1682
#include <iostream>
#include <vector>
using namespace std;
 
const int N = 1e5 + 5;
 
int n, m;
 
struct Find_Path
{
	vector <int> a[N];
	vector <bool> Vst;
	
	void DFS(int u)
	{
		for (int v : a[u])
			if (!Vst[v])
				Vst[v] = 1, DFS(v);
	}		
 
	void Check(int n, bool c)
	{
		Vst.assign(n + 1, 0);
		DFS(1);
		for (int i = 2; i <= n; i++)
			if (!Vst[i]) 
			{
				if (c) {cout << "NO\n1 " << i; exit(0);}
				cout << "NO\n" << i << " " << 1; exit(0);
			}
	}
} a, b;
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v,
		a.a[u].push_back(v),	
		b.a[v].push_back(u);	
}
 
int Solve()
{
	Load_Data();
	a.Check(n, 1);
	b.Check(n, 0);
	return cout << "YES", 0;
}
 
int main() {Solve();}

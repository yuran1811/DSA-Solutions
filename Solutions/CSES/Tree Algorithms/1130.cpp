// https://cses.fi/problemset/task/1130
#include <iostream>
#include <vector>
using namespace std;
 
const int N = 2e5 + 5;
 
vector <int> a[N];
vector <bool> Vst;
int n, Res = 0;
 
void DFS(int u, int p)
{
	for (int v : a[u])
		if (v != p)
		{
			DFS(v, u);
			if (!Vst[u] && !Vst[v]) 
				Res++, Vst[u] = Vst[v] = 1;
		}
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; Vst.assign(n + 1, 0);
	for (int i = 2, u, v; i <= n; i++)
		cin >> u >> v, 
		a[u].push_back(v),
		a[v].push_back(u);
}
 
int Solve()
{
	Load_Data();
	DFS(1, -1);
	cout << Res;
	return 0;
}
 
int main() {Solve();}

// https://cses.fi/problemset/task/1133
#include <iostream>
#include <vector>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5 + 5;
 
vector <int> a[N];
ll NumChild[N];
ll SumDis[N];
int n;
 
void DFS(int u, int p)
{
	NumChild[u] = 1;
	for (int v : a[u])
	{
		if (v == p) continue;
		DFS(v, u);
		NumChild[u] += NumChild[v];
		SumDis[u] += SumDis[v] + NumChild[v];
	}
}
 
void Calc_SumDis(int u, int p)
{
	if (u ^ p)
		SumDis[u] += SumDis[p] - SumDis[u] + NumChild[p] - 2 * NumChild[u], 
		NumChild[u] += NumChild[p] - NumChild[u];
	for (int v : a[u])
		if (v ^ p) Calc_SumDis(v, u);
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
}
 
int Solve()
{
	Load_Data();
	DFS(1, 1);
	Calc_SumDis(1, 1);
	for (int i = 1; i <= n; i++)
		cout << SumDis[i] << " ";
	return 0;
}
 
int main() {Solve();}

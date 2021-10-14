// https://cses.fi/problemset/task/1711
#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#define sz(s) (int (s.size()))
using namespace std;
 
const int N = 501;
 
struct Edge
{
	bool used; int to; int rev; bool isRev;
	Edge(bool u, int t, int r, bool i) : used(u), to(t), rev(r), isRev(i) {};
};
 
vector <bitset <N>> f[N];
vector <Edge> a[N];
int n, m, MaxFlow;
bool Vst[N];
 
bool DFS(int u)
{
	Vst[u] = 1;
	for (Edge &e : a[u])
		if (!e.used && !Vst[e.to])
			if (e.to == n || DFS(e.to))
				return a[e.to][e.rev].used = 0, MaxFlow += e.to == n, e.used = 1, 1;
	return 0;
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v,
		a[u].push_back(Edge(0, v, sz(a[v]), 0)),
		a[v].push_back(Edge(1, u, sz(a[u]) - 1, 1));	
}
 
void Recall()
{
	vector <int> path; int vertex = 1;
	while (vertex != n)
	{
		path.push_back(vertex);
		for (Edge &e : a[vertex])
			if (!e.isRev && e.used)
			{
				e.used = 0;
				vertex = e.to;
				break;
			}
	}
	path.push_back(n);
	cout << sz(path) << '\n';
	for (int u : path) cout << u << " ";
	cout << '\n';
}
 
int Solve()
{
	Load_Data();
	do memset(Vst, 0, sizeof Vst); while (DFS(1));
	cout << MaxFlow << '\n';
	for (int i = 1; i <= MaxFlow; i++) Recall();
	return 0;	
}
 
int main() {Solve();}

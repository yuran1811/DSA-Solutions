// https://cses.fi/problemset/task/1690
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
 
const int N = 30, MOD = 1e9 + 7;
 
vector <int> a[N];
int n, m;
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++)
		cin >> u >> v, a[u - 1].push_back(v - 1);
}
 
void Plus(int &x, int b) {x += b; x -= (x > MOD ? MOD : 0);}
 
void DP()
{
	m = 1 << n;
	vector <vector <int>> f(n + 5, vector <int> (m + 5, 0));
	f[0][1] = 1;
	for (int e = 0; e < m; e++)
		for (int u = 0; u < n; u++)
			if ((e & (1 << u)) && f[u][e])
				for (int v : a[u])
					if (!(e & (1 << v)))
						Plus(f[v][e ^ (1 << v)], f[u][e]);
	cout << f[n - 1][m - 1];
}
 
int Solve()
{
	Load_Data(); DP();
	return 0;
}
 
int main() {Solve();}

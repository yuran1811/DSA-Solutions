// https://cses.fi/problemset/task/1687
#include <iostream>
using namespace std;
 
const int N = 2e5 + 5, LOG = 20;
 
int par[N][LOG + 5];
int n, q;
 
void Sparse_Table()
{
	for (int j = 1; j <= LOG; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];
}
 
int Ancesstor(int u, int k)
{
	int cnt = 0;
	for (; k > 0; k >>= 1, cnt++)
		u = k & 1 ? par[u][cnt] : u;
	return u ? u : -1;
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int u = 2; u <= n; u++)
		cin >> par[u][0];
	Sparse_Table();
}
 
int Solve()
{
	Load_Data();
	for (int i = 1, u, k; i <= q; i++)
		cin >> u >> k, cout << Ancesstor(u, k) << '\n';
	return 0;
}
 
int main() {Solve();}

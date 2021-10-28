// https://cses.fi/problemset/task/1746
#include <iostream>
using namespace std;
 
const int N = 1e5 + 5, MOD = 1e9 + 7;
 
int a[N], f[N][105];
int n, m;
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i];
}
 
void Add(int &a, int b) {a += b; a -= a >= MOD ? MOD : 0;}
 
int Solve()
{
	Load_Data();
	if (a[1]) f[1][a[1]] = 1; else
	for (int i = 1; i <= m; i++) f[1][i] = 1;
 
	for (int i = 2; i <= n; i++)
		if (a[i])
		{
			for (int j = -1; j <= 1; j++)
				if (1 <= a[i] + j && a[i] + j <= m)
					Add(f[i][a[i]], f[i - 1][a[i] + j]);
		} else
		{
			for (int k = 1; k <= m; k++)
				for (int j = -1; j <= 1; j++)
					if (1 <= k + j && k + j <= m)
						Add(f[i][k], f[i - 1][k + j]);
		}
 
	int res = 0;
	for (int i = 1; i <= m; i++) Add(res, f[n][i]);
	return cout << res, 0;
}
 
int main() {Solve();}

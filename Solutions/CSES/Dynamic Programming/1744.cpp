// https://cses.fi/problemset/task/1744
#include <iostream>
using namespace std;
 
const int N = 505, oo = 1e9 + 7;
 
int f[N][N];
int n, m;
 
int mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
}
 
int Solve()
{
	Load_Data();
	for (int i = 1; i <= min(n, m); i++)
		for (int j = i + 1; j <= max(n, m); j++)
		{
			f[i][j] = oo;
			for (int k = 1; k < i; k++) mnz(f[i][j], f[k][j] + f[i - k][j] + 1);
			for (int k = 1; k < j; k++) mnz(f[i][j], f[i][k] + f[i][j - k] + 1);
			f[j][i] = f[i][j];
		}
	cout << f[min(n, m)][max(n, m)];
	return 0;
}
 
int main() {Solve();}

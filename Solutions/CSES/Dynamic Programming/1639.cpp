// https://cses.fi/problemset/task/1639
#include <bits/stdc++.h>
using namespace std;
 
const int N = 5005;
 
int n, m, f[N][N];
string s, t;
 
int mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}
int mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> t; n = s.size(); m = t.size();
}
 
int Solve()
{
	Load_Data();
	for (int i = 1; i <= n; i++) f[i][0] = i;
	for (int i = 1; i <= m; i++) f[0][i] = i;
 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = min({f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + (s[i - 1] != t[j - 1])});
	cout << f[n][m];
	return 0;
}
 
int main() {Solve();}

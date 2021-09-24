#include <iostream>
#include <string>
#define SBSTR(s, l) (s.substr(0, l))
#define sz(s) (int (s.size()))
using namespace std;
 
typedef long long ll;
 
const int MOD = 1e9 + 7;
 
ll f[1005][105], lth[105][26];
int n, m;
string s;
 
ll Pow(ll a, ll b)
{
	if (!b) return 1;
	if (b == 1) return a;
	ll c = Pow(a, b / 2);
	c = c * c % MOD;
	return (b & 1) ? c * a % MOD : c;
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s; m = s.size();
}
 
void Init()
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 26; j++)
		{
			string pre = SBSTR(s, i); pre += j + 'A';
			lth[i][j] = 0;
			for (int k = 0; k < sz(pre); k++)
				if (pre.substr(k) == SBSTR(s, sz(pre) - k))
					{lth[i][j] = sz(pre) - k; break;}
		}
}
 
void DP()
{
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 26; k++)
				(f[i][lth[j][k]] += f[i - 1][j]) %= MOD;
}
 
int Solve()
{
	Load_Data(); Init(); DP();
	ll res = Pow(26, n);
	for (int i = 0; i < m; i++) res = (res - f[n][i] + MOD) % MOD;
	return cout << res, 0;
}    
 
int main() {Solve();}

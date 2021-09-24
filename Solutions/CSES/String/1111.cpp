#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll BASE = 311, MOD = 1e9 + 7, N = 2e6 + 5;
 
ll Pow[N], H1[N], H2[N];
int n, res = 0;
string s;
 
void build()
{
	Pow[0] = 1;
	for (int i = 1; i <= n; i++)
		Pow[i] = Pow[i - 1] * BASE % MOD,
		H1[i] = (H1[i - 1] * BASE + s[i]) % MOD,
		H2[i] = (H2[i - 1] * BASE + s[n - i + 1]) % MOD;
}
 
ll get1(int i, int j) {return (H1[j] - H1[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;}
ll get2(int i, int j) {return (H2[n - i + 1] - H2[n - j] * Pow[j - i + 1] + MOD * MOD) % MOD;}

bool Check(int mid)
{
	for (int i = 1; i <= n - mid + 1; i++)
		if (get1(i, i + mid - 1) == get2(i, i + mid - 1))
			return true;
	return false;
}

void Find(int l, int r, int k)
{
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (mid % 2 && k) mid++; else
		if (mid % 2 == 0 && !k) mid++;
		
		if (Check(mid)) l = mid;
		else r = mid - 2;
	}
	res = max(res, l);
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s; s = " " + s; n = s.size(); build();
	Find(1, n - (n % 2 == 0), 0);
	Find(0, n - n % 2, 1);
	for (int i = 1; i <= n - res + 1; i++)
		if (get1(i, i + res - 1) == get2(i, i + res - 1))
			return cout << s.substr(i, res), 0;
	return 0;
}

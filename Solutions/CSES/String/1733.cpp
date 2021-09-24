#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

const int N = 2e6 + 5;
const ll BASE = 311, MOD = 1e9 + 7;
 
ll Pow[N];
string s;
int n;
 
struct HASH
{
	ll Hash[N];
 
	void in(string s, int &n)
	{
		n = s.size();
		s = " " + s;
		for (int i = 1; i <= n; i++)
			Hash[i] = (Hash[i - 1] * BASE + s[i] - 'a' + 1) % MOD;
	}
 
	ll get(int i, int j) {return (Hash[j] - Hash[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;}
} H;
 
void build()
{
	Pow[0] = 1;
	for (int i = 1; i < N; i++)
		Pow[i] = Pow[i - 1] * BASE % MOD;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s; build(); H.in(s, n);
	for (int i = 1; i <= n; i++)
		if (H.get(1, n - i) == H.get(i + 1, n))
			cout << i << " ";
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 5;
const ll BASE = 311, MOD = 1e9 + 7;

ll Pow[N], Hash[N];
string s;
int n;

void Build(int n)
{
	Pow[0] = 1;
	for (int i = 1; i <= n; i++)
		Pow[i] = Pow[i - 1] * BASE % MOD,
		Hash[i] = (Hash[i - 1] * BASE + s[i]) % MOD;
}

ll get(int i, int j) {return (Hash[j] - Hash[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s; n = s.size(); s = " " + s;
	Build(n);
	for (int i = 1; i < n; i++)
		if (get(1, i) == get(n - i + 1, n))
			cout << i << " ";
	return 0;
}

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define avr(a, b) ((a + b) >> 1)
#define E (int) 1e9 + 
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const ll BASE = 311, K = 3;
const ll MOD[] = {E 1927, E 1957, E 1963};

ll Pow[N][K];
string s, t;
int n;

void buildPow(int n)
{
	for (int nmod = 0; nmod < K; nmod++)
	{
		Pow[0][nmod] = 1;
		for (int i = 1; i <= n; i++)
			Pow[i][nmod] = Pow[i - 1][nmod] * BASE % MOD[nmod];
	}
}

struct Hashing
{
	ll val[K];

	Hashing() {memset(val, 0, sizeof val);}
	Hashing(char x) {for (int i = 0; i < K; i++) val[i] = x;}

	Hashing operator + (const Hashing &x) const 
	{
		Hashing res;
		for (int nmod = 0; nmod < K; nmod++) 
		{
			res.val[nmod] = val[nmod] + x.val[nmod];
			if (res.val[nmod] >= MOD[nmod]) res.val[nmod] -= MOD[nmod];
		}
		return res;
	}

	Hashing operator - (const Hashing &x) const 
	{
		Hashing res;
		for (int nmod = 0; nmod < K; nmod++) 
		{
			res.val[nmod] = val[nmod] - x.val[nmod];
			if (res.val[nmod] < 0) res.val[nmod] += MOD[nmod];
		}
		return res;
	}

	Hashing operator * (int k) const 
	{
		Hashing res;
		for (int nmod = 0; nmod < K; nmod++) 
			res.val[nmod] = val[nmod] * Pow[k][nmod] % MOD[nmod];
		return res;
	}

	bool operator < (const Hashing &x) const 
	{
		for (int nmod = 0; nmod < K; nmod++) 
			if (val[nmod] != x.val[nmod]) 
				return val[nmod] < x.val[nmod];
		return false;
	}
	bool operator == (const Hashing &x) const 
	{
		for (int nmod = 0; nmod < K; nmod++) 
			if (val[nmod] != x.val[nmod]) 
				return false;
		return true;
	}
};

struct _HASH_
{
	vector <Hashing> Hash;
	string s;
	int n;

	void build(string x)
	{
		n = x.size();
		s = " " + x;
		Hash.resize(n + 1);
		for (int i = 1; i <= n; i++)
			Hash[i] = Hash[i - 1] + Hashing(s[i]) * i;
	}   

	Hashing get(int i, int j) {return (Hash[j] - Hash[i - 1]) * (n - j);}
} H1, H2;

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> t; n = s.size();
	buildPow(n); H1.build(s); H2.build(t);
}

int main() {Load_Data(); return 0;}

#include <iostream>
#define sz(s) (int (s.size()))
using namespace std;

const int N = 1e6 + 5, M = 5005, MOD = 1e9 + 7;

struct Trie
{
	int Next[N][26], End[N], sz = 0;
	void Add(string s)
	{
		int pos = 0;
		for (char c : s)
		{
			if (!Next[pos][c - 'a'])
				Next[pos][c - 'a'] = ++sz;
			pos = Next[pos][c - 'a'];
		}
		End[pos] = 1;
	}
} T;

int f[M], k;
string s, t;

void Add(int &a, int b) {a += b; a -= (a > MOD ? MOD : 0);}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> k; while (k--) cin >> t, T.Add(t);

	f[0] = 1;
	for (int i = 0; i < sz(s); i++)
	{
		int cur = 0;
		for (int j = i; j < sz(s); j++)
		{
			cur = T.Next[cur][s[j] - 'a'];
			if (!cur) break;
			if (T.End[cur]) Add(f[j + 1], f[i]);
		}
	}
	cout << f[sz(s)];
	return 0;
}

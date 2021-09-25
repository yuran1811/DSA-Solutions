#include <iostream>
using namespace std;

const int N = 1e5 + 5;

int n, a[N];

struct Lazy
{
	int lz[4 * N];
	int t[4 * N];

	void Build(int l, int r, int i)
	{
		if (l == r) return void (t[i] = a[l]);
		int m = (l + r) >> 1;
		Build(l, m, i << 1);
		Build(m + 1, r, i << 1 | 1);
		t[i] = t[i << 1] + t[i << 1 | 1];
	}

	void Down(int i)
	{
		int &val = lz[i];
		t[i << 1] += val;
		t[i << 1 | 1] += val;
		val = 0;
	}

	void Up(int l, int r, int i, int u, int v, int val)
	{
		if (v < l || r < u) return;
		if (l == r)
		{
			t[i] += (r - l + 1) * val;
			lz[i] += val;
			return;
		}
		Down(i);
		int m = (l + r) >> 1;
		Up(l, m, i << 1, u, v, val);
		Up(m + 1, r, i << 1 | 1, u, v, val);
		t[i] = t[i << 1] + t[i << 1 | 1];		
	}

	int Get(int l, int r, int i, int u, int v)
	{
		if (v < l || r < u) return 0;
		if (u <= l && r <= v) return t[i];
		Down(i);
		int m = (l + r) >> 1;
		return Get(l, m, i << 1, u, v) + Get(m + 1, r, i << 1 | 1, u, v);
	}
} T;

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];
	T.Build(1, n, 1);
}

int Scorpio()
{
	Load_Data();
	int q; cin >> q;
	while (q--)
	{
		int c, u, v, val;
		cin >> c >> u >> v;
		if (c) cout << T.Get(1, n, 1, u, v) << '\n';
		else cin >> val, T.Up(1, n, 1, u, v, val);
	}
	return 0;
}

int main() {Scorpio();}

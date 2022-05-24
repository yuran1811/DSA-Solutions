#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

struct SegTree
{
	int t[4 * N];

	void Build(int l, int r, int i)
	{
		if (l == r) return void (t[i] = a[l]);

		int m = (l + r) >> 1;
		Build(l, m, i << 1);
		Build(m + 1, r, i << 1 | 1);

		t[i] = t[i << 1] + t[i << 1 | 1];
	}

	void Up(int l, int r, int i, int pos, int val)
	{
		if (pos < l || r < pos) return;
		if (l == r) return void (t[i] = val);

		int m = (l + r) >> 1;
		Up(l, m, i << 1, pos, val);
		Up(m + 1, r, i << 1 | 1, pos, val);

		t[i] = t[i << 1] + t[i << 1 | 1];		
	}

	int Get(int l, int r, int i, int u, int v)
	{
		if (v < l || r < u) return 0;
		if (u <= l && r <= v) return t[i];

		int m = (l + r) >> 1;
		return Get(l, m, i << 1, u, v) + Get(m + 1, r, i << 1 | 1, u, v);
	}
} T;

void loadData()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	T.Build(1, n, 1);
}

int Solve()
{
	loadData();
	return 0;
}

int main() { Solve(); }
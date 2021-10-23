// https://cses.fi/problemset/task/1076
#include <algorithm>
#include <iostream>
#include <vector>
#define fi first
#define se second
using namespace std;

const int N = 2e5 + 5, oo = 1e9 + 7;

pair <int, int> a[N];
int b[N], Node_Id[N];
int n, k, median;

struct SegTree
{
	struct Node
	{
		int val, pos;
		Node operator + (const Node &b) const
		{
			return Node ({val + b.val, max(pos, b.pos)});
		}
	} t[4 * N];

	void Init(int n) {for (int i = 1; i <= 4 * n; i++) t[i] = {0, -oo};}

	void Up(int l, int r, int i, int pos, int val)
	{
		if (pos < l || r < pos) return;
		if (l == r)
		{
			t[i].val += val;
			t[i].pos = (val < 0 ? -oo : pos);
			return;
		}
		int m = (l + r) >> 1;
		Up(l, m, i << 1, pos, val);
		Up(m + 1, r, i << 1 | 1, pos, val);
		t[i] = t[i << 1] + t[i << 1 | 1];
	}

	Node Get(int l, int r, int i, int k)
	{
		if (t[i].val <= k) return t[i];
		if (l == r)
		{
			if (t[i].val != k) return {oo, -oo};
			return t[i];
		}
		int m = (l + r) >> 1;
		if (k <= t[i << 1].val) return Get(l, m, i << 1, k);
		return Get(m + 1, r, i << 1 | 1, k - t[i << 1].val) + t[i << 1];
	}
} T;

void Compress()
{
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		Node_Id[i] = a[i].fi, 
		b[a[i].se] = i;
}

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i].fi, a[i].se = i;
	Compress();
}

int Solve()
{
	Load_Data();
	T.Init(n);
	median = (k + 1) >> 1;
	for (int i = 1; i <= k; i++) T.Up(1, n, 1, b[i], 1);
	for (int i = k + 1; i <= n + 1; i++)
	{
		cout << Node_Id[T.Get(1, n, 1, median).pos] << " ";
		T.Up(1, n, 1, b[i], 1);
		T.Up(1, n, 1, b[i - k], -1);
	}
	return 0;
}

int main() {Solve();}

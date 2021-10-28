// https://cses.fi/problemset/task/1145
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
vector <int> a, b;
int n;
 
int mxm(int &a, int b) {return a < b ? a = b, 1 : 0;}
 
struct BIT
{
	vector <int> bit;
	void Init(int n) {bit.assign(n + 1, 0);}
	void Up(int i, int val) {for (; i <= n; i += -i & i) mxm(bit[i], val);}
	int Get(int i)
	{
		int res = 0;
		for (; i > 0; i -= -i & i) mxm(res, bit[i]);
		return res;
	}
} T;
 
void Compress()
{
	b = a; sort(b.begin(), b.end());
	for (int &x : a)
		x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; a.resize(n); for (int &x : a) cin >> x;
	Compress();
}
 
int Solve()
{
	Load_Data();
	T.Init(n);
	for (int x : a) T.Up(x, T.Get(x - 1) + 1);
	cout << T.Get(n);
	return 0;
}
 
int main() {Solve();}

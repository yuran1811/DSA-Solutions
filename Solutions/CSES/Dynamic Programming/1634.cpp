// https://cses.fi/problemset/task/1634
#include <iostream>
#include <vector>
using namespace std;
 
typedef long long ll;
 
const int N = 2e6 + 5, oo = 1e9 + 7;
 
int n, Sum, a[N];
 
ll mnz(ll &a, ll b) {return a > b ? a = b, 1 : 0;}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> Sum; for (int i = 1; i <= n; i++) cin >> a[i];
}
 
void DP()
{
	vector <ll> f(Sum + 1, oo); f[0] = 0;
	for (int i = 1; i <= Sum; i++)
		for (int j = 1; j <= n; j++)
			if (a[j] <= i) mnz(f[i], f[i - a[j]] + 1);
	cout << (f[Sum] < oo ? f[Sum] : -1);
}
 
int Solve()
{
	Load_Data(); DP();
	return 0;
}
 
int main() {Solve();}

// https://cses.fi/problemset/task/1636
#include <iostream>
#include <vector>
using namespace std;
 
const int MOD = 1e9 + 7;
 
vector <int> f;
int n, Sum;
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> Sum; f.assign(Sum + 1, 0); f[0] = 1;
	for (int i = 1, x; i <= n; i++)
	{
		cin >> x;
		for (int j = x; j <= Sum; j++)
			f[j] = (f[j] % MOD + f[j - x] % MOD) % MOD;
	}
}
 
int Solve()
{
	Load_Data();
	cout << f[Sum];
	return 0;
}
 
int main() {Solve();}

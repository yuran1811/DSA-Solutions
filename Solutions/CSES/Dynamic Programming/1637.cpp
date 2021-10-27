// https://cses.fi/problemset/task/1637
#include <iostream>
#include <vector>
using namespace std;
 
typedef long long ll;
 
const int N = 1e6 + 5, oo = 1e9 + 7;
 
int n, res = oo;
 
int mnz(int &a, int b) {return a > b ? a = b, 1 : 0;}
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
}
 
void Analyzing(int n, vector <int> &a) {a.clear(); while (n) a.push_back(n % 10), n /= 10;}
 
void DP()
{
	vector <int> f(n + 5, oo), a; f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		Analyzing(i, a);
		for (int x : a) mnz(f[i], f[i - x] + 1);
	}
	cout << f[n];
}
 
int Solve()
{
	Load_Data(); DP();
	return 0;
}
 
int main() {Solve();}

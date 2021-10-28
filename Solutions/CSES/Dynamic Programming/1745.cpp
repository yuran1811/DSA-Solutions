// https://cses.fi/problemset/task/1745
#include <iostream>
#include <vector>
using namespace std;
 
const int N = 105, M = 1e5;
 
int n, MaxVal, f[M + 5];
vector <int> S;
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
}
 
int Solve()
{
	Load_Data();
	f[0] = 1;
	for (int i = 1, a; i <= n; i++)
	{
		cin >> a;
		for (int j = M; j >= a; j--)
			f[j] |= f[j - a];
	}
	for (int i = 1; i <= M; i++)
		if (f[i]) S.push_back(i);
	cout << int (S.size()) << '\n';
	for (int i : S) cout << i << " ";
	return 0;
}
 
int main() {Solve();}

// https://cses.fi/problemset/task/1071
#include <bits/stdc++.h>
using namespace std;
 
int solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t, a, b;
	cin >> t; 
	while (t--)
	{
		cin >> a >> b;
		if (a > b)
		{
			if (a % 2) cout << (a - 1) * (a - 1) + b << '\n';
			else cout << a * a - b + 1 << '\n';
		} else
		{
			if (b % 2) cout << b * b - a + 1 << '\n';
			else cout << (b - 1) * (b - 1) + a << '\n';
		}
	}
	return 0;
}
 
int main() {solve();}

// https://cses.fi/problemset/task/1092
#include <bits/stdc++.h>
using namespace std;
 
vector <int> a, b;
int n;
 
void prt()
{
	cout << "YES\n" << a.size() << '\n';
	for (int i: a) cout << i << " ";
	cout << '\n' << b.size() << '\n';
	for (int i: b) cout << i << " ";
}
 
int solve()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	if (n % 4 == 0)
	{
		for (int i = 1; i < n + 1; i++)
		{
			if (i % 4 == 1 || i % 4 == 0) a.push_back(i);
			else b.push_back(i);
		}
		prt();
	} else 
	if (n % 4 == 3)
	{
		for (int i = 1; i < n; i++)
		{
			if (i % 4 == 1 || i % 4 == 2)  a.push_back(i);
			else b.push_back(i);
		}
		b.push_back(n);
		prt();
	}
	else cout << "NO";
	return 0;
}	
 
int main() {solve();}

// https://cses.fi/problemset/task/1674
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
 
int n, s[N];
vector <int> a[N];
 
void dfs(int u, int par)
{
	s[u]++;
	for (int v : a[u])
		if (v != par)
		{
			dfs(v, u);
			s[u] += s[v];
		}
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 2, x; i <= n; i++)
    	cin >> x, a[x].push_back(i);
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    	cout << s[i] - 1 << " ";
    return 0;
}

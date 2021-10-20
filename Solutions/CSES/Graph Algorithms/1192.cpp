// https://cses.fi/problemset/task/1192
#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 1e6 + 5;
 
typedef long long ll;
 
char c[N][N];
bool kt[N][N];
long long n, m, res = 0, cnt = 0;
pair <int, int> a[M], dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
 
void bfs(pair <int, int> s)
{
	queue <pair <int, int>> q; q.push(s);
    while (q.size())
    {
        pair <int, int> x = q.front(); q.pop();
        for (int d = 0; d < 4; d++)
        {
            int u = dir[d].first + x.first;
            int v = dir[d].second + x.second;
            if (u > 0 && v > 0 && u <= n && v <= m && kt[u][v] && c[u][v] == '.')
            {
                kt[u][v] = false;
                q.push({u, v});
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= m; j++)
    	{
            cin >> c[i][j];
            if (c[i][j] == '.') a[++cnt] = {i, j};
            kt[i][j] = 1;
        }
 
    for (int i = 1; i <= cnt; i++)
        if (kt[a[i].first][a[i].second]) 
            kt[a[i].first][a[i].second] = 0, res++, bfs(a[i]);
    cout << res;
    return 0;
}

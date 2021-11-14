// https://cses.fi/problemset/task/1625
#include <bits/stdc++.h>
using namespace std;
 
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
string s, dir = "UDLR";
char a[9][9];
int res;
 
void btr(int u, int v, int i) 
{
    if (!s[i]) return (void) (res++);
    if (u == 7 && v == 1) return;
    if (a[u - 1][v] && a[u + 1][v] && !a[u][v - 1] && !a[u][v + 1]) return;
    if (!a[u - 1][v] && !a[u + 1][v] && a[u][v - 1] && a[u][v + 1]) return;
    a[u][v] = 1;
    for (int d = 0; d < 4; d++) 
    {
        int x = u + dx[d];
        int y = v + dy[d];
        if (a[x][y]) continue;
        if (s[i] != '?' && s[i] != dir[d]) continue;
        btr(x, y, i + 1);
    }
    a[u][v] = 0;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 1; i < 8; i++)
        a[i][0] = a[i][8] = a[0][i] = a[8][i] = 1;
    cin >> s;
    btr(1, 1, 0);
    cout << res << '\n';
    return 0;
}

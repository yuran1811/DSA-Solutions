// https://cses.fi/problemset/task/1689
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

int x, y, a[8][8];

vector <pii> init(int x, int y) 
{
    vector <pii> g;
    for (int dx = -2; dx <= 2; dx++) 
        for (int dy = -2; dy <= 2; dy++) 
        {
            if (dx * dx + dy * dy != 5) continue;

            int u = x + dx, v = y + dy;
            if (u >= 0 && u < 8 && v >= 0 && v < 8) 
                g.push_back({u, v});
        }
    return g;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);    
    cin >> y >> x;
    a[--x][--y] = 1;

    for (int k = 2, val = 100; k <= 64; k++, val = 100) 
    {
        pii ok = {0, 0};
        for (auto i : init(x, y)) 
        {
            if (a[i.fi][i.se]) continue;

            int tmp = 0;
            for (auto j : init(i.fi, i.se))
                tmp += (a[j.fi][j.se] == 0);

            if (tmp < val || (tmp == val && i.se > ok.fi))
                val = tmp, ok = i;
        }
        x = ok.fi, y = ok.se;
        a[x][y] = k;
    }
    for (int i = 0; i < 8; i++) 
        for (int j = 0; j < 8; j++)
            cout << a[i][j] << " \n" [j == 7];
    return 0;
}

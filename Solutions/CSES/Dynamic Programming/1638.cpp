// https://cses.fi/problemset/task/1638
#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7, N = 1e3 + 5;

int n, f[N][N];
char c[N][N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
          cin >> c[i][j];
  
    if (c[1][1]!='.' || c[n][n]!='.') return cout << 0, 0;
  
    f[1][1]=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        if (c[i][j]=='.')
        {
            if (c[i-1][j]=='.' && c[i][j-1]=='.')
                f[i][j]+=(f[i-1][j]%oo+f[i][j-1]%oo)%oo; else
            if (c[i-1][j]=='.' && c[i][j-1]!='.')
                f[i][j]+=f[i-1][j]%oo; else
            if (c[i-1][j]!='.' && c[i][j-1]=='.')
                f[i][j]+=f[i][j-1]%oo;
        }
    cout << f[n][n];
    return 0;
}

// https://cses.fi/problemset/task/1094
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a,c=b;i<=c;i++)
using namespace std;

int n, a[200002];
long long d = 0;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n; f(i, 1, n) cin >> a[i];
    f(i, 1, n - 1)
        if (a[i] > a[i + 1])
          d += a[i] - a[i + 1],
          a[i + 1] = a[i];
    cout << d;
    return 0;
}

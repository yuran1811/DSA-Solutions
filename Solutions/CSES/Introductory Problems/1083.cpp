// https://cses.fi/problemset/task/1083
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a,c=b;i<=c;i++)
using namespace std;

int x, n, a[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    f(i, 1, n - 1)
    {
        cin >> x;
        a[x] = 1;
    }
    f(i, 1, n)
      if (!a[i]) cout << i;
    return 0;
}

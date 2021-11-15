// https://cses.fi/problemset/task/1618
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a,c=b;i<=c;i++)
using namespace std;

int res, n, i = 5;

int main()
{
    cin >> n;
    while (i <= n)
    {
        res += (n / i);
        i *= 5;
    }
    cout << res;
    return 0;
}

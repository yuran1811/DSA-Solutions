// https://cses.fi/problemset/task/1617
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a,c=b;i<=c;i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t = 1, e = 1e9 + 7;
    cin >> n;
    f(i, 1, n) t = t * 2 % e;
    cout << t;
    return 0;
}

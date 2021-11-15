// https://cses.fi/problemset/task/1068
#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a,c=b;i<=c;i++)
using namespace std;

long long res, n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; cout << n << " ";
    while (n > 1)
    {
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
        cout << n << " ";
    }
    return 0;
}

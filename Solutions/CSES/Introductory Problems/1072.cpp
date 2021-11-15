// https://cses.fi/problemset/task/1072
#include <bits/stdc++.h>
#define _f(i,ii,iii) for(int i=ii,(_ii)=iii;i<=(_ii);i++)
#define ul unsigned long long
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    _f(k, 1, n)
        cout << (ul) k * k * (k * k - 1) / 2 - (k - 1) * (k - 2) * 4 <<'\n';
    return 0;
}

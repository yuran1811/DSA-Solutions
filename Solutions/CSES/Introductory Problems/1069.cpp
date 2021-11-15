// https://cses.fi/problemset/task/1069
#include <bits/stdc++.h>
#define _f(i,ii,iii) for(int i=ii,(_ii)=iii;i<=(_ii);i++)
#define ul unsigned long long
using namespace std;

int res, k, n;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    getline(cin, s); n = s.size(); s = "." + s;
    _f(i, 1, n)
    {
        k = i;
        while (i <= n && s[i] == s[k]) i++;
        res = max(res, i - k);
        i--;
    }
    cout << res;
    return 0;
}

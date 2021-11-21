// https://cses.fi/problemset/task/2183
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
vector <long long> f;
vector <int> a;
int n;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; a.resize(n); f.assign(n + 5, 0); f[0] = 1;
    for (int &x : a) cin >> x; sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
    	if (f[i] < a[i]) return cout << f[i], 0;
    	f[i + 1] = f[i] + a[i];
    }
    return cout << f[n], 0;
}

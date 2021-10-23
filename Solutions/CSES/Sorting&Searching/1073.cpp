// https://cses.fi/problemset/task/1073
#include <iostream>
#include <map>

using namespace std;
const int N = 2e5 + 5;

map <int, int> mp;
int n, res = 0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 
    for (int i = 1, x; i <= n; i++) 
    {
    	cin >> x;
    	auto pos = mp.upper_bound(x);
    	if (pos == mp.end()) res++; else
    	if (--pos -> second == 0) mp.erase(pos);
    	mp[x]++;
    }
    cout << res;
    return 0;
}

// https://cses.fi/problemset/task/2205
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
 
int n, a[N];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; for (int i = 1; i <= n; i++) cout << 0;
    cout << '\n';
 
    a[0] = 1;
    int x = 0;
    for (int i = 1; i < 1 << n; i++) 
    	for (int j = 0; j < n; j++) 
        {
    		int y = x ^ (1 << j);
    		if (!a[y]) 
            {
    			x = y;
    			a[y] = 1;
				string s;
				while (y) 
                {
					if (y & 1) s += '1';
					else s += '0';
					y >>= 1;
				}
				reverse(s.begin(), s.end());
				for (int i = 1; i <= n - int(s.size()); i++) cout << 0;
				cout << s << '\n';
				break;
    		}
    	}
    return 0;
}

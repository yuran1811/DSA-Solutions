#include <iostream>
#include <vector>
using namespace std;
 
vector <int> Z, KMP;
string s;
int n;
 
void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s; n = s.size(); Z.resize(n); KMP.resize(n);
}
 
int Scorpio()
{
	Load_Data();
	int l = 0, r = 0;
	for (int i = 1, k, val; i < n; i++)
	{
		k = KMP[i - 1];
		while (k && s[i] != s[k]) k = KMP[k - 1];
		KMP[i] = k + (s[i] == s[k]);
 
		val = (i <= r) ? min(Z[i - l], r - i + 1) : 0;
		while (i + val < n && s[val] == s[val + i]) val++;
		Z[i] = val;
		if (i + val - 1 > r)
			l = i, r = i + val - 1; 
	}
	for (int x : Z) cout << x << " "; cout << '\n';
	for (int x : KMP) cout << x << " ";
	return 0;
}
 
int main() {Scorpio();}

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 5;

vector <int> Z;
string s, t;

void Z_Build(const string &s)
{
	int n = s.size(), l, r;

	Z.resize(n);
	l = r = 0;

	for (int i = 1; i < n; i++)
	{
		if (i <= r)
			Z[i] = min(r - i + 1, Z[i - l]);

		while (i + Z[i] < n && s[i + Z[i]] == s[Z[i]]) Z[i]++;

		if (r < i + Z[i] - 1)
			l = i, r = i + Z[i] - 1;
	}
}

void loadData()
{
	cin >> s >> t;
	s = t + '.' + s;

	Z_Build(s);

	for (int i = t.size() + 1; i < int (s.size()); i++)
		if (int (t.size()) <= Z[i])
			cout << i - t.size() << " ";
}

int Solve()
{
	loadData();
	return 0;
}

int main() {Solve();}
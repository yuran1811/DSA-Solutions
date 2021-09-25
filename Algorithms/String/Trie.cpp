#include <iostream>
using namespace std;

const int N = 1e6 + 5;

int n, q, sz = 0;
string s;

struct Trie
{
	struct Node
	{
		Node *child[26];
		int End, id;
		Node() {}
		Node(int sz)
		{
			this -> id = sz;
			this -> End = 0;
			for (int i = 0; i < 26; i++)
				child[i] = nullptr;
		}
	} *root = new Node(++sz);

	void Add(const string &s)
	{
		Node *p = root;
		for (char c : s)
		{
			if (p -> child[c - 'a'] == nullptr)
				p -> child[c - 'a'] = new Node(++sz);
			p = p -> child[c - 'a'];
		}
		++p -> End;
	}

	bool Find(const string &t)
	{		
		Node *p = root;
		for (char c : t)
		{
			p = p -> child[c - 'a'];
			if (p == nullptr) return false;
		}
		return p -> End;
	}
} T;

void Load_Data()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s, T.Add(s);
}

int Scorpio()
{
	Load_Data();
	while (q--)
		cin >> s, cout << (T.Find(s) ? "YES\n" : "NO\n");
	return 0;
}

int main() {Scorpio();}

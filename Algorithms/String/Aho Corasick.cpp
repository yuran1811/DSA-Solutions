/**
	Usage:
	* Count Appear Times
	* Find first appear position
*/

#include <iostream>
#include <vector>

#define sz(s) (int (s.size()))

using namespace std;

const int N = 1e6 + 5;
const int oo = 1e9 + 7;

string s, t;
int q;

bool mnz(int &a, int b) { return a > b ? a = b, 1 : 0; }

struct AhoCorasick
{
	struct Node
	{
		Node *link, *child[26];
		int lth, cnt, fi_pos;
		bool Valid;

		Node()
		{
			link = NULL; fi_pos = oo;
			lth = cnt = 0; Valid = 0;
			for (int i = 0; i < 26; i++) child[i] = NULL;
		}
	} *root = new Node();

	vector <Node*> q{root}, res;

	void Init(int n) { res.resize(n); }

	void Add(const string &t, int id)
	{
		Node *p = root;
		
		for (char c : t)
		{
			if (p -> child[c - 'a'] == NULL)
				p -> child[c - 'a'] = new Node();
			p = p -> child[c - 'a'];
		}

		p -> lth = sz(t);
		res[id] = p;
	}

	void BFS()
	{
		root -> link = root;

		for (int i = 0; i < sz(q); i++)
		{
			Node *p = q[i];

			for (int c = 0; c < 26; c++)
				if (p -> child[c] != NULL)
				{
					p -> child[c] -> link = (p == root) ? root : p -> link -> child[c];
					q.push_back(p -> child[c]);
				} else p -> child[c] = (p == root) ? root : p -> link -> child[c];
		}
	}

	void Marking(const string &s, int l = 1)
	{
		BFS();

		Node *p = root;

		for (char c : s)
			p = p -> child[c - 'a'],
			mnz(p -> fi_pos, l++);

		for (char c : s)
			root = root -> child[c - 'a'],
			root -> Valid = 1, root -> cnt++;

		for (auto p : vector <Node*> (q.rbegin(), q.rend()))
			p -> link -> Valid |= p -> Valid,
			p -> link -> cnt += p -> cnt,
			mnz(p -> link -> fi_pos, p -> fi_pos);
	}

	void Print()
	{
		for (auto p : res)
			if (p -> Valid)
				cout << "Appear " << p -> cnt << " times, first at " << p -> fi_pos - p -> lth + 1 << '\n'; 
			else cout << "Not Valid\n";
	}
} T;

void loadData()
{
	cin >> s >> q;
	T.Init(q);

	for (int i = 0; i < q; i++)
		cin >> t, T.Add(t, i);

	T.Marking(s);
	T.Print();
}

int Solve()
{
	loadData();
	return 0;
}

int main() {Solve();}

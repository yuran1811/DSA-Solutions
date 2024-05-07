/**
        Usage:
        * Finding longest repeating substring
        * Number of distinct substrings
        * Number of distinct substrings length i
*/

#include <iostream>
#include <string>

#define sz(s) (int(s.size()))

using namespace std;

const int N = 1e5 + 5;
const int A = 26;

struct Node {
  Node *link, *child[A];
  int lth;

  Node() {
    lth = 0;
    link = 0;
    for (int i = 0; i < A; i++) child[i] = 0;
  }
} SufAr[2 * N - 1], *last = SufAr;

int sz = 1;
string s, t;

void Add(int c) {
  Node *p = last;
  SufAr[sz].lth = last->lth + 1;
  last = SufAr + sz++;

  do p->child[c] = last, p = p->link;
  while (p && !p->child[c]);

  if (p) {
    Node *k = p->child[c];
    if (k->lth == p->lth + 1)
      last->link = k;
    else {
      SufAr[sz] = *k;
      SufAr[sz].lth = p->lth + 1;
      last->link = k->link = SufAr + sz;
      do p->child[c] = SufAr + sz, p = p->link;
      while (p && p->child[c] == k);
      ++sz;
    }
  } else
    last->link = SufAr;
}

// Application
void Repeat_Substring() {
  int r = 0, id = 0, i = -1;
  for (char c : s) {
    Add(c - 'a');
    i++;
    if (last->link->lth > r) r = last->link->lth, id = i + 1;
  }

  if (r)
    s.erase(id), cout << s.substr(id - r) << '\n';
  else
    cout << "-1\n";
}

int in[N];
void Num_Distinct_Substr_Lth_i() {
  for (char c : s) Add(c - 'a');
  for (int i = 1; i < sz; i++) ++in[SufAr[i].link->lth], --in[SufAr[i].lth];

  int Automaton = 0;
  for (int i = 0; s[i]; i++) Automaton += in[i], cout << Automaton << " ";
  cout << '\n';
}

void Num_Distinct_Substr() {
  for (char c : s) Add(c - 'a');

  long long res = 0;
  for (int i = 1; i < sz; i++) res += SufAr[i].lth - SufAr[i].link->lth;

  cout << res << '\n';
}
// End

int main() {
  cin >> s >> t;
  s += t;
  // Repeat_Substring();
  // Num_Distinct_Substr();
  // Num_Distinct_Substr_Lth_i();
  return 0;
}
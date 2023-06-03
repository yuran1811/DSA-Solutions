#include <iostream>
#include <string>
using namespace std;

const int N = 4e5 + 5, A = 26;

struct Node {
  Node *link, *child[A];
  int lth;
  Node() {
    lth = 0;
    link = 0;
    for (int i = 0; i < A; i++)
      child[i] = 0;
  }
} SufAr[2 * N - 1], *last = SufAr;

int sz = 1;
string s;

void Add(int c) {
  Node *p = last;
  SufAr[sz].lth = last->lth + 1;
  last = SufAr + sz++;

  do
    p->child[c] = last, p = p->link;
  while (p && !p->child[c]);

  if (p) {
    Node *k = p->child[c];
    if (k->lth == p->lth + 1)
      last->link = k;
    else {
      SufAr[sz] = *k;
      SufAr[sz].lth = p->lth + 1;
      last->link = k->link = SufAr + sz;
      do
        p->child[c] = SufAr + sz, p = p->link;
      while (p && p->child[c] == k);
      ++sz;
    }
  } else
    last->link = SufAr;
}

void Num_Distinct_Substr() {
  for (char c : s)
    Add(c - 'a');
  long long res = 0;
  for (int i = 1; i < sz; i++)
    res += SufAr[i].lth - SufAr[i].link->lth;
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  Num_Distinct_Substr();
  return 0;
}

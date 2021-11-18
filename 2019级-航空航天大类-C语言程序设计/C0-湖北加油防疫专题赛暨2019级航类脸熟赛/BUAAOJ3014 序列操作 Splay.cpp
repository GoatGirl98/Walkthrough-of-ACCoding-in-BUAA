#include<bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

const int MX = 200005;

struct Node{
  int val;
  int link[2], par;
}node[MX];

inline int& val(int x){ return node[x].val; }
inline int& par(int x){ return node[x].par; }
inline int& link(int x, int d){ return node[x].link[d]; }
inline int dir(int x){ return node[par(x)].link[0] != x; }

struct splaytree{
  int root;

  void rotate(int n) // To
  {
    int p = par(n), d = dir(n);
    link(p, d) = link(n, !d);
    if( link(n, !d) ) par(link(n, !d)) = p;

    par(n) = par(p);
    if( par(p) ) link(par(p), dir(p)) = n;

    link(n, !d) = p; par(p) = n;
  }

  void splay(int x, int f = 0){
    if( x == f ) return;
    while(par(x) != f){
      if( par(par(x)) == f );
      else if(dir(x) == dir(par(x))) rotate(par(x));
      else rotate(x);
      rotate(x);
    }
    if( f == 0 ) root = x;
  }

  int erase_end(int v){
    int n = root, l = 0, r = 0;
    while(n){
      if( val(n) >= v ) r = n, n = link(n, 0);
      else l = n, n = link(n, 1);
    }
    if( r == 0 ) return 0;
    else if( l == 0 ){
      int tmp = root; root = 0;
      return tmp;
    }
    else{
      splay(l);
      splay(r, l);
      par(r) = 0;
      link(l, 1) = 0;

      return r;
    }
  }

  int max_element(int n){
    return link(n, 1)? max_element(link(n, 1)) : n;
  }

  int back(){
    int v = max_element(root); splay(v);
    return v;
  }

  void push_back(int n)
  {
    splay(max_element(root));
    link(root, 1) = n; par(n) = root;
  }

  bool empty(){ return !root; }

  void print(int n){
    if( link(n, 0) ) print(link(n, 0));
    printf("%d ", val(n));
    if( link(n, 1) ) print(link(n, 1));
  }
};

typedef pair<int, splaytree> event;

splaytree A[MX];
set<int> X;
int D[MX];

void print(int t)
{
  printf("%d\n", t);
  for(int c : X){
    printf("%d : ", c);
    A[c].print(A[c].root);
    printf("\n");
  }
}


int main()
{
  int N;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) scanf("%d", D+i);
  for(int i = 1; i <= N; i++) val(i) = i;
  vector<event> L;
  for(int i = 1; i <= N; i++){
    int d = lower_bound(L.begin(), L.end(), D[i], [](event c, int l){ return c.first > l; }) - L.begin();

    if( L.size() == d ){
      val(D[i]) = D[i];
      splaytree tmp; tmp.root = D[i];
      L.emplace_back(D[i], tmp);
    }
    else{
      L[d].second.push_back(D[i]);
      L[d].first = D[i];
    }
  }
  for(event c : L){
    X.insert(c.first);
    swap(A[c.first], c.second);
  }

  int count = 0;
  int t, mx = N;
  for(t = 0; X.size() > 1; t++){
    int cur = *X.rbegin();
    splaytree lst = A[cur];// swap(lst, A[cur]);
    while(!lst.empty() && lst.back() == mx) lst.erase_end(mx--);
    X.erase(cur);

    while(!lst.empty()){
      int en = lst.back(), st = 0;
      auto it = X.lower_bound(en);
      if( it != X.begin()) st = *prev(it);
      else break;

      int v = lst.erase_end(st);
      A[st].push_back(v);

      int tmp = A[st].back();
      X.erase(st); X.insert(tmp);
      swap(A[st], A[tmp]);
    }
    if( !lst.empty() ){
      int tmp = lst.back();
      swap(A[tmp], lst);
      X.insert(tmp);
    }
  }
  printf("%d\n", t);
}

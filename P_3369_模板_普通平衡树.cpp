// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
template<class T>T min(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T max(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 5e6, inf = 2e10;
int n, rt, tot;
struct node {
  int val, siz, cnt, sum;
  int ch[2], fa;
} t[N];
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
void pushup(int p) {
  t[p].siz = t[ls(p)].siz + t[rs(p)].siz + t[p].cnt;
}
void rotate(int x) {
  int f = t[x].fa, ff = t[f].fa;
  int c = rs(f) == x;
  int d = t[x].ch[c ^ 1]; 
  if(ff) t[ff].ch[rs(ff) == f] = x;
  t[x].fa = ff;
  t[f].fa = x;
  t[x].ch[c ^ 1] = f;
  t[f].ch[c] = d; 
  t[d].fa = f;
  pushup(f);  pushup(x);
}
void Splay(int x, int tar) {
  while( t[x].fa != tar ) {
    int f = t[x].fa, ff = t[f].fa;
    if(ff != tar) {
      ( ( (rs(ff) == f) ^ (rs(f) == x) ) ? rotate(x) : rotate(f) );
    }
    rotate(x);
  }
  if(!tar) rt = x;
}
int Find(int x) {
  int u = rt;
  while(t[u].val != x && t[u].ch[t[u].val < x]) u = t[u].ch[t[u].val < x];
  Splay(u, 0);  return u;
}
void insert(int x) {
  int u = rt, fa = 0;
  while(u && t[u].val != x) fa = u, u = t[u].ch[t[u].val < x];
  if(u) t[u].cnt++, t[u].siz++, Splay(u, 0);
  else {
    ++tot;
    t[tot].val = x;  t[tot].fa = fa;  t[tot].cnt = t[tot].siz = 1;
    if( fa ) t[fa].ch[t[fa].val < x] = tot;
    Splay(tot, 0);
  }
}
int Rank(int x) {
  int u = rt;
  while(1) {
    if(t[ls(u)].siz >= x) u = ls(u);
    else if(t[ls(u)].siz + t[u].cnt >= x) return u;
    else x -= t[ls(u)].siz, x -= t[u].cnt, u = rs(u);
  }
}
int Pre(int x) {
  Find(x);
  if(t[rt].val < x) return rt;
  int u = t[rt].ch[0];
  while(u && t[u].ch[1]) u = t[u].ch[1];
  Splay(u, 0);
  return u;
}
int Next(int x) {
  Find(x);
  if(t[rt].val > x) return rt;
  int u = t[rt].ch[1];
  while(u && t[u].ch[0]) u = t[u].ch[0];
  Splay(u, 0);
  return u;
}
void Del(int x) {
  int p = Pre(x), q = Next(x);
  Splay(p, 0);  Splay(q, p);
  int u = t[q].ch[0];
  if(t[u].cnt > 1) t[u].cnt--, t[u].siz--, Splay(u, 0);
  else {  t[q].ch[0] = 0;  }
}
signed main () {
  n = read();  insert(-inf), insert(inf);
  FOR(i, 1, n) {
    int op = read(), x = read();
    if(op == 1) {
      insert(x);
    }
    if(op == 2) {            
      Del(x);
    }
    if(op == 3) { 
      insert(x);  Find(x); printf("%d\n", t[ls(rt)].siz); Del(x);
    }
    if(op == 4) {
      printf("%d\n", t[Rank(x + 1)].val);
    }
    if(op == 5) {
      printf("%d\n", t[Pre(x)].val);
    }
    if(op == 6) {
      printf("%d\n", t[Next(x)].val);
    }
  }
  return 0;
}
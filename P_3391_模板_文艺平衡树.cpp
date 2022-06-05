// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
template<class T>T wmin(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T wmax(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
const int N = 2e6;
int n, m, rt, tot, inf = 2e9;
struct node {
  int fa, ch[2], siz, cnt, val, tag;
} t[N];
#define fa(x) t[x].fa
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
void pushup(int x) {
  t[x].siz = t[ls(x)].siz + t[rs(x)].siz + t[x].cnt;
}
void rotate(int x) {
  int f = fa(x), ff = fa(f);
  int c = rs(f) == x;
  int d = t[x].ch[c ^ 1];
  if (ff) t[ff].ch[rs(ff) == f] = x;
  t[x].fa = ff, t[f].fa = x;
  t[x].ch[c ^ 1] = f; t[f].ch[c] = d;  t[d].fa = f;
  pushup(f), pushup(x);
}
void pushdown(int p) {
  if (t[p].tag) {
    swap(ls(p), rs(p));
    t[ls(p)].tag ^= 1; t[rs(p)].tag ^= 1; t[p].tag ^= 1;
  }
}
int st[N], tp;
void splay(int x,int tar = 0) {
  int u = x;
  while (fa(u) != tar) st[++tp] = u, u = fa(u);
  while (tp) pushdown(st[tp--]);
  while (fa(x) != tar) {
    int f = fa(x), ff = fa(f);
    if (ff != tar) {
      if ( (rs(ff) == f) && (rs(f) == x) ) rotate(f);
      else rotate(x);
    }
    rotate(x);
  }
  if (!tar) rt = x;
}
void insert(int x) {
  int u = rt, fa = 0;
  while (u && t[u].val != x) fa = u, u = t[u].ch[t[u].val < x];
  if (u) t[u].cnt++, t[u].siz++, splay(u);
  else {
    ++tot; t[tot].val = x; t[tot].fa = fa;
    t[tot].cnt = t[tot].siz = 1;
    if ( fa ) t[fa].ch[t[fa].val < x] = tot;
    splay(tot);
  }
}
int Find(int x) {
  int u = rt;
  while (t[u].ch[t[u].val < x] && t[u].val != x) {
    pushdown(u);
    u = t[u].ch[t[u].val < x];
  }
  splay(u, 0);
  return u;
}
int Findkth(int x) {
  int u = rt;
  while (1) {
    pushdown(u);
    if (t[ls(u)].siz >= x) u = ls(u);
    else if (t[ls(u)].siz + t[u].cnt >= x) return u;
    else x -= t[ls(u)].siz, x -= t[u].cnt, u = rs(u);
  }
}
int Getpre(int x) {
  Find(x);  if(t[rt].val < x) return rt;
  int u = rt;  u = ls(u);
  while (u && rs(u)) u = rs(u);
  splay(u, 0);
  return u;
}
int Getnext(int x) {
  Find(x); if (t[rt].val > x) return rt;
  int u = rt; u = rs(u);
  while (u && ls(u)) u = ls(u);
  splay(u, 0);
  return u;
}
void del(int x) {
  int p = Getpre(x), q = Getnext(x);
  splay(p); splay(q, p);
  int u = ls(q);
  if (t[u].cnt > 1) t[u].cnt--, t[u].siz--, splay(u, 0);
  else ls(q) = 0;
}
int Findrank(int x) {
  insert(x); Find(x);
  int now = t[ls(rt)].siz;
  del(x); return now;
}
void work(int l,int r) {
  int x = Findkth(l - 1), y = Findkth(r + 1);
  splay(x, 0); splay(y, x);
  int now = rt; now = rs(now); now = ls(now);
  t[now].tag ^= 1;
}
vector <int> ans;
void out(int x) {
  pushdown(x);
  if (ls(x)) out(ls(x));
  if (x <= n + 1 && x >= 2) ans.emplace_back(x);
  if (rs(x)) out(rs(x));
}
signed main () {
  n = read(), m = read();
  FOR (i, 1, n + 2) insert(i);
  FOR (i, 1, m) {
    int l = read() + 1, r = read() + 1;
    work(l, r);
  }
  out(rt);
  FORP (to, ans) write(to - 1), putchar(' ');
  return 0;
}
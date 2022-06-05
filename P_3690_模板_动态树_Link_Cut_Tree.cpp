// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
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
int n, m;
struct node {  int val, sum, tag, fa, ch[2];  } t[N];
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
#define fa(x) t[x].fa
int chk(int x) {
  return ( ls( fa(x) ) != x) && (rs( fa(x) ) != x );
}
void pushdown(int x) {
  if (t[x].tag) {
    swap(t[ls(x)], t[rs(x)]);
    t[ls(x)].tag ^= 1; t[rs(x)].tag ^= 1; t[x].tag ^= 1;
  }
}
void pushup(int x) {  t[x].sum = t[ls(x)].sum ^ t[rs(x)].sum ^ t[x].val;  }
void rotate(int x) {
  int f = fa(x), ff = fa(f);
  int z = ( rs(f) == x ), ch = t[x].ch[z ^ 1];
  t[x].fa = ff;  if ( !chk(f) ) t[ff].ch[rs(ff) == f] = x;
  t[f].fa = x; t[x].ch[z ^ 1] = f;
  t[ch].fa = f; t[f].ch[z] = ch;
  pushup(f); pushup(x);
}
int st[N], tp;
void splay(int x) {
  int u = x;
  while ( chk(u) ) st[++tp] = u, u = t[u].fa;
  while (tp) 
  while (chk(x)) {
    int f = fa(x);
    if ( !chk(f) ) rotate(x);
    else {
      if (rs(f) == x && rs( fa(f) ) == f) rotate(f);
      else rotate(x);
      rotate(x);
    }
  }
}
signed main () {
  n = read(), m = read();
  FOR (i, 1, n) t[i].val = read();
  FOR (i, 1, m) {
    int op = read(), x = read(), y = read();
    if (op == 1) {

    }
    if (op == 2) {

    }
    if (op == 3) {

    }
    if (op == 0) {

    }
  }

  return 0;
}
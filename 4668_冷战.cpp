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
const int N = 4e6;
int ans, tot, n, m, a[N], w[N];
struct node {
  int ch[2], fa, val, sum, tag;
  int id, mx;
} t[N];
void pushup(int k) {
  t[k].id = k;  t[k].mx = w[k];
  if( t[ t[k].ch[0] ].mx > t[k].mx ) {
    t[k].mx = t[ t[k].ch[0] ].mx;
    t[k].id = t[ t[k].ch[0] ].id;
  }
  if( t[ t[k].ch[1] ].mx > t[k].mx ) {
    t[k].mx = t[ t[k].ch[1] ].mx;
    t[k].id = t[ t[k].ch[1] ].id;
  }
}
#define ls(k) t[k].ch[0]
#define rs(k) t[k].ch[1]
bool chk(int x) {
  return ( rs(t[x].fa) != x ) && ( ls(t[x].fa) != x );
}
void rotate(int x) {
  int f = t[x].fa, ff = t[f].fa;
  int z = (rs(f) == x), ch = t[x].ch[z ^ 1];
  t[x].fa = ff; 
  if( !chk(f) ) t[ff].ch[rs(ff) == f] = x;
  t[f].fa = x;  t[x].ch[z ^ 1] = f;
  t[ch].fa = f;  t[f].ch[z] = ch;
  pushup(f), pushup(x);
}
void pushdown(int x) {
  if( t[x].tag ) {
    swap( ls(x), rs(x) );
    t[x].tag = 0;
    t[ls(x)].tag ^= 1;  t[rs(x)].tag ^= 1;
  }
}
int st[N], tp, las;
void splay(int x) {
  int u = x;  st[++tp] = x;
  while(!chk(u)) st[++tp] = (u = t[u].fa);
  while(tp) pushdown(st[tp--]);
  while(!chk(x)) {
    int f = t[x].fa, ff = t[f].fa;
    if(!chk(f)) {
      ( ( rs(ff) == f ) ^ ( rs(f) == x ) ) ? rotate(x) : rotate(f);
    }
    rotate(x);
  }
}
void access(int x) {
  for(int y = 0; x; y = x, x = t[x].fa) {
    splay(x);  rs(x) = y;  pushup(x);
  }
}
void makeroot(int x) {
  access(x);  splay(x);  t[x].tag ^= 1;
}
void spilt(int x,int y) {
  makeroot(x);  access(y);  splay(y);
}
int findrt(int x) {
  access(x);  splay(x);  pushdown(x);
  while ( ls(x) ) pushdown( x = ls(x) );
  return x;
}
void link(int x,int y) {
  makeroot(x);
  if(findrt(y) != x) t[x].fa = y;
}
signed main () {
  n = read(), m = read();
  FOR (i, n + 1, n + m) {
    int op = read(), x = read(), y = read();
    x ^= las, y ^= las;
    //cout << op << " " << x << " " << y << "\n";
    //w[i] = ++tot;
    makeroot(x);
    if (op == 0) {
      w[i] = ++tot;
      if (findrt(x) != findrt(y)); 
        link(x, i), link(i, y);
    }
    if (op == 1) {
      if (findrt(y) != x) { las = 0; cout << "0\n"; continue; }
      spilt(x, y);
      int k = t[y].id;
      cout << (las = t[k].mx) << "\n";
    }
  }  
  return 0;
}
// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define LL long long
using namespace std;
namespace io {
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
  #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
  inline void flush () {  fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
  inline void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
  template <class I>
  inline void gi (I &x) {
    for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
  }
  string getstr(void) {
    string s = ""; char c = gc();
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF) c = gc();
    while (!(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF))s.push_back(c), c = gc();
    return s;
  }
  template <class I>
  inline void print (I x) {
    if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
    while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
    while (qr) putc (qu[qr --]);
  }
  struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
#define I inline int
#define V inline void
const int N = 1e6 + 6, mod = 998244353;
int n, m;
struct mat {
  LL a[4][4];
  int n, m;
  mat () { n = 1; m = 4; memset(a, 0, sizeof(a)); }
  mat operator * (mat B) const {
    mat res; res.n = n; res.m = B.m;
    for (int i = 0; i < n; i++) 
      for (int k = 0; k < B.m; k++)
         for (int j = 0; j < m; j++) {
          res.a[i][j] += (LL) a[i][k] * B.a[k][j] % mod;
          res.a[i][j] %= mod;
        }
    return res;
  }
  mat operator + (mat B) const {
    mat res;
    for (int i = 0; i < 4; i++) {
      res.a[i][0] = (a[i][0] + B.a[i][0]);
      res.a[i][1] = (a[i][1] + B.a[i][1]);
      res.a[i][2] = (a[i][2] + B.a[i][2]);
      res.a[i][3] = (a[i][3] + B.a[i][3]);
      if (res.a[i][0] >= mod) 
        res.a[i][0] -= mod;
      if (res.a[i][1] >= mod) 
        res.a[i][1] -= mod;
      if (res.a[i][2] >= mod) 
        res.a[i][2] -= mod;
      if (res.a[i][3] >= mod) 
        res.a[i][3] -= mod;
    }
    return res;
  }
  bool operator == (mat x)  const {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        if(a[i][j] != x.a[i][j])
          return false;
    return true;
  }
  void init() {
    n = m = 4;
    for (int i = 0; i < 4; i++)
      a[i][i] = 1;
  }
} s[N], tag[N], First, pt[8];
I ls(int p) { return p << 1; }
I rs(int p) { return p << 1 | 1; }
V pushup(int p) { s[p] = s[ls(p)] + s[rs(p)]; }
V pushdown(int p) {
  if (tag[p] == First)
    return;
  s[ls(p)] = s[ls(p)] * tag[p], s[rs(p)] = s[rs(p)] * tag[p];
  tag[ls(p)] = tag[ls(p)] * tag[p], tag[rs(p)] = tag[rs(p)] * tag[p];
  tag[p] = First;
}
V build(int p,int l,int r) {
  tag[p].init(); s[p].n = 1; s[p].m = 4; tag[p].n = tag[p].m = 4;
  if (l == r) { gi(s[p].a[0][0]), gi(s[p].a[0][1]), gi(s[p].a[0][2]), s[p].a[0][3] = 1;  return; }
  int mid = (l + r) >> 1;
  build(ls(p), l, mid), build(rs(p), mid + 1, r);
  pushup(p);  return;
}
V update(int p,int l,int r,int nx,int ny, mat val) {
  if (nx <= l && r <= ny) { s[p] = s[p] * val;  tag[p] = tag[p] * val; return;}
  pushdown(p);
  int mid = (l + r) >> 1;
  if (nx <= mid) 
    update(ls(p), l, mid, nx, ny, val);
  if (ny > mid)
    update(rs(p), mid + 1, r, nx, ny, val);
  pushup(p);
}
mat ask(int p,int l,int r,int nx,int ny) {
  if (nx <= l && r <= ny) 
    return s[p];
  pushdown(p);
  int mid = (l + r) >> 1;
  mat ans; ans.n = 1; ans.m = 4;
  if (nx <= mid) 
    ans = ans + ask(ls(p), l, mid, nx, ny);
  if (ny > mid) 
    ans = ans + ask(rs(p), mid + 1, r, nx, ny);
  pushup(p);
  return ans;
}
signed main () {
  // freopen("5.in", "r", stdin);
  // freopen("5.out", "w", stdout);
  // ios::sync_with_stdio(0);
  // cin.tie(0), cout.tie(0);
  First.init();
  for (int i = 1; i <= 6; i++)
    pt[i].init();
  pt[1].a[1][0] = 1;  pt[2].a[2][1] = 1;  pt[3].a[0][2] = 1;  pt[4].a[3][0] = 1; pt[6].a[2][2] = 0;
  gi(n);
  build(1, 1, n);
  gi(m);
  for (int t = 1, op, l, r; t <= m; t++) {
    gi(op), gi(l), gi(r);
    if (op <= 3) {
      update(1, 1, n, l, r, pt[op]);
    }
    if (op == 4) {
      int k; gi(k);
      pt[op].a[3][0] = k; 
      update(1, 1, n, l, r, pt[op]);
    }
    if (op == 5) {
      int k; gi(k);
      pt[op].a[1][1] = k;
      update(1, 1, n, l, r, pt[op]);
    }
    if (op == 6) {
      int k; gi(k);
      pt[op].a[3][2] = k; 
      update(1, 1, n, l, r, pt[op]);
    }
    if (op == 7) {
      mat ans = ask(1, 1, n, l, r);
      print(ans.a[0][0]), putc(' '), print(ans.a[0][1]), putc(' '), print(ans.a[0][2]), putc('\n');
    }
  }
  return 0;
}
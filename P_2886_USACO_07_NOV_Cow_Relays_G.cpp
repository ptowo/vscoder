// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define int long long 
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
struct mat {
  int a[101][101];
  mat () {  memset(a, 0x3f, sizeof(a));  }
  mat operator * (mat b) const {
    mat res;
    for (int i = 1; i <= 100; i++)
      for (int k = 1; k <= 100; k++)
        for (int j = 1; j <= 100; j++)
          res.a[i][j] = min(res.a[i][j], a[i][k] + b.a[k][j]);
    return res;
  }
  mat operator ^ (int k) const {
    mat res, B;  
    for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= 100; j++) 
        B.a[i][j] = a[i][j];
      res.a[i][i] = 0;
    }
    while (k) {
      if (k & 1)
        res = res * B;
      k >>= 1;  B = B * B; 
    }
    return res;
  }
} base;
int n, t, s, e;
int vis[2000], tot;
signed main () {
  gi(n), gi(t), gi(s), gi(e);  
  if (!vis[s])
    vis[s] = ++tot;
  if (!vis[e])
    vis[e] = ++tot;
  for (int i = 1, u, v, w; i <= t; i++) {
    gi(w), gi(u), gi(v);
    if (!vis[u])
      vis[u] = ++tot;
    if (!vis[v])
      vis[v] = ++tot;
    u = vis[u], v = vis[v];
    base.a[u][v] = base.a[v][u] = w; 
  }
  base = base ^ n;
  cout << base.a[vis[s]][vis[e]] << "\n";
  return 0;
}
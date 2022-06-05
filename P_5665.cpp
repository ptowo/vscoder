// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
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
const int N = 4e7 + 5, M = 2e5, mod = (1 << 30) ;
int n, op, a[N], b[N], x, y, z, m, p[M], l[M], r[M], q[N], las[N];
long long s[N];
long long bx(int x) {
  return s[x] - s[las[x]];
}
signed main() {
  gi(n), gi(op);
  if (op) {
    gi(x), gi(y), gi(z), gi(b[1]), gi(b[2]), gi(m);
    for (int i = 1; i <= m; i++) 
      gi(p[i]), gi(l[i]), gi(r[i]);
    for (int i = 3; i <= n; i++) 
      b[i] = (0ll + 1ll * b[i - 1] * x % mod + 1ll * b[i - 2] * y % mod + z) % mod; 
    for (int i = 1; i <= m; i++) 
      for (int j = p[i - 1] + 1; j <= p[i]; j++)
        a[j] = (b[j] % (r[i] - l[i] + 1)) + l[i], s[j] = s[j - 1] + a[j] ;
  }  else {
    for (int i = 1; i <= n; i++)
      gi(a[i]), s[i] = s[i - 1] + a[i]; 
  }
  int l = 0, r = 0;
  for (int i = 1; i <= n; i++) {
    while (l < r && bx(q[l + 1]) + s[q[l + 1]] <= s[i])
      l++;
    las[i] = q[l];
    while (l < r && bx(q[r]) + s[q[r]] >= bx(i) + s[i])
      r--;
    q[++r] = i;
  }
  int now = n; 
  __int128 ans = 0, tmp = 1;
  while (now) {
    tmp = (__int128) bx(now) * bx(now), ans += tmp, now = las[now];
  }
  print(ans);
  return 0 ;
}
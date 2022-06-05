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
  inline int gi () {
    int x = 0;
    for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f; return x;
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
const int inf = 2e9;
int n, m, a[150][150], f[150][150], g[150][150];
void printe(int i,int j) {
  if (i == 0) 
    return;
  printe(i - 1, g[i][j]);
  cout << j << " ";
}
signed main () {
  n = gi(), m = gi();
  for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= m; j++) 
      a[i][j] = gi();
  for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= m; j++)
      f[i][j] = (i == 1) ? a[i][j] : -inf;
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= m; j++) {
      for (int k = i - 1; k < j; k++) {
        if (f[i][j] < f[i - 1][k]) {
          f[i][j] = f[i - 1][k];
          g[i][j] = k;
        }
      }
      f[i][j] += a[i][j];
    }
  }
  int ans = -inf, pos = 0;
  for (int i = 1; i <= m; i++) {
    if (f[n][i] > ans) {
      ans = f[n][i], pos = i;
    }
  }
  cout << ans << "\n";
  printe(n, pos);
  return 0;
}
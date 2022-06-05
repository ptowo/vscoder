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
int T, x, f[25][4], lim = 24;
void init() {
  memset(f, 0, sizeof(f)); f[0][0] = 1;
  for (int i = 1; i <= 24; i++) {
    f[i][0] = 9 * (f[i - 1][0] + f[i - 1][1] + f[i - 1][1]);
    f[i][1] = f[i - 1][0];
    f[i][2] = f[i - 1][1];
    f[i][3] = 10 * f[i - 1][3] + f[i - 1][2];
  }
}
void solve(int x) {
  int m = 3, n = x;
  while (f[m][3] < x)
    m++;
  for (int i = m, k = 0; i > 0; i--) {
    for (int j = 0; j <= 9; j++) {
      int cnt = f[i - 1][3];
      if (j == 6 || k == 3) {
        for (int l = max(3 - k - (j == 6), 0ll); l < 3; l++) 
          cnt += f[i - 1][l];
      }
      if (cnt < x) x -= cnt;
      else {
        if (k < 3) {
          if (j == 6) k++;
          else k = 0;
        }
        printf("%d", j); 
        break;
      }
    }
  }
  return;
}
signed main () {
  init(); T = gi();
  while (T--)
    x = gi(), solve(x);
  return 0;
}
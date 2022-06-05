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
const int N = 305;
int n, a[N], s[N], dp1[N][N], dp2[N][N];
signed main () {
  n = gi();
  for (int i = 1; i <= n; i++) a[i] = gi(), s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= n; i++) a[i + n] = a[i], s[i + n] = s[i + n - 1] + a[i + n]; 
  memset(dp1, 0x3f, sizeof(dp1));
  for (int i = 1; i <= n * 2; i++) dp1[i][i] = 0;
  for (int len = 2; len <= n; len ++) {
    for (int l = 1; l + len <= 2 * n; l++) {
      int r = l + len - 1;
      for (int k = l; k < r; k++) {
        dp1[l][r] = min(dp1[l][r], dp1[l][k] + dp1[k + 1][r] + s[r] - s[l - 1]);
        dp2[l][r] = max(dp2[l][r], dp2[l][k] + dp2[k + 1][r] + s[r] - s[l - 1]);
      }
    }
  }
  int ans1 = INT_MAX, ans2 = 0;
  for (int i = 1; i <= n; i++) {
    ans1 = min(ans1, dp1[i][i + n - 1]);
    ans2 = max(ans2, dp2[i][i + n - 1]);
  }
  print(ans1), putc('\n'), print(ans2);
  return 0;
}
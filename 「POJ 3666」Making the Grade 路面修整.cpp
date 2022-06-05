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
const int N = 3000;
int ans = INT_MAX, m, n, a[N], b[N], c[N], dp[N][N];
signed main () {
  n = gi();
  for (int i = 1; i <= n; i++) b[i] = a[i] = gi();
  sort(b + 1, b + n + 1); m = unique(b + 1, b + n + 1) - (b + 1);
  memset(dp, 0x7f, sizeof(dp)); memset(dp[0], 0, sizeof(dp[0]));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) 
      dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + abs(a[i] - b[j]));
  }
  ans = min(ans, dp[n][m]);
  memset(dp, 0x7f, sizeof(dp)); memset(dp[0], 0, sizeof(dp[0]));  
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      dp[i][j] = min(dp[i][j + 1], dp[i - 1][j] + abs(a[i] - b[j]) );
    }
  }
  ans = min(ans, dp[n][1]);
  printf("%lld\n", ans);
  return 0;
}
/*
f[i][j] 表示前 i 个最大值能取到 j 的
*/
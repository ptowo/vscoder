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
const int N = 2e5;
int n, m, a[N], c[N], dp[N];
signed main () {
  while (1) {
    n = gi(), m = gi();
    if (n == 0 && m == 0) { return 0; }
    for (int i = 1; i <= n; i++) a[i] = gi();
    for (int i = 1; i <= n; i++) c[i] = gi();
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (dp[j] >= 0) dp[j] = c[i];
        else if (j < a[i] || dp[j - a[i]] <= 0) dp[j] = -1;
        else dp[j] = dp[j - a[i]] - 1;
      }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) ans += (dp[i] >= 0);
    print(ans), putc('\n');
  }
  return 0;
}
/*
n 中面值硬币，每种面值多少多少个，这就把不是傻逼题

哦，原来我才是，傻逼，嘻嘻嘻😁😃😄😄🥰。

dp[i][j] 表示前i种硬币凑成 j 的时候，第 i 种硬币剩余数量

dp[i][j] = -1 代表无法凑成

dp[i - 1][j] >=0 -> dp[i][j] = c[i]
dp[i][j - a[i]]
j < a[i] ||dp[i][j - a[i]] <= 0 dp[i][j] = -1
else dp[i][j] = dp[i][j - a[i]] - 1
*/
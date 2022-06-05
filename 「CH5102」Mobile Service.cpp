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
const int N = 300;
int l, n, c[N][N], a[1005], dp[1005][205][205];
int chkmin(int &x,int y) { if (y < x) x = y; return x;}
signed main () {
  l = gi(), n = gi();
  for (int i = 1; i <= l; i++)
    for (int j = 1; j <= l; j++)
      c[i][j] = gi();
  for (int i = 1; i <= n; i++) a[i] = gi(); a[0] = 1;
  memset(dp, 0x3f, sizeof(dp));
  dp[0][2][3] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= l; j++) {
      if (j == a[i]) continue;
      for (int k = 1; k <= l; k++) {
        if (k == j || k == a[i]) continue; 
        chkmin(dp[i + 1][j][k], dp[i][j][k] + c[ a[i] ][ a[i + 1] ]);
        chkmin(dp[i + 1][a[i]][k], dp[i][j][k] + c[j][ a[i + 1] ]);
        chkmin(dp[i + 1][j][a[i]], dp[i][j][k] + c[ k ][ a[i + 1] ]);
      }
    }
  }
  int ans = INT_MAX;
  for (int j = 1; j <= l; j++) {
    for (int k = 1; k <= l; k++) {
      if (j == k || j == a[n] || k == a[n]) continue;
      chkmin(ans, dp[n][j][k]);
    }
  }
  print(ans);
  return 0;
}
/*
dp[i][j][k] 表示员工正赛 i,j,k 的方案数
n * l^3
但是，你自己分析一下，你发现 i,j,k 中一定有一个位置是 a[i - 1]
于是省去一维度枚举，
发现倒着 dp 很难，那就正着来，然后貌似就过了
复杂度 n * l^2
*/
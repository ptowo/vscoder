// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int N = 70;
int n, m, a[N][N], f[N][N][N][N];
int chkmin(int &x,int y) { if (y < x) x = y; return x;}
int max2(int x,int y,int z,int k) { return max(max(x, y), max(z, k)); }
signed main () {
  m = gi(), n = gi();
  for (int i = 1; i <= m; i++) 
    for (int j = 1; j <= n; j++)
      a[i][j] = gi();
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= m; k++) {
        for (int l = j + 1; l <= n; l++) {
          f[i][j][k][l] = max2(f[i][j - 1][k - 1][l], f[i - 1][j][k][l - 1], f[i][j - 1][k][l - 1], f[i - 1][j][k - 1][l]) + a[i][j] + a[k][l];
        }
      }
    }
  }
  print(f[m][n - 1][m - 1][n]);
  return 0;
}
/*
dp[i][j][k][l] 表示路径当前到了 (i, j, k, l)
当然这题拿费用流做最简单，感觉。
*/
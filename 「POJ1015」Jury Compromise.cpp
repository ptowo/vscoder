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
const int N = 505;
int n, m, p[N], d[N], dp[30][N][N];
signed main () {
  while (1) {
    n = gi(), m = gi();
    if (n == 0 && m == 0) { return 0; }
    for (int i = 1; i <= n; i++) p[i] = gi(), d[i] = gi();
    for (int k = 0; k <= m; k++)
      for (int i = 0; i <= 200; i++) 
        for (int j = 0; j <= 200; j++) dp[k][i][j] = 0;
    int now = 20 * m;
    for (int i = 1; i <= n; i++) dp[1][p[i]][d[i]] = i;
    for (int k = 2; k <= m; k++) {
      for (int i = 1; i <= n; i++) { 
        for (int a = 0; a + p[i] <= now; a++) {
          for (int b = 0; b + d[i] <= now; b++) {
            if (!dp[k - 1][a][b]) continue;
            dp[k][a + p[i]][b + d[i]] = i;
          }
        }
      }
    }
    int posa = 0, posb = 0, mx = 300;
    for (int a = 0; a <= now; a++) {
      for (int b = 0; b <= now; b++) {
        if (dp[m][a][b]) {
          if (abs(a - b) < mx) {
            mx = abs(a - b);
            posa = a, posb = b;
          }  else if (abs(a - b) == mx) {
            if (a + b > posa + posb) {
              posa = a; posb = b;
            }
          }
        }
      }
    }
    cout << mx << " " << posa << " " << posb << "\n";
  }
  return 0;
}
/*
n 个人之中选出 m 个，让他们边防总分和控方总分的差的绝对值最小
两个约束条件，自然想到对于一个条件 dp，另一个条件为 dp 值
就这??????我就这!!!!!!!😎😎😎😎😎😎😎😎😎😎
注意到，p 与 d 的和做多也不会超过 20 * 20 = 400
于是直接暴力 dp 的说，，dp[i][j][k] 表示当前 dp 选了 i 个人
sump = j, sumd = k 是否存在
然后转移，显然很好转移，输出方案，how。
记录一下选的是哪个，然后倒着推回来就好了
哦，完全不需要多开，直接记录就好了
*/
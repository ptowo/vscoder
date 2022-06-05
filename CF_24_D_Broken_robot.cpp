// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define double float
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
const int N = 2500;
int n, m, x, y;
double dp[N][N], a[N][N], mat[N][N];
void get(int i) {
  a[1][1] = a[m][m] = (double) 2.0 / 3.0;
  a[1][2] = a[m][m - 1] = (double) -1.0 / 3.0;
  a[1][m + 1] = (double) dp[i + 1][1] / 3.0 + 1.0;
  a[m][m + 1] = (double) dp[i + 1][m] / 3.0 + 1.0;
  for (int j = 2; j < m; j++) {
    a[j][j] = (double) 3.0 / 4.0;
    a[j][m + 1] = (double) dp[i + 1][j] / 4.0 + 1.0;
    a[j][j - 1] = a[j][j + 1] = (double) -1.0 / 4.0;
  }
}
void gaos() {
  for (int i = 1; i <= m; i++) {
    double x = (double) 1.0 / a[i][i];
    a[i][i] = 1.0; a[i][m + 1] *= x;
    if (i != m) {
      a[i][i + 1] *= x;
      x = (double) a[i + 1][i] / a[i][i];
      a[i + 1][i] = 0;
      a[i + 1][i + 1] -= x * a[i][i + 1];
      a[i + 1][m + 1] -= x * a[i][m + 1];
    }
  }
  for (int i = m - 1; i; i--)
    a[i][m + 1] -= a[i + 1][m + 1] * a[i][i + 1];
}
signed main () {
  n = gi(), m = gi(), x = gi(), y = gi();
  if (m == 1) { printf("%d\n", 2 * (n - x)); return 0;}
  for (int i = n - 1; i >= x; i--) {
    get(i); gaos();
    for (int j = 1; j <= m; j++) 
      dp[i][j] = a[j][m + 1];
  }
  printf("%.6f", dp[x][y]);
  return 0;
}
/*
最自然的想法，感觉是直接对原图建出一个图出来，所有的第 n 行节点，不会再有出度
这就是一个拓扑结构，但是中途的点还会在这上面随机游走？
我日，这题高消？(nm)^3，不会啊，蒙蔽了😅😅
完全不会啊，看题解，什么神仙题

*/
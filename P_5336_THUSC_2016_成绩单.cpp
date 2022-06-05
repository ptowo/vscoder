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
const int N = 70, M = 70;
int n, a, b, num, w[N], c[N];
int dp[M][M][M][M], g[M][M];
void chkmin(int &x,int y) { if (x > y) x = y; return; }
signed main () {
  n = gi(), a = gi(), b = gi();
  for (int i = 1; i <= n; i++) 
    c[i] = w[i] = gi();
  sort(c + 1, c + n + 1);
  num = unique(c + 1, c + n + 1) - (c + 1);
  for (int i = 1; i <= n; i++) 
    w[i] = lower_bound(c + 1, c + num + 1, w[i]) - c;
  for (int l = 1; l <= n; l++)
    for (int r = 1; r <= n; r++)
      for (int x = 0; x <= num; x++)
        for (int y = 0; y <= num; y++)
          dp[l][r][x][y] = g[l][r] = INT_MAX;
  for (int i = 1; i <= n; i++)
    dp[i][i][w[i]][w[i]] = 0, g[i][i] = a;
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l <= n; l++) {
      int r = l + len - 1;
      if (r > n) break;
      for (int x = 1; x <= num; x++) {
        for (int y = x; y <= num; y++) {
          chkmin(dp[l][r][min(x, w[r])][max(y, w[r])], dp[l][r - 1][x][y]);
          for (int k = l; k < r; k++)
            chkmin(dp[l][r][x][y], dp[l][k][x][y] + g[k + 1][r]);
        }
      }
      for (int x = 1; x <= num; x++)
        for (int y = x; y <= num; y++)
          chkmin(g[l][r], dp[l][r][x][y] + a + b * (c[y] - c[x]) * (c[y] - c[x]));
      //cout << g[l][r] << " " << l << " " << r << "\n";
    }
  }
  cout << g[1][n] << "\n";
  return 0;
}
/*
dp[l][r][k] 表示合并了 k 次出现 [l,r] 的价值
dp[l][r][k] = a + 
[l, r] - > [l, t] + [t + 1, t] ？这个是分批次合并的
合并答案时，并不关注两个子区间所用次数，只关心当前区间的所用次数
暴力枚举区间，以及断点以及两个区间的次数，可以做到 n^6，笑麻了

首先合并区间的顺序没有关系，于是我们选择每次合并相邻区间到大区间，可以区间 dp

dp[l][r][x][y] 表示当时合并成 [l,r] 当前值域区间剩下的是 [x, y]

然后 dp[l][r][min(x, w[k])][max(y, w[k])] = dp[l][r - 1][x][y]

dp[l][r][min(x, w[k])][max(y, w[k])] = dp[k][r][x][y]
g[l][r] 表示的是 [l,r] 这段区间的一个最小值

g[l][r] = min(g[l][r], f[l][r][x][y] + A + B * (b[y] - b[x]) * (b[y] - b[x]));//记录小代价
*/
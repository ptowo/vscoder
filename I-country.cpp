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
const int N = 40;
int n, m, k, a[N][N], dp[N][230][N][N][2][2];
struct node { int i, j, l, r, x, y; };
node pre[N][230][N][N][2][2];
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
vector < pair<int,int> > Ans;
string PT = "Oil : ";
signed main () {
  n = gi(), m = gi(), k = gi();
  for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= m; j++) a[i][j] = a[i][j - 1] + gi();
  if (!k) { for (auto it : PT) putc(it); print(0); putc('\n'); return 0;}
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int l = 1; l <= m; l++) {
        for (int r = l; r <= m; r++) {
          int sum = a[i][r] - a[i][l - 1], mx10 = 0, mx11 = 0, mx00 = 0, mx01 = 0, len = r - l + 1; 
          if (j - len < 0) continue;
          for (int x = 0; x <= 1; x++) 
            for (int y = 0; y <= 1; y++) dp[i][j][l][r][x][y] = -1;
          for (int p = l; p <= r; p++) 
            for (int q = p; q <= r; q++) {
              if (chkmax(dp[i][j][l][r][1][0], dp[i - 1][j - len][p][q][1][0])) {
                pre[i][j][l][r][1][0] = node {i - 1, j - len, p, q, 1, 0};
              }
            }
          for (int p = l; p <= r; p++) {
            for (int q = r; q <= m; q++) {
              if (chkmax(dp[i][j][l][r][1][1], dp[i - 1][j - len][p][q][1][0])){
                pre[i][j][l][r][1][1] = node {i - 1, j - len, p, q, 1, 0};
              }
              if (chkmax(dp[i][j][l][r][1][1], dp[i - 1][j - len][p][q][1][1])) {
                pre[i][j][l][r][1][1] = node {i - 1, j - len, p, q, 1, 1};
              }
            }
          }
          for (int p = 1; p <= l; p++) {
            for (int q = l; q <= r; q++) {
              if (chkmax(dp[i][j][l][r][0][0], dp[i - 1][j - len][p][q][0][0])) {
                pre[i][j][l][r][0][0] = node {i - 1, j - len, p, q, 0, 0};
              }
              if (chkmax(dp[i][j][l][r][0][0], dp[i - 1][j - len][p][q][1][0])) {
                pre[i][j][l][r][0][0] = node {i - 1, j - len, p, q, 1, 0};
              }
            }
          }
          for (int p = 1; p <= l; p++) {
            for (int q = r; q<= m; q++) {
              if (chkmax(dp[i][j][l][r][0][1], dp[i - 1][j - len][p][q][0][0])) {
                pre[i][j][l][r][0][1] = node {i - 1, j - len, p, q, 0, 0};
              }
              if (chkmax(dp[i][j][l][r][0][1], dp[i - 1][j - len][p][q][1][0])) {
                pre[i][j][l][r][0][1] = node {i - 1, j - len, p, q, 1, 0};
              }
              if (chkmax(dp[i][j][l][r][0][1], dp[i - 1][j - len][p][q][1][1])) {
                pre[i][j][l][r][0][1] = node {i - 1, j - len, p, q, 1, 1};
              }
              if (chkmax(dp[i][j][l][r][0][1], dp[i - 1][j - len][p][q][0][1])) {
                pre[i][j][l][r][0][1] = node {i - 1, j - len, p, q, 0, 1};
              }
            }
          }          
          for (int x = 0; x <= 1; x++)
            for (int y = 0; y <= 1; y++) {
              dp[i][j][l][r][x][y] += sum;
            }
        }
      }
    }
  }
  int ans2 = 0;
  node qwq ;
  for (int i = 1; i <= n; i++) {
    for (int l = 1; l <= m; l++) {
      for (int r = l; r <= m; r++) {
        for (int x = 0; x <= 1; x++) {
          for (int y = 0; y <= 1; y++) {
            if (chkmax(ans2, dp[i][k][l][r][x][y])) qwq = node {i, k, l, r, x, y};
          }
        }
      }
    }
  }
  while (1) {
    for (int i = qwq.r; i >= qwq.l; i--) 
      Ans.emplace_back( make_pair(qwq.i, i) );
    if (qwq.i == 1) break;
    qwq = pre[qwq.i][qwq.j][qwq.l][qwq.r][qwq.x][qwq.y];
  }
  for (auto it : PT) putc(it); print(ans2); putc('\n');
  reverse(Ans.begin(), Ans.end());
  for (auto x : Ans) print(x.first), putc(' '), print(x.second), putc('\n');
  io :: flush();
  return 0;
}
/*
左端先（非严格）递减，再（非严格）递增，右端先（非严格）递增，再（非严格）递减的就是凸连通块。
设计状态 dp[i][k][l][fl][r][fr] 表示第 i 行取了 k 个格子，左端点为 l，右端点为 r
视作 n，m 同级
状态为 fl 和 fr 的权值和
首先枚举当前第 i 行， n
l,r n^3
k n^4
fl, fr 枚举上一行的状态转移
n^6
*/
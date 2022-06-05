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
const int inf = 1e9;
int n, m, f[14][5000], dis[50][50];
int d[5000][5000];
void output(int x) {
  for (int i = 0; i < n; i++) {
    if ((x >> i) & 1) cout <<"1";
    else cout << "0";
  }
  cout << " ";
}
signed main () {
  n = gi(), m = gi();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      dis[i][j] = inf;
  for (int i = 1, x, y, z; i <= m; i++) {
    x = gi() - 1, y = gi() - 1, z = gi();
    dis[x][y] = dis[y][x] = min(dis[x][y], z);
  }
  int lim = (1 << n);
  for (int i = 0; i < lim; i++) 
    for (int j = 0; j < lim; j++)
      d[i][j] = inf;
  for (int s = 1; s < lim; s++) {
    for (int s2 = s; s2; s2 = (s2 - 1) & s) {
      if (s2 == s) continue;
      int las = (s ^ s2), now = s, gp = 0;
      for (int i = 0; i < n; i++) {
        if ((las >> i) & 1) { 
          int pt = inf;
          for (int j = 0; j < n; j++) 
            if ((s2 >> j) & 1) pt = min(pt, dis[i][j]);
          gp += pt;
        }
      }
      d[s2][s] = min(d[s2][s], gp);
    }
  }
  memset(f, 0x3f, sizeof(f));
  for (int i = 0; i < n; i++)
    f[0][(1 << i)] = 0;
  for (int i = 1; i <= n; i++) 
    for (int s = 1; s < lim; s++) 
      for (int s2 = s; s2; s2 = (s2 - 1) & s) {
        if (s2 == s) continue;
        f[i][s] = min(f[i][s], f[i - 1][s2] + d[s2][s] * i);
      }
  int ans = inf;
  for (int i = 0; i <= n; i++) 
    ans = min(f[i][lim - 1], ans);
  cout << ans << "\n";
  return 0;
}
/*
认真的子集 dp
初始化 dp 无穷大
预处理出 dp[1<<i] = 0
然后到下一个状态的时候，我们考虑枚举他的子集，然后选最优进行答案的覆盖更新
开发一条路代价为 L*K，L 表示道长已知，K 表示大通的点到这条道路起点经过的宝藏屋
发现这个对于 k 这东西不是很好处理，考虑在加一维度表示深度
于是复杂度变为 n^4 2^n
考虑每次枚举一个顶点 x 表示他是打通的宝藏物 O(n)
然后枚举状态得到 2^n
然后枚举大少一个点为
f[i][s] 表示当前树高为 i
打通集合 s 的最小代价
f[i - 1][s0] 
*/
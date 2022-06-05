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
int n, m, dp[N][5005], sum[N], ans[N];
int cksum[N][5005], pre[N][5005];
pair <int,int> g[N];
int cmp(pair<int,int> a, pair<int,int> b) { return a.first > b.first; }
void process(int num,int bis) {
  if (!num) return;
  process(pre[num][bis], cksum[num][bis]);
  if (pre[num][bis] == num) {
    for (int i = 1; i <= num; i++) ans[ g[i].second ]++;
  }  else {
    for (int i = pre[num][bis] + 1; i <= num; i++) ans[ g[i].second ] = 1;
  }
}
signed main () {
  n = gi(), m = gi();
  for (int i = 1; i <= n; i++) g[i].first = gi(), g[i].second = i;
  sort(g + 1, g + n + 1, cmp);
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + g[i].first;
    for (int j = i; j <= m; j++) {
      dp[i][j] = dp[i][j - i];
      pre[i][j] = i;
      cksum[i][j] = j - i;
      for (int k = 0; k < i; k++) {
        if (dp[k][j - (i - k)] + k * (sum[i] - sum[k]) < dp[i][j]) {
          dp[i][j] = dp[k][j - (i - k)] + k * (sum[i] - sum[k]);
          pre[i][j] = k;
          cksum[i][j] = j - (i - k);
        }
      }
    }
  }
  cout << dp[n][m] << "\n";
  process(n, m);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
/*
每个孩子至少一个饼干，从小到大排序，
dp[i][j] 表示前 i 个人分得的 j 个
*/
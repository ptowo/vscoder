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
const int N = 3e6;
int T, n, num, nex[N], first[N], v[N], w[N];
void add(int from,int to,int val) {
  nex[++num] = first[from]; first[from] = num; v[num] = to; w[num] = val;
}
int f[N], siz[N], dep[N], sz[N];
void dfs1(int x,int fa) {
  f[x] = fa; siz[x] += dep[x]; sz[x] = 1;
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i]; if (to == fa) continue;
    dep[to] = dep[x] + w[i];
    dfs1(to, x);
    siz[x] += siz[to];
    sz[x] += sz[to];
  }
}
//求出以某个节点为根的时候的节点深度和
// x -> to
int dp[N];
void DP(int x,int fa) {
  if (x == 1) dp[1] = siz[1];
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i]; if (to == fa) continue;
    dp[to] = dp[x];
    dp[to] -= sz[to] * w[i];
    dp[to] += (n - sz[to]) * w[i];
    DP(to, x);
    // 
  }
}
signed main () {  
  T = gi();
  while (T--) {
    n = gi();
    for (int i = 1; i < n; i++) {
      int u = gi(), v = gi(), w2 = gi();
      add(u, v, w2), add(v, u, w2);
    }
    dfs1(1, 0); DP(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    print(ans), putc('\n');
  }
  return 0;
}
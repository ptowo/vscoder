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
const int N = 6000;
int n, a[N], lis[N];
double dp[N];
signed main () {
  n = gi();
  for (int i = 1; i <= n; i++)
    a[i] = gi();
  a[0] = INT_MAX; lis[0] = 0; dp[0] = 1.0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i] < a[j] && lis[j] + 1 > lis[i]) 
        lis[i] = lis[j] + 1;
    }
    for (int j = i - 1; j >= 0; j--) {
      if (a[i] < a[j]) {
        if (lis[j] + 1 == lis[i])
          dp[i] += (double) dp[j];
      }  else if (a[i] == a[j] && lis[i] == lis[j]) break;
    }
  }
  int mx = 0;
  double ans = 0;
  for (int i = 1; i <= n; i++)
    mx = max(mx, lis[i]);
  for (int i = 1; i <= n; i++) 
    if (lis[i] == mx)
      ans += (double)dp[i];
  printf("%d %.0f\n", mx, ans);
  return 0;
}
/*
dp[j] 表示以 j 结尾的最长上升子序列长度
dp2[j] 表示以 j 结尾的最长上升子序列的方案数
*/
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
const int mod = 998244353;
const int N = 20;
int n, m, ans, a[N], b[N];
void dfs(int x,int val) {
  if (x == n + 1) {
    for (int i = 1; i <= n; i++) 
      b[i] = b[i - 1] ^ a[i];
    for (int i = 2; i <= n; i++)
      if (b[i] <= b[i - 1]) return;
    /*for (int i = 1; i <= n; i++) 
      cout << b[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 5; j++) {
        if ((b[i] >> j) & 1) cout << "1";
        else cout << "0";
      }
      cout << " ";
    }
    cout << "\n";*/
    ans++;
    return ;
  }
  for (int i = val + 1; i <= m; i++) 
    a[x] = i, dfs(x + 1, i);
}
signed main () {
  n = gi(), m = gi();
  if (m <= n) { puts("0"); return 0;}
  dfs(1, 0); cout << ans << "\n";
  return 0;
}
/*
n，m 都很大，肯定不能直接做，打表
因为你的元素都是递增的，然后看一下二进制的形式
假设当前异或值为 x，要使后面的异或值更大
首先选的是比自己大的数，然后前缀异或值要增大，于是后面选的数都必须是让自己的
dp[i][j] 表示当前是第 i 位，然后有 j 个比这个大


2 3 2
---
2 4 5
2 5 8
2 6 11
2 7 14
----
2 8 21
2 9 28
...
2 15 70
----
2 16 85
2 17 100
...
----
2 32 341
发现对 2 来说：
(2, 1)
(4, 3)
(8, 7)
(16,15)
(32,31)

2^n - 1

3 4 2
3 5 4
3 6 6
3 7 8
----
3 8 22
3 9 36
3 10 50
3 11 64
...
3 15 120
----
3 16 190
3 17 260
...
----
3 32 1550
3 33 1860
...
----
3 64 12462
3 65 13764

4 8 8
4 9 16
4 10 24
...
----
4 16 184
4 17 304
4 18 424
..
---
4 32 3224
4 33 4464
4 34 5704
..
---
4 64 52824
4 65 63954

1 3 7 15 31 63
2 14 70 310 1302
8 112 1120 9920

8 120 1240 11160

发现对 3 来说
(4, 2)
(8, 14)
(16, 70)
(32, 310)
(64, 1302);

2 4 8 16 32 2 ^ n
2 12 56 240 992 4 ^ n - 2 ^ n

1 3 7 15 31 63
2 14 70 310 1302
*/
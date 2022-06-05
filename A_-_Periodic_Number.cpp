// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define int __int128
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
using io :: getstr;
int T, d[20], b[20], f[20];
int n;
signed main () {
  T = gi();
  while (T--) {
    n = gi(); int t = 0;
    int x = n;
    while (x) 
      b[++t] = x % 10, x /= 10;
    reverse(b + 1, b + t + 1);
    int ans = 0;
    for (int len = t; len >= 1; len--) {
      for (int p = len - 1; p >= 1; p--) {
        if (len % p != 0) continue; 
        if (len / p < 2) continue;
        for (int i = 1; i < 20; i++)
          d[i] = 9, f[i] = 0;
        int cnt = 0, fl = 0, num = 1;
        int s1 = 1;
        for (int i = 1; i <= p; i++) s1 = s1 * 10;
        int s2 = 0;
        for (int i = 1; i <= p; i++) s2 = s2 * 10 + 9;
        int s = 0;
        int l = 1, r = s2, pos = 0, tp = 0;
        while (l <= r) {
          int mid = (l + r) >> 1;
          int gt = mid, tt = mid, fl = 0;
          for (int j = 2; j <= (len / p); j++)  {
            gt = gt * s1 + tt;
            if (gt > n) { fl = 1; break;}
          }
          if (fl) r = mid - 1;
          else pos = gt, l = mid + 1, tp = mid;
        }
        //print(pos), putc(' '), print(tp), putc(' '), print(len), putc(' '), print(p), putc('\n');
        ans = max(ans, pos);
      }
    }
    print(ans), putc('\n');
  }
  return 0;
}
/*
n 总共就是一个 10^18 ，不超过 n 的最大的周期数
至少为两个循环
谔谔，你首先判断n是不是周期数，如果是直接输出
如果不是的话，枚举周期数的长度，然后对于每个找他能找到的最大的来代替
就是砍了之后对每个取 max，挺对的（
错惹呜呜，分离出来这么多位之后，二分一个数 check 也可以?
*/
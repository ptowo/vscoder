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
  template <class I>
  inline void gi (I &x) {
    for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
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
const int N = 3e5;
int n, ans;
int p[N], c[N], num;
vector <int> fac[N];
signed main () {
  gi(n);
  int s = 0;
  for (int i = 1; i <= n; i++) {
    int p1 = i * i, p2 = i * n;
    num = 0;
    for (int j = i; j <= n; j += i)
      p[++num] = j * j;
    if (sqrt(i) * sqrt(i) == i){
      int now = sqrt(i);
      for (int j = now; j <= n; j += now) {
        p[++num] = j * j;
      }
    }
    sort(p + 1, p + num + 1); 
    num = unique(p + 1, p + num + 1) - (p + 1);
    int pos1 = lower_bound(p + 1, p + num + 1, p1) - p;
    int pos2 = upper_bound(p + 1, p + num + 1, p2) - p - 1;
    int ans = (pos2 - pos1 + 1) * 2;  ans--;
    for (int k = pos1; k <= pos2; k++) {
      int now = p[k];
      cout << i << " " << p[k] / i << "\n";
      if (k != pos1)
        cout << p[k] / i << " " << i << "\n";
    }
    s += ans;
  }
  cout << s << "\n";
  return 0;
}
/*
对于过大的，n*n
(n-1)*(n-1) 就很少了，那么可能
问题在于，两个有公因数的，是弄不了的，
a^2 = (x + y) * (x - y) 统计合法的 x + y 与 x - y 的数目
1 *1 2*2 3*3 4*4 5*5
2*2 4*4 6*6 8*8 3*3 3*
x^2 统计多少 (i,j) i * j = x^2
x 分解质因数，然后 
首先对于在范围内的有那么多个
对于 2，2 * 2 = 4 2 * 8 = 16 
对于 3 3 * 3 = 3 * 
对于他的倍数的这些全部筛出来
a^2 - b^2
(a + b) * (a - b)
a^2 - b ^2
(a + b) * (a - b)
枚举 i，对于 j \in [1, n]
也就是 [i, i * n]
这里面能为平方数的，是 i 的倍数的
我们统计 i 的倍数，将他们的平方数扔进一个桶

偶数的完全平方 %4 = 0
奇数的完全平方 %4 = 1
偶 * 奇 = 偶，所以奇数一定是两个奇数相乘的形式
a^2 = (x + y) * (x - y)
管他的，平常摆烂就摆烂，反正
*/
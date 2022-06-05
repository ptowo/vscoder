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
const int N = 4e6;
int n, l, r, a[N];
pair<int,int> get(int x) {
  int now = n - 1, pt = 1;
  while (x > now && now >= 0)
    x -= now, ++pt, now--;
  return make_pair(pt, x);
}
signed main () {
  n = gi(), l = gi(), r = gi();
  for (int i = 1; i <= n; i++)
    a[i] = i;
  auto L = get(l), R = get(r);
  if (L.first == R.first) {
    int gt = L.first;
    for (int i = gt + L.second; i <= gt + R.second; i++)
      swap(a[L.first], a[i]);
    for (int i = 1; i <= n; i++)
      cout << a[i] << " ";
    return 0;
  }
  for (int i = L.first + L.second; i <= n; i++) 
    swap(a[L.first], a[i]);
  if (L.first + 1 <= R.first - 1) 
    reverse(a + L.first + 1, a + n + 1), reverse(a + R.first, a + n + 1);
  for (int i = R.first + 1; i <= R.first + R.second; i++) 
    swap(a[R.first], a[i]);
  for (int j = 1; j <= n; j++) 
    cout << a[j] << " "; cout << "\n";
  return 0;
}
/*
根据一个很奇怪的定理，反正最后如果一整个 (l, i) 都被翻了
第 x+1 行到第 y-1 行全部操作相当于反转 a[x + 1 ~ n] 再反转 a[y ~ n]
然后对于零散的我们可以直接暴力
*/
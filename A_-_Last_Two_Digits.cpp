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
const int N = 2e6;
int n, k, a[N], b[N], c[4];
signed main () {
  gi(n), gi(k);
  for (int i = 1; i <= n; i++)
    gi(a[i]), b[i] = a[i];
  sort(b + 1, b + n + 1);

  for (int i = 1; i <= n - 2 * k; i++) {
    c[1] = a[i], c[2] = a[i + k], c[3] = a[i + k + k];
    sort(c + 1, c + 3 + 1);
    a[i] = c[1], a[i + k] = c[2], a[i + k + k] = c[3];
  }
  for (int i = max(n - 2 * k, 0ll) + 1; i <= n - k; i++) {
    if (a[i] > a[i + k]) {
      swap(a[i], a[i + k]);
    }
  }
  // for (int i = 1; i <= n;)
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i]) {
      puts("No"); return 0;
    }
  }
  cout << "Yes";
  return 0;
}
/*
pos + k <= n - k

pos <= n - 2 * k

首先先满足小的，看他
*/
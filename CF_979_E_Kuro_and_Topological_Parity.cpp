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
const int N = 60, mod = 1e9 + 7;
int n, p, col[N], f[N][N][N][N], c[N][N], pw[N];
int power(int a,int b) {
  int ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a;
    b >>= 1;
    a = a * a;
  } 
  return ans;
}
signed main () {
  n = gi(), p = gi();
  for (int i = 1; i <= n; i++)
    col[i] = gi();    
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) 
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
  pw[0] = 1;
  for (int i = 1; i <= n; i++)
    pw[i] = pw[i - 1] * 2 % mod;
  f[1][0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < i; k++) {
        if (col[i] != 1) {
          for (int l = 0; l <= k; l++) {
            for (int d = 0; d <= 1; d++) {
              f[i + 1][j + ((l + 1) % 2)][k][d] += f[i][j][k][d ^ ((l + 1) % 2)] * pw[i - k - 1] % mod * c[k][l] % mod;
              f[i + 1][j + ((l + 1) % 2)][k][d] %= mod;
            }
          }
        }
        if (col[i] != 0){
          for (int l = 0; l <= j; l++) {
            for (int d = 0; d <= 1; d++) {
              f[i + 1][j][k + ((l + 1) % 2)][d] += f[i][j][k][d ^ ((l + 1) % 2)] * pw[i - j - 1] % mod * c[j][l] % mod;
              f[i + 1][j][k + ((l + 1) % 2)][d] %= mod;
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) 
    for (int j = 0; j <= n; j++)
      ans += f[n + 1][i][j][p], ans %= mod;
  cout << ans << "\n";
  return 0;
}
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
const int MN = 600;
int n, m, s[MN][MN], sz[MN], vis[MN];
vector < pair<int,int> > ans;
void get(int i,int j) { ans.emplace_back(make_pair(i, j)); } //把i最上面移到j最上方
void calc(int X,int H,int N,int y) {
  int a = 0, len = sz[H], cnt = 0;
  for (int i = sz[X]; i >= 1; i--) a += (s[X][i] == y);
  for (int i = len; i >= 1; i--) { get(H, N); s[N][++sz[N]] = s[H][sz[H]--];  if (++cnt == a) break;}
  cnt = 0; len = sz[X];
  for (int i = len; i >= 1; i--) {
    if (s[X][i] == y) get(X, H), s[H][++sz[H]] = s[X][sz[X]--];
    else get(X, N), s[N][++sz[N]] = s[X][sz[X]--];
  }
  len = sz[N], cnt = 0; 
  for (int i = len; i >= 1; i--) { get(N, X); s[X][++sz[X]] = s[N][sz[N]--]; if (++cnt == m - a) break;}
  cnt = 0; len = sz[H];
  for (int i = len; i >= 1; i--) { get(H, X); s[X][++sz[X]] = s[H][sz[H]--]; if (++cnt == a) break; }
  cnt = 0; len = sz[N];
  for (int i = len; i >= 1; i--)  get(N, H), s[H][++sz[H]] = s[N][sz[N]--];
}
signed main () {
  freopen("1.out", "w", stdout);
  n = gi(), m = gi();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) s[i][++sz[i]] = gi();
  }
  if (n == 2) {
    calc(1, 2, 3, 1); calc(2, 1, 3, 1);
    int pos = 0;
    for (int i = m; i >= 1; i--) { if (s[1][i] != 1) { pos = i; break;} get(1, 3); }
    for (int i = m; i >= 1; i--) { if (s[2][i] != 1) break; get(2, 3);}
    for (int i = pos; i >= 1; i--) get(1, 2);
    print(ans.size()); putc('\n');
    for (auto it : ans) print(it.first), putc(' '), print(it.second), putc('\n');
    return 0;
  }  else {
    for (int col = 1; col <= n; col++) {
      for (int i = col; i <= n; i++) {
        if (i == n) calc(i, 1, n + 1, col);
        else calc(i, i + 1, n + 1, col);
      }
      for (int i = col; i <= n; i++) {
        for (int j = sz[i]; j >= 1; j--) {
          if (s[i][j] != col) break;
          get(i, n + 1);
          s[n + 1][++sz[n + 1]] = s[i][sz[i]--];
        }
      }
      for (int i = col + 1; i <= n; i++) {
        while (sz[i] < m && sz[col]) {
          get(col, i);
          s[i][++sz[i]] = s[col][sz[col]--];
        }
        if (!sz[col]) break;
      }
      for (int i = sz[n + 1]; i >= 1; i--) {
        get(n + 1, col);
        s[col][++sz[col]] = s[n + 1][sz[n + 1]--];
      }
      //所有数的 col 都提上来了
    }
    print(ans.size()); putc('\n');
    for (auto it : ans) print(it.first), putc(' '), print(it.second), putc('\n');
    return 0;
  }
  return 0;
}
/*
称上提操作
*/
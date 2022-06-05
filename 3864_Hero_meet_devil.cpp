// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define long long int
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
const int N = 2e6, mod = 1e9 + 7;
int T, m, n, a[2005];
int dp[1005][(1 << 16) + 3];
char s[N];
int tmp[2][26], trans[(1 << 16) + 3][5];
int pre(int sta,int ch) { //表示现在sta状态，加入了ch字符
  int ret = 0;
  memset(tmp, 0, sizeof(tmp));
  for (int i = 0; i < n; i++)
    tmp[0][i + 1] = tmp[0][i] + ((sta >> i) & 1);
  for (int i = 1; i <= n; i++) {
    int mx = 0;
    if (a[i] == ch) mx = tmp[0][i - 1] + 1;
    mx = max( max(mx, tmp[0][i]), tmp[1][i - 1]);
    tmp[1][i] = mx;
  }
  for (int i = 0; i < n; i++) 
    ret += (1 << i) * (tmp[1][i + 1] - tmp[1][i]);
  return ret;
}
int ans[2005];
void mo(int &x) { if (x >= mod) x -= mod; }
signed main () {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  //T = gi();
  int now = 0;
  cin >> T;
  for (int tim = 1; tim <= T; tim++) {
    memset(ans, 0, sizeof(ans)); memset(dp, 0, sizeof(dp));
    memset(trans, 0, sizeof(trans));
    //s = io :: getstr(); m = gi(); n = s.size();
    cin >> s >> m; n = strlen(s);
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == 'A') a[i] = 0;
      else if (s[i - 1] == 'C') a[i] = 1;
      else if (s[i - 1] == 'G') a[i] = 2;
      else if (s[i - 1] == 'T') a[i] = 3;
    } 
    int s = (1ll << n);
    for (int i = 0; i < s; i++) 
      for (int now = 0; now < 4; now ++) {
        trans[i][now] = pre(i, now);
      }
    dp[0][0] = 1ll;
    for (int i = 1; i <= m; i++) 
      for (int sta = 0; sta < s; sta++)  {
        mo(dp[i][trans[sta][0]] += dp[i - 1][sta]);
        mo(dp[i][trans[sta][1]] += dp[i - 1][sta]);
        mo(dp[i][trans[sta][2]] += dp[i - 1][sta]);
        mo(dp[i][trans[sta][3]] += dp[i - 1][sta]);
      }
    for (int sta = 0; sta < s; sta++)
      mo(ans[__builtin_popcount(sta)] += dp[m][sta]);      
    for (int i = 0; i <= n; i++) 
      cout << ans[i] << "\n";
  }
  return 0;
}

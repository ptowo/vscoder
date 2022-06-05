// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
#define ll long long
template<class T>T wmin(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T wmax(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
namespace IO {
  int len = 0;
  char ibuf[(1 << 20) + 1], *iS, *iT, out[(1 << 25) + 1];
  #define gh()   (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, (1 << 20) + 1, stdin), (iS == iT ? EOF : *iS++) : *iS++)
  inline int read() {
    char ch = gh();
    int x = 0;
    char t = 0;
    while (ch < '0' || ch > '9') t |= ch == '-', ch = gh();
    while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = gh();
    return t ? -x : x;
  }
  inline void putc(char ch) { out[len++] = ch; }
  template <class T> inline void write(T x) {
    if (x < 0) putc('-'), x = -x;
    if (x > 9) write(x / 10);
    out[len++] = x % 10 + 48;
  }
  string getstr(void) {
    string s = ""; 
    char c = gh();
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF) c = gh();
    while (!(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF))s.push_back(c), c = gh();
    return s;
  }
  void putstr(string str, int begin = 0, int end = -1) {
    if (end == -1) end = str.size();
    for (int i = begin; i < end; i++) putc(str[i]);
    return;
  }
  inline void flush() {
    fwrite(out, 1, len, stdout);
    len = 0;
  }
} // namespace IO by Macesuted
using IO::flush;
using IO::getstr;
using IO::putc;
using IO::putstr;
using IO::read;
using IO::write;
const int N = 6e5;
int T, E, R, n, v[N], f[N][20], lg[N];
int cmp(int x,int y) {  return v[x] < v[y];  }
void build() {
  FOR (i, 1, n) f[i][0] = i;
  for (int j = 1; (1 << j) <= n; j++) 
    for (int i = 1; i <= (n - (1 << j)  + 1); i++) 
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1], cmp);
}
int rmq(int l,int r) {
  int x = lg[r - l + 1];
  return max(f[l][x], f[r - (1 << x) + 1][x], cmp);
}
long long solve(int l,int r, int st,int ed) {
  if (l > r) return 0;
  ll id = rmq(l, r);
  ll ans = 0, tmp = (ll)(id - l) * R;
  if ((ll)st + tmp > E) 
    ans = solve(l, id - 1, st, E), st = E;
  else st += tmp;
  tmp = (ll)(r - id + 1) * R;
  if (tmp < ed) ed -= tmp;
  else ans += solve(id + 1, r, R, ed), ed = 0;
  ans += (ll)(st - ed) * v[id];
  return ans;
}
signed main () {
  T = read();
  REP (i, 2, N) lg[i] = lg[i >> 1] + 1;
  while (T--) {
    E = read(), R = read(), n = read();
    FOR (i, 1, n)
      v[i] = read();
    build();
    printf("%lld\n", solve(1, n, E, 0) );
  }
  return 0;
}
/*
每天的任务可以做或者不做，做任务得到的代价我们知道为
*/
// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
template<class T>T min(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T max(const T &a, const T &b) {return a > b ? a : b;}
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
int n, mod;
int power(int a,int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
struct node {
  int a[2][2];
  void clear() {
    memset(a, 0, sizeof(a));
    FOR (i, 0, 1) a[i][i] = 1;
  }
  void clear2() {
    memset(a, 0, sizeof(a));
  }
  node operator *  (const node &b) {
    node res;  res.clear2();
    FOR (i, 0, 1) 
      FOR (k, 0, 1)
        FOR (j, 0, 1) 
          res.a[i][j] += a[i][k] * b.a[k][j] % mod, res.a[i][j] %= mod;    
    return res;
  }
}a, b;
node ksm(node a,int k) {
  node ans;  ans.clear();
  while (k) {
    if (k & 1) ans = ans * a;
    a = a * a;
    k >>= 1;
  }
  return ans;
}
signed main () {
  n = read(), mod = read();
  b.a[0][1] = b.a[1][0] = b.a[0][0] = 1;
  int ans = ksm(b, n + 2).a[0][0];
  ans -= n + 2;  ans = ans + mod;  ans %= mod; ans += mod;
  write(power(ans, n + 1)); flush();
  return 0;
}
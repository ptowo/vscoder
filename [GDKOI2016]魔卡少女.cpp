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
#define int long long
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
const int N = 3e5, mod = 1e8 + 7;
class Segment {
  public: 
  struct node {
    int sum, l[2], r[2], ans; 
    node() { l[1] = r[1] = sum = ans = l[0] = r[0] = 0;}
    void get (int x) { l[1] = r[1] = sum = ans = x, l[0] = r[0] = x ^ 1;}
  } s[N];
  friend node operator + (node a,node b) {
    node c;  c.sum = a.sum ^ b.sum;
    c.l[0] = a.l[0] + b.l[a.sum]; c.l[1] = a.l[1] + b.l[a.sum ^ 1];
    c.r[0] = a.r[b.sum] + b.r[0]; c.r[1] = a.r[b.sum ^ 1] + b.r[1];
    c.ans = a.ans + b.ans + a.r[0] * b.l[1] + a.r[1] * b.l[0];
    return c;
  }
  int ls(int p) { return p << 1;}
  int rs(int p) { return p << 1 | 1;}
  void change(int p,int l,int r,int pos,int val) {
    if (l == r) { s[p].get(val); return; }
    int mid = (l + r) >> 1;
    if (pos <= mid) change(ls(p), l, mid, pos, val);
    else change(rs(p), mid + 1, r, pos, val);
    s[p] = s[ls(p)] + s[rs(p)];
  }
  node ask(int p,int l,int r,int nx,int ny) {
    if (nx <= l && r <= ny) return s[p];
    node ans;
    int mid = (l + r) >> 1;
    if (nx <= mid) ans = ans + ask(ls(p), l, mid, nx, ny);
    if (ny > mid) ans = ans + ask(rs(p), mid + 1, r, nx, ny);
    return ans;
  }
}t[10];
int a[N], n, m;
string ch;
signed main () {
  n = read();
  FOR (i, 1, n) a[i] = read();
  FOR (i, 1, n) {
    for (int j = 0; j < 10; j++) 
      t[j].change(1, 1, n, i, (a[i] >> j) & 1);
  }
  m = read();
  FOR (i, 1, m) {
    ch = getstr();
    int l, r, p, x;
    if (ch == "M") {
      p = read(), x = read();
      for (int j = 0; j < 10; j++) 
        t[j].change(1, 1, n, p, (x >> j) & 1);
    }  else {
      l = read(), r = read();
      int ans = 0;
      for (int j = 0; j < 10; j++) 
        ans += t[j].ask(1, 1, n, l, r).ans << j, ans %= mod;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
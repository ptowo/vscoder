// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
const int N = 2e6;
int ct[N];
int n, m, q;
int lowbit(int x) { return x & (-x); }
void change(int x,int val) {
  x += 3;
  for (int i = x; i <= m + 3; i += lowbit(i))
    ct[i] += val;
}
void update(int l,int r,int val) {
  change(l, val); change(r, -val);
}
int ask(int x) {
  int ans = 0; x += 3;
  for (int i = x; i; i -= lowbit(i))
    ans += ct[i];
  return ans;
}
int sum(int l,int r) {
  return ask(r) - ask(l);
}
pair <int,int> latest[N];
int t[N], a[N], b[N], c[N];
signed main() {
  n = gi(), m = gi(), q = gi();
  vector< vector<int> > subt(q);
  for (int i = 1; i <= n; i++) latest[i] = {-1, 0};
  vector<long long> ans;
  for (int i = 1; i <= q; i++) {
    t[i] = gi();
    if (t[i] == 1) 
      a[i] = gi(), b[i] = gi(), c[i] = gi(), a[i]--;
    if (t[i] == 2) {
      a[i] = gi(), b[i] = gi(), a[i]--;
      latest[ a[i] ] = {i, b[i]};
    }
    if (t[i] == 3) {
      a[i] = gi(), b[i] = gi(), a[i]--;
      auto it = latest[a[i]];
      int j = it.first, x = it.second;
      int id = ans.size();
      ans.emplace_back(x);
      c[i] = id;
      if (j >= 0) 
        subt[j].push_back(i);
    }
  }
  atcoder::fenwick_tree<long long> fen(m + 1);
  for (int i = 1; i <= q; i++) {
    if (t[i] == 1) {
      fen.add(a[i], c[i]);
      fen.add(b[i], -c[i]);
    }
    if (t[i] == 2) {
      for (auto j : subt[i])
        ans[ c[j] ] -= fen.sum(0, b[j]);
    }
    if (t[i] == 3) 
      ans [ c[i] ] += fen.sum(0, b[i]);
  }
  for (auto x : ans)  cout << x << '\n';
  return 0; 
}
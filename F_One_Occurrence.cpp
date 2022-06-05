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
const int N = 3e6;
int siz, q, n, a[N], bel, pos[N], cnt[N], vib[N], Ans[N];
struct node { int l, r, id; } p[N];
int cmp(node x, node y) {  return (pos[x.l] == pos[y.l]) ? (pos[x.l] & 1 ? x.r > y.r : x.r < y.r) :  x.l < y.l; }
int st[N], tp;
void add(int pos) {
  int x = a[pos];
  cnt[x]++;
  if (cnt[x] == 1) { st[++tp] = x; vib[x] = tp; }
  if (cnt[x] == 2) {
    st[ vib[x] ] = st[tp], vib[ st[tp] ] = vib[x];
    st[tp--] = 0, vib[x] = 0;
  }
}
void del(int pos) {
  int x = a[pos];
  cnt[x]--;
  if (cnt[x] == 1) { st[++tp] = x; vib[x] = tp;}
  if (cnt[x] == 0) {
    st[ vib[x] ] = st[tp], vib[ st[tp] ] = vib[x];
    st[tp--] = 0, vib[x] = 0;
  }
}
signed main () {
  n = read();
  FOR (i, 1, n) 
    a[i] = read();
  q = read();
  siz = sqrt(q) + 1;
  bel = (n - 1) / siz + 1;
  FOR (i, 1, bel) {
    int L = (i - 1) * siz + 1;
    int R = wmin(i * siz, n);
    FOR (j, L, R) pos[j] = i;
  }
  FOR (i, 1, q) 
    p[i].l = read(), p[i].r = read(), p[i].id = i;
  sort(p + 1, p + q + 1, cmp);
  int l = 1, r = 0;
  FOR (i, 1, q) {
    int ql = p[i].l, qr = p[i].r;
    while (l < ql) del(l++);
    while (l > ql) add(--l);
    while (r < qr) add(++r);
    while (r > qr) del(r--);
    int id = p[i].id;
    if (tp) Ans[id] = st[tp];
  }
  FOR (i, 1, q) write(Ans[i]), putc('\n');
  flush();
  return 0;
}
/*
考虑莫队，莫队如何根号平衡呢
直接记录一下，每次出来打标记？
*/
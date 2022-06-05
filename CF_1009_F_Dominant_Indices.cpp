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
const int N = 1e6 + 155;
int cnt, n, siz[N], dep[N], fa[N], son[N], top[N], in[N], out[N], w[N];
vector <int> ver[N];
void dfs(int x, int f) {
  in[x] = ++cnt;  w[cnt] = x;  fa[x] = f;
  dep[x] = dep[ fa[x] ] + 1;  siz[x] = 1;  
  FORV(i, ver[x]) {
    int to = ver[x][i];
    if(to == f) continue;
    dfs(to, x); 
    if(siz[to] > siz[son[x]]) son[x] = to;
    siz[x] += siz[to];
  }
  out[x] = cnt;
}
int ct[N], mx, id, Ans[N];
void add(int point, int x, int val) {
  ct[ dep[point] ] += val;
  if( (ct[ dep[point] ] > mx || (ct[ dep[point] ] == mx && dep[point] - dep[x] < id - dep[x]) )) {  mx = ct[ dep[point] ];  id = dep[point];  }
}
void dfs3(int x,int fl) {
  FORV(i, ver[x]) {  int to = ver[x][i];  if(to != son[x] && to != fa[x]) dfs3(to, 0);  }
  if(son[x]) dfs3(son[x], 1);
  FORV(i, ver[x]) {  int to = ver[x][i];
    if(to != son[x] && to != fa[x]) {
      FOR(j, in[to], out[to]) add(w[j], x, 1);
    }
  }  add(x, x, 1);  Ans[x] = id;
  if(fl) return;
  FOR(i, in[x], out[x])  add(w[i], x, -1);   mx = 0;  id = 0;
}
signed main () {
  ios::sync_with_stdio(0);  cin.tie(0);cout.tie(0);
  n = read();  REP(i, 1, n) {   int a = read(), b = read();  
    ver[a].emplace_back(b);  ver[b].emplace_back(a);
  }  dfs(1, 0);  dfs3(1, 0);
  FOR(i, 1, n) write(Ans[i] - dep[i]), putc('\n');  flush();
  return 0;
}
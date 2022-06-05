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
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 4e5;
int n, q, tag[N];
vector <int> ver[N];
int f[N], dep[N], siz[N], top[N], son[N], dfn[N], cnt, w[N];
void dfs(int x,int fa) {
  dep[x] = dep[fa] + 1;
  siz[x] = 1;  f[x] = fa;
  FORP(to, ver[x]) {  if(to == fa) continue;  dfs(to, x);
    if(siz[to] > siz[son[x]]) son[x] = to;  siz[x] += siz[to];
  }
}
void dfs2(int now,int x) {
  dfn[now] = ++cnt;  w[cnt] = now;
  top[now] = x;  if(son[now]) dfs2(son[now], x);  FORP(to, ver[now]) {
    if(to != son[now] && to != f[now]) dfs2(to, to);
  }
}
struct node { int sum, mx; }s[N]; 
int ls(int p) { return p << 1; }
int rs(int p) { return p << 1 | 1; }
void pushup(int p) {
  s[p].sum = s[ls(p)].sum + s[rs(p)].sum;
  s[p].mx = max(s[ls(p)].mx, s[rs(p)].mx);
}
void f(int p,int l,int r,int val) {
  s[p].sum = (r - l + 1) * val;
  s[p].mx = val;  s[p].tag = val;
}
void pushdown(int p,int l,int r) {
  if(tag[p]) {
    int mid = (l + r) >> 1;  
    f(ls(p), l, mid, tag[p]);  f(rs(p), mid + 1, r, tag[p]);
    tag[p] = 0; 
  }
}
void update(int p,int l,int r,int nx,int ny, int val) {
  if(nx <= l && t <= ny) {
    s[p].sum = (r - l + 1) * val;
    s[p].mx = val;
    tag[p] = val;
    return;
  }
  pushdown(p, l, r);  int mid = (l + r) >> 1;
  if(nx <= mid) update(ls(p), l, mid, nx, ny, val);  
  if(ny > mid) update(rs(p), mid + 1, r, nx, ny, val);
  pushup(p);
}
int ask(int )
signed main () {
  n = read(), q = read();  REP(i, 1, n) {  int a = read(), b = read();  ver[a].emplace_back(b);  ver[b].emplace_back(a);  }  dfs(1, 0);  dfs2(1, 1);
  FOR(i, 1, q) {
    char s[5];  scanf("%s", s + 1);
    if(s[1] == 'Q' && s[2] == 'S') {

    }
    if(s[1] == 'Q' && s[2] == 'M') {

    }
    if(s[1] == 'C' && s[2] == 'C') {

    }
    if(s[1] == 'C' && s[2] == 'W') {

    }
  }
  return 0;
}
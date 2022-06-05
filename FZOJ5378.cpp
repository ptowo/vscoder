// 寰蜂附鑾庝綘濂藉彲鐖卞痉涓借帋浣犲ソ鍙埍寰蜂附鑾庝綘濂藉彲鐖卞痉涓借帋浣犲ソ鍙埍寰蜂附鑾庝綘濂藉彲鐖?
// 寰蜂附鑾庣殑鍙埍鍦ㄤ簬寰蜂附鑾庡緢鍙埍锛屽痉涓借帋涓轰粈涔堝緢鍙埍鍛紝杩欐槸鍥犱负寰蜂附鑾庡緢鍙埍锛?
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define FOR(i, l, r) for(int i = (l), i##_end = (r); i <= i##_end; ++i)
#define REP(i, l, r) for(int i = (l), i##_end = (r); i <  i##_end; ++i)
#define DFR(i, l, r) for(int i = (l), i##_end = (r); i >= i##_end; --i)
#define DRP(i, l, r) for(int i = (l), i##_end = (r); i >  i##_end; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
#define mod(x) x %= p
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
const int N = 2e6, p = 998244353;
int cnt, n, ans, fa[N], siz[N], in[N], out[N], w[N], son[N], top[N], Now[N];
vector <int> ver[N];
multiset <int> s;
void dfs(int x) {
  in[x] = ++cnt;  w[cnt] = x;  siz[x] = 1;
  FORP(to, ver[x]) {  dfs(to);  siz[x] += siz[to];
    if( siz[to] > siz[ son[x] ] ) son[x] = to;
  }  out[x] = cnt;
}
void dfs2(int now,int x) {
  top[now] = x;  if(son[now]) dfs2(son[now], x);  FORP(to, ver[now]) {
    if(to != fa[now] && to != son[now]) dfs2(to, to);
  }
}
void add(int x) {
  if( s.empty() ) { s.insert(x);  return;  }
  auto it = s.upper_bound(x);
  if( it == s.end() ) {  it = (--s.end());  ans += pow(x - *it, 2);  s.insert(x);  return;  }
  if( it == s.begin() ) {  ans += pow(*it - x, 2);  s.insert(x);  return;  }
  s.insert(x);  auto it2 = s.find(x);  it = s.find(x);  it2++;  it--;
  ans -= pow(*it2 - *it, 2);  ans += pow(x - *it, 2);  ans += pow(x - *it2, 2);
}
void dfs3(int x,int fl) {
  FORV(i, ver[x]) {
    int to = ver[x][i];
    if(to == son[x]) continue;
    dfs3(to, 0);
  }
  if( son[x] ) dfs3(son[x], 1);
  FORV(i, ver[x]) {
    int to = ver[x][i];
    if(to == son[x]) continue;
    FOR(j, in[to], out[to]) {
      int now = w[j];
      add(now);
    }
  }
  add(x);  Now[x] = ans;
  if( fl ) return;
  s.clear();  ans = 0;
}
signed main () {
  n = read();  FOR(i, 2, n) fa[i] = read(), ver[ fa[i] ].emplace_back(i);  dfs(1);  dfs2(1, 1);
  dfs3(1, 0); 
  FOR(i, 1, n) printf("%lld\n", Now[i]);
  return 0;
}
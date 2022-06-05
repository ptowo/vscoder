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
const int N = 2e6;
int n, k, lim, vis[N], dep[N];
vector<int>ver[N];
struct edge { int u, v; } e[N];
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  FORP(to, ver[x]) {
    if(to == fa) continue;  dfs(to, x);
  }
}
void dfs2(int x,int fa) {
  dep[x] = dep[fa] + 1;  vis[x] = 1;
  FORP(to, ver[x]) {
    if(vis[to]) continue;
    dfs2(to, x);
  }
}
signed main () {
  n = read(), k = read();  REP(i, 1, n) {
    int a = read(), b = read();
    ver[a].push_back(b);
    ver[b].push_back(a);
    e[i].u = a, e[i].v = b;
  }
  if(k % 2 == 0) {
    int ans = n;
    FOR(rt, 1, n) {
      FOR(j, 1, n) dep[j] = 0;
      dep[rt] = 0;  dfs(rt, rt);
      int cnt = 0;
      FOR(j, 1, n) {
        if(dep[j] - 1 <= k / 2) cnt++;
      }
      chkmin(ans, n - cnt);
    }
    cout << ans << "\n";  return 0;
  }  else {
    int ans = n;
    FOR(i, 1, n - 1) {
      int cnt = 0;
      FOR(j, 1, n) vis[j] = 0, dep[j] = 0;
      int u = e[i].u, v = e[i].v;
      vis[u] = vis[v] = 1;
      dfs2(u, 0);  dfs2(v, 0);
      FOR(j, 1, n) {
        if(dep[j] - 1 <= k / 2) cnt++;
      }
      chkmin(ans, n - cnt);
    }
    cout << ans << "\n";  return 0;
  }
  return 0;
}
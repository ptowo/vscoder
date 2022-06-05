// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 2e6;
int ok, n, m, num, nex[N], first[N], v[N], w[N];
void add(int from,int to,int val) {
  nex[++num] = first[from]; first[from] = num;
  v[num] = to; w[num] = val;
}
int dis[306], vis[N], vib;
void spfa(int now,int dep,int lim) {
  if (ok) return;
  for (int i = first[now]; i; i = nex[i]) {
    int to = v[i];
    if (dis[to] >= dis[now] + w[i]) {
      if (vis[to] == vib) { ok = 1; return; }
      if (dep == lim) return;
      dis[to] = dis[now] + w[i], vis[to] = vib;
      spfa(to, dep + 1, lim);  vis[to]--;
    }
  }
}
bool check(int mid) {
  FOR (i, 1, n) {
    ok = 0; ++vib;
    memset(dis, 0, sizeof(dis));
    vis[i] = vib; spfa(i, 1, mid);
    if (ok) return 1;
  }
  return false;
}
signed main () {
  n = read(), m = read();
  FOR (i, 1, m) {
    int u = read(), v = read(), w = read();
    add(u, v, w);
  }
  if (!check(n)) { puts("0"); return 0; }
  int l = 1, r = n, ans = INT_MAX;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) 
      ans = mid, r = mid - 1;
    else l = mid + 1;
  }
  cout << ans << "\n";
  return 0;
}
/*
f_{kij} 表示走 2^k 步的 i->j 最小值
转移简单？简单个寄吧
*/
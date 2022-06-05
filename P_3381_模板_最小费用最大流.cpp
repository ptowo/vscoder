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
#define go(u) for (int i = first[u]; i; i = nex[i])
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
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
const int N = 2e6, inf = 1e12;
int n, m, s, t, num = 1, nex[N], first[N], v[N], flow[N], cost[N];
void add(int from,int to,int val,int cos) {
  nex[++num] = first[from]; first[from] = num; v[num] = to; flow[num] = val; cost[num] = cos;
}
queue <int> q;
int dis[N], vis[N], cur[N];
bool spfa(int s,int t) {
  FOR (i, 1, num) vis[i] = 0, dis[i] = inf;
  while (!q.empty()) q.pop();  q.push(s);  dis[s] = 0; vis[s] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop(); cur[u] = first[u];  vis[u] = 0;
    go (u) {
      int to = v[i];
      if (flow[i] && dis[to] > dis[u] + cost[i]) {
        dis[to] = dis[u] + cost[i];
        if (!vis[to]) { q.push(to), vis[to] = 1; }
      }
    }
  } return dis[t] != inf;
}
int dfs(int x,int a) {
  if (x == t) return a;
  vis[x] = 1; int f = 0;
  for (int i = cur[x]; i; i = nex[i]) {
    int to = v[i]; cur[x] = i;
    if (dis[to] == dis[x] + cost[i] && flow[i] && !vis[to]) {
      int now = dfs(to, min(a, flow[i]) );
      flow[i] -= now; flow[i ^ 1] += now;
      f += now; a -= now;
      if (!a) break;
    }
  }
  vis[x] = 0; cur[x] = first[x];  return f;
}
void mxflow(int s,int t) {
  int ansflow = 0, ans = 0;
  while (spfa(s, t)) {
    while (int f = dfs(s, inf)) {
      ansflow += f;
      ans += f * dis[t];
    }
  }
  cout << ansflow << " " << ans << "\n";
}
signed main () {
  n = read(), m = read(), s = read(), t = read();
  FOR (i, 1, m) {
    int u = read(), v = read(), w = read(), cos = read();
    add(u, v, w, cos), add(v, u, 0, -cos);
  }
  mxflow(s, t);
  return 0;
}
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
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
const int N = 2e6, Inf = 1e9;
int n, m, s, t, num = 1, nex[N], first[N], v[N], flow[N], cost[N];
void ins(int from,int to,int val,int cos) {
  nex[++num] = first[from]; first[from ] = num; v[num] = to;
  flow[num] = val; cost[num] = cos;
}
void add(int u,int v, int w,int c) {
  ins(u, v, w, c);
  ins(v, u, 0, -c);
}
queue <int> q;
int id, dis[N], inf[N], pre[N], las[N], vis[N], mxflow, mncost;
bool spfa(int s,int t) {
  FOR (i, 1, id) dis[i] = Inf, inf[i] = Inf, vis[i] = 0;
  q.push(s);
  vis[s] = 1; dis[s] = 0; pre[t] = -1;
  while (q.size()) {
    int u = q.front();  q.pop();
    vis[u] = 0;
    for (int i = first[u]; i; i = nex[i]) {
      int to = v[i];
      if (flow[i] && dis[to] > dis[u] + cost[i]) {
        dis[to] = dis[u] + cost[i];
        pre[to] = u; las[to] = i;
        inf[to] = wmin(inf[u], flow[i]);
        if (!vis[to]) { vis[to] = 1; q.push(to); }
      }
    }
  }
  return pre[t] != - 1;
}
void EK(int s,int t) {
  while (spfa(s, t)) {
    int now = t;
    mxflow += inf[t];
    mncost += inf[t] * dis[t];
    while (now != s) {
      flow[ las[now] ] -= inf[t]; flow[ las[now] ^ 1 ] += inf[t];
      now = pre[now];
    }
  }
}
int k, xx, yx, cnt, idnum[N], x[N], y[N];
pair <int,int> r[N], b[N];
map <int,int> mx, my;
signed main () {
  n = read(), m = read(), k = read(); num = 1;
  FOR (i, 1, n) r[i].first = read(), r[i].second = read();
  FOR (i, 1, m) b[i].first = read(), b[i].second = read();
  sort(r + 1, r + n + 1);
  int nx = 1;
  FOR (i, 2, n) {
    while (nx && r[nx].second <= r[i].second) nx--;
    r[++nx] = r[i];
  }
  n = nx;
  FOR (i, 1, n) {
    if (!mx.count(r[i].first)) mx[r[i].first] = ++id, x[++xx] = r[i].first;
    if (!my.count(r[i].second)) my[r[i].second] = ++id, y[++yx] = r[i].second;
  }
  FOR (i, 1, m) {
    if (!mx.count(b[i].first)) mx[b[i].first] = ++id, x[++xx] = b[i].first;
    if (!my.count(b[i].second)) my[b[i].second] = ++id, y[++yx] = b[i].second;
  }
  t = mx[ r[n].first ], s = ++id;
  sort (x + 1, x + xx + 1), sort(y + 1, y + yx + 1);
  REP (i, 1, xx) add(mx[x[i]], mx[x[i + 1]], x[i + 1] - x[i], Inf), add(mx[x[i + 1]], mx[x[i]], 0, Inf);
  REP (i, 1, yx) add(my[y[i]], my[y[i + 1]], 0, Inf), add(my[y[i + 1]], my[y[i]], y[i + 1] - y[i], Inf);
  FOR (i, 1, m) add(my[b[i].second], mx[b[i].first], 0, 1);
  REP (i, 1, n)add(mx[r[i].first], my[r[i + 1].second], 0, Inf);
  add(s, my[r[1].second], 0, k);
  EK(s, t);
  cout << mncost << "\n";
  return 0;
}
/*
去重，点去重，首先红点排序，然后 x1 <= x2 然后当前 xi 然后找到 yi 大于自己
*/
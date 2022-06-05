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
const int N = 800, INF = 2e16;
int n, m, s, t, num = 1, nex[N], first[N], v[N], flow[N], cost[N];
void add(int from,int to, int val,int cos) {
  nex[++num] = first[from]; first[from ] =num; v[num] = to;
  flow[num] = val; cost[num] = cos;
}
struct qwq { int a, b, c; } e[N];
int t1[600], t2[600], tot, t3[600], t4[600], t5[600];
queue <int> q;
int dis[N], inf[N], pre[N], las[N], vis[N], mxflow, mncost;
bool spfa(int s,int t) {
  FOR (i, 1, tot) dis[i] = INF, vis[i] = 0, inf[i] = INF;
  while (!q.empty()) q.pop();
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
void build() {
  memset(nex, 0, sizeof(nex));
  memset(flow, 0, sizeof(flow));
  memset(cost, 0, sizeof(cost));
  memset(v, 0, sizeof(v));
  memset(first, 0, sizeof(first));
  //FOR (i, 1, num + tot) v[i] = flow[i] = cost[i] = nex[i] = first[i] = 0;
  mxflow = 0; mncost = 0;  
  num = 1; tot = n; s = 1;
  FOR (i, 1, 600) t1[i] = 0, t2[i] = 0, t3[i] = 0, t4[i] = 0, t5[i] = 0;
  FOR (i, 1, n) {
    int x = e[i].a, y = e[i].b, z = e[i].c;
    if ( !t1[x] ) t1[x] = ++tot, t3[x] = ++tot;
  }
  FOR (i, 1, n) {
    int x = e[i].a, y = e[i].b, z = e[i].c;
    if ( !t2[y] ) t2[y] = ++tot;
  }
  tot += 2;
  FOR (i, 1, n) {
    int x = e[i].a, y = e[i].b, z = e[i].c;
    add(i, t1[x], 1, 0);
    add(t1[x], i, 0, 0);
    if (!t4[x]) {
      t4[x] = 1;
      add(s, t1[x], 1, 0);
      add(t1[x], s, 0, 0);
      add(t1[x], t3[x], 1, 0);
      add(t3[x], t1[x], 0, 0);
    }
    add(t3[x], t2[y], 1, -z);
    add(t2[y], t3[x], 0, z);
    if (!t5[y]) {
      t5[y] = 1;
      add(t2[y], tot - 1, 1, 0);
      add(tot - 1, t2[y], 0, 0);
    }
  }
}
void solve() {
  int now = 0;
  vector <int> Ans;
  FOR (k, 1, 2) {
    build();
    add(tot - 1, tot, k, 0);
    add(tot, tot - 1, 0, 0);
    EK(s, tot);
    //cout << mxflow << " "  << mncost << "\n";
    if (mxflow != k) break;
    now = k;
    Ans.push_back(-mncost);
  }
  //if (!now) exit(0);
  write(now); putchar('\n');
  FORP(qw, Ans) write(qw), putchar('\n');
}
signed main () {
  n = read();
  FOR (i, 1, n) {
    e[i].a = read(), e[i].b = read(), e[i].c = read();
  }
  solve();
  /*
  n = read(), m = read(), s = read(), t = read();
  FOR (i, 1, m) {
    int u = read(), v = read(), w = read(), c =  read();
    add(u, v, w, c), add(v, u, 0, -c);
  }
  EK(s, t);
  cout << mxflow << " " << mncost << "\n";*/
  return 0;
}
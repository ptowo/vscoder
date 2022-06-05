#include <bits/stdc++.h>
using namespace std;
const int N =  4e5;
int n, m, a[N];
int num, first[N], v[N], nex[N];
void add(int from,int to) { nex[++num] = first[from]; first[from] = num; v[num] = to; }
int dfn[N], low[N], cnt;
int s[N], tp, in[N], sc, scc[N], p[N];
void tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
  in[u] = 1;
  s[++tp] = u;
  for(int i = first[u]; i; i = nex[i]) {
    int to = v[i];
    if(!dfn[to]) {
      tarjan(to);
      low[u] = min(low[u], low[to]);
    }
    else if(in[to]) {
      low[u] = min(low[u], dfn[to]);
    }
  }
  if(dfn[u] == low[u]) {
    int now;
    ++sc;
    while(1) {
      int now = s[tp];
      scc[now] = sc;
      p[sc] += a[now];
      in[now] = 0;
      tp--;
      if(u == s[tp + 1]) break;
    }
  }
}
vector<int>G[N];
int qa[N], qb[N], deg[N], dp[N];
signed main () {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    add(u, v);
    qa[i] = u, qb[i] = v; 
  }
  for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
  for(int i = 1; i <= m; i++) {
    int u = scc[qa[i]], v = scc[qb[i]];
    if(u == v) continue;
    G[u].push_back(v);
    deg[v]++;
  }
  queue<int>q;
  for(int i = 1; i <= sc; i++) {
    if(!deg[i]) q.push(i), dp[i] = p[i];
  }
  while(q.size()) {
    int u = q.front(); q.pop();
    for(int i = 0; i < G[u].size(); i++) {
      int to = G[u][i];
      deg[to]--;
      dp[to] = max(dp[to], dp[u] + p[to]);
      if(!deg[to]) q.push(to);
    }
  }
  int ans = 0;
  for(int i = 1; i <= sc; i++) ans = max(ans, dp[i]);
  cout << ans << "\n";
  return 0;
}
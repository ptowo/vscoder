// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 3e6;
int n, m, num, nex[N], first[N], v[N];
void add(int from,int to) {
  nex[++num] = first[from]; first[from] = num; v[num] = to;
}
vector < pair<int,int> > ans;
int vis[N];
void dfs(int x,int fa) {
  vis[x] = 1;
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i]; if (vis[to]) continue;
    ans.push_back(make_pair(x, to));
    dfs(to, x);
  }
}
signed main () {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    add(u, v), add(v, u);
  }
  for (int i = 1; i <= n; i++) vis[i] = 0; dfs(1, 0);
  for (auto it : ans) printf("%d %d\n", it.first, it.second);
  queue <int> q; for (int i = 1; i <= n; i++) vis[i] = 0; q.push(1); ans.clear(); vis[1] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = first[u]; i; i = nex[i]) {
      int to = v[i]; if (vis[to]) continue;
      ans.push_back(make_pair(u, to));  q.push(to); vis[to] = 1;
    }
  }
  for (auto it : ans) printf("%d %d\n", it.first, it.second);
  return 0;
}
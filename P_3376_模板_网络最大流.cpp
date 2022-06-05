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
int n, m, s, t, num = 1, nex[N], first[N], v[N], flow[N], cur[N];
void add(int from,int to,int val) {
  nex[++num] = first[from];  first[from] = num;
  v[num] = to;  flow[num] = val;
}
queue <int> q;
int dep[N];
bool bfs(int s,int t) {
  FOR (i, 0, num) dep[i] = 0;  dep[s] = 1;
  while (!q.empty()) q.pop();  q.push(s);
  while (q.size()) {
    int u = q.front();  q.pop(); cur[u] = first[u]; 
    go (u) {
      int to = v[i]; if (dep[to] || !flow[i]) continue;
      dep[to] = dep[u] + 1;  q.push(to); cur[to] = first[to];
    }
  }  return dep[t] != 0;
}
int dfs(int x,int a) {
  if (x == t) return a;
  int f = 0;
  for (int i = cur[x]; i; i = nex[i]) {
    int to = v[i];  cur[x] = i;
    if (dep[to] == dep[x] + 1 && flow[i]) {
      int now = dfs(to, wmin(a, flow[i]) );
      flow[i] -= now;  flow[i ^ 1] += now;
      a -= now;  f += now;  if (!a) break;
    }
  }
  return f;
}
void mxflow(int s,int t) {
  int ans = 0;
  while (bfs(s, t)) ans += dfs(s, 1ll << 30);
  cout << ans << "\n";
}
signed main () {
  n = read(), m = read(), s = read(), t = read();
  FOR (i, 1, m) {
    int u = read(), v = read(), w = read();
    add(u, v, w), add(v, u, 0);
  }
  mxflow(s, t);
  return 0;
}
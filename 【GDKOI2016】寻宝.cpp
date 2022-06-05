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
const int N = 2e6, inf = 2e17;
int num = 1, v[N], first[N], nex[N];
double flow[N];
void add(int from,int to,double val) { 
  nex[++num] = first[from]; first[from] = num;
  v[num] = to; flow[num] = val;
}
int dep[N], aim, cur[N], tot, s, t;
queue <int> q;
int n, A[N], B[N];
vector <int> pos[N];
const double eps = 1e-6;
int bfs(int s,int t) {
  while (!q.empty()) q.pop();
  FOR (i, 1, n + 6 ) dep[i] = 0;
  q.push(s); dep[s] = 1;
  while (!q.empty()) {
    int u = q.front(); q.pop(); cur[u] = first[u];
    for (int i = first[u]; i; i = nex[i]) {
      int to = v[i];
      if (flow[i] > eps && !dep[to]) 
        dep[to] = dep[u] + 1, q.push(to);
    }
  } return dep[t] != 0;
}
double dfs(int now,double fl) {
  if(now == aim) return fl;
  double f = 0;
  for(int i = cur[now]; i; i = nex[i]) {
    int to = v[i];  cur[now] = i;
    if(dep[to] == dep[now] + 1 && flow[i] > eps) {
      double x = dfs(to, min(flow[i], fl) );
      flow[i] -= x, flow[i ^ 1] += x;
      fl -= x, f += x; 
      if(!fl) break;
    }
  }
  if(!f) dep[now] = -2;
  return f;
}
bool check(double mid) {
  FOR (i, 1, num * 2) flow[i] = 0, first[i] = 0, nex[i] = 0; 
  num = 1; s = n + 1; t = n + 2;  aim = t;
  FOR (i, 1, n) {
    FORP (to, pos[i]) 
      add(i, to, inf), add(to, i, 0);
  }
  double sum = 0;
  FOR (i, 1, n) {
    double val = (double) mid * 1.0 *  A[i] - B[i] * 1.0;
    if (val > 0) 
      add(s, i, val), add(i, s, 0), sum += val;
    else add(i, t, -val), add(t, i, 0);
  }
  while ( bfs(s, t) ) 
    sum -= dfs(s, inf);
  if (sum > 0) return 1;
  return 0;
}
signed main () {
  n = read();
  FOR (i, 1, n) {
    int k = read();
    FOR (j, 1, k) {  
      int it = read();
      pos[i].emplace_back( it );
    }
  }
  FOR (i, 1, n) 
    A[i] = read(), B[i] = read();
  double l = 0.0, r = 100000000.0, ans = -1.0;
  while (r - l > eps) {
    double mid = (l + r) * 1.0 / 2.0;
    if (check(mid)) r = mid;
    else l = mid;
  }
  if (l > eps) printf("%.6lf", l);
  else printf("CanNotFindTreasure!");
  return 0;
}
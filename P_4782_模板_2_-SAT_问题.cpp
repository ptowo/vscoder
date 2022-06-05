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
const int N = 2e6;
int n, m, num, nex[N], first[N], v[N];
int low[N], dfn[N], in[N], cnt, scc[N], sc;
stack <int> st;
void add(int from,int to) {
  nex[++num] = first[from]; first[from] = num; v[num] = to;
}
void tarjan(int u) {
  low[u] = dfn[u] = ++cnt;  st.push(u); in[u] = 1;
  go (u) {
    int to = v[i];
    if (!dfn[to]) tarjan(to), chkmin(low[u], low[to]);
    else if (in[to]) chkmin(low[u], dfn[to]);
  }
  if (low[u] == dfn[u]) {
    ++sc; do {
      scc[u] = sc; u = st.top(); st.pop(); in[u] = 0;
    } while (low[u] != dfn[u]);
  }
}
signed main () {
  n = read(), m = read();
  FOR (i, 1, m) {
    int ia, ib, a, b; ia = read(), a = read(), ib = read(), b = read();
    if (a == 1 && b == 1) {
      add(ia, ib + n); add(ib, ia + n);
    }
    if (a == 0 && b == 0) {
      add(ib + n, ia), add(ia + n, ib);      
    }
    if (a == 1 && b == 0) {
      add(ia, ib);  add(ib + n, ia + n);
    }
    if (a == 0 && b == 1) {
      add(ia + n, ib + n); add(ib, ia);
    }
  }
  FOR (i, 1, 2 * n) if (!dfn[i]) tarjan(i);
  FOR (i, 1, n) 
    if (scc[i] == scc[i + n]) {  printf("IMPOSSIBLE\n"); return 0; }
  printf("POSSIBLE\n");
  FOR (i, 1, n) {
    if (scc[i] > scc[i + n]) printf("1 ");
    else printf("0 ");
  }
  return 0;
}
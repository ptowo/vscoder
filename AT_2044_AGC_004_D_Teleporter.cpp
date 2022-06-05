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
#define Fedge(i, x) for (int i = first[x]; i; i = nex[i])
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
int n, k, sum, num, ans, nex[N], first[N], v[N], a[N], dep[N], siz[N];
void add(int from,int to) {
  nex[++num] = first[from];  first[from] = num; v[num] = to;
}
int dis[N], vis[N];
void dfs(int x,int fa) {
  Fedge (i, x) {
    int to = v[i]; if (to == fa ) continue; dfs(to, x);
    dis[x] = wmax(dis[to] + 1, dis[x]);
  }
  if (dis[x] == k - 1 && fa > 1 && a[x] ^ 1) { ans++; dis[x] = -1; } 
}
signed main () {
  n = read(), k = read();
  FOR (i, 1, n) a[i] = read();
  FOR (i, 2, n) add(i, a[i]), add(a[i], i);
  if (a[1] != 1) ans++;  dfs(1, 0);
  write(ans); putchar('\n');
  return 0;
}
/*
传送 k 次都必须要在 1
1 自环不就好了...
然后剩余的点咋办啊，要求到 1 不超过 k 就好了
哦建个图，一个点改肯定改到 1 最优，哦，这简单
然后取不合法的一串链出来，总和除一下，简单
wa 了，唔，从下往上贪心吗？试试
*/
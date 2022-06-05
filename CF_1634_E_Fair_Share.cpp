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
template<class T>T min(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T max(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 2e6;
int m, num, val, fn[N];
map <int,int> mp;
unordered_map <int,int> vis[N];
vector <int> ans[N];
vector < pair<int,pair<int,int> > > ver[N];
void add(int u,int v,int x,int y) {
  ver[u].emplace_back( make_pair(v, make_pair(x, y) ) );
  ver[v].emplace_back( make_pair(u, make_pair(x, y) ) );
}
void dfs(int u) {
  for ( ; ; ) {
    if ( ver[u].size() ) {
      pair<int, pair<int,int> > it = ver[u].back();
      ver[u].pop_back();
      int x = it.second.first, y = it.second.second;
      if (vis[x][y]) continue;
      vis[x][y] = 1;  ans[x][y] = val;  val ^= 1;
      dfs( it.first );
    }  else break;
  }
}
signed main () {
  num = m = read();
  FOR (i, 1, m) { 
    int len = read(); fn[i] = len;
    ans[i].resize(len + 1);
    FOR (j, 1, len) {
      int x = read();
      if( !mp[x] ) mp[x] = ++num;
      add( i, mp[x], i, j );
    }
  }
  FOR (i, 1, num) 
    if( ver[i].size() % 2) {  puts("NO");  return 0;};
  FOR (i, 1, num) dfs(i);
  puts("YES");  FOR (i, 1, m) {
    FOR (j, 1, fn[i]) {
      int to = ans[i][j];
      printf("%c", (to ? 'R' : 'L'));
    }
    printf("\n");
  }
  return 0;
}

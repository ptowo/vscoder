// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define int long long
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
int t, n, a[N], vis[N], b[N], tot;
map <int,int> cnt;
signed main () {
  t = read();
  while (t--) {
    n = read(); cnt.clear();
    FOR (i, 1, n) a[i] = read();
    if(n == 1) { printf("YES\n");  continue;  }
    sort(a + 1, a + n + 1);  int s = 0;
    FOR (i, 1, n) s += a[i];
    FOR (i, 1, n) cnt[ a[i] ] ++;
    queue <int> q;  q.push(s);
    REP (i, 1, n) {
      int u = q.front();  q.pop();
      int x = u / 2; int y = u - x;
      if (!cnt.count(x)) q.push(x);
      else if(--cnt[x] == 0) cnt.erase(x);
      if (!cnt.count(y)) q.push(y);
      else if(--cnt[y] == 0) cnt.erase(y);
    }
    if(cnt.empty() && q.empty()) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
/*
14
1
327 test1
2
869 541 test2
2
985214736 985214737 test3
3
2 3 1 test4
3
2 3 3 test5
6
1 1 1 1 1 1 test6
6
100 100 100 100 100 100 test7
8
100 100 100 100 100 100 100 100
8
2 16 1 8 64 1 4 32
10
1 2 4 7 1 1 1 1 7 2
10
7 1 1 1 3 1 3 3 2 3
10
1 4 4 1 1 1 3 3 3 1
10
2 3 2 2 1 2 2 2 2 2
4
999999999 999999999 999999999 999999999
*/
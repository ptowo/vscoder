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
const int N = 3e5;
int h, w, m, ans, c[N], r[N], tr[N];
pair <int,int> a[N];
int lowbit(int x) {
  return x & (-x);
}
void change(int x,int val) {
  for (int i = x; i <= N; i += lowbit(i)) 
    tr[i] += val;
}
int ask(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i))
    ans += tr[i];
  return ans;
}
void clear() {
  for (int i = 1; i <= N; i++)
    c[i] = 0;
}
vector <int> g[N];
signed main () {
  h = read(), w = read(), m = read();
  FOR (i, 1, h)
    r[i] = w + 1;
  FOR (i, 1, w)
    c[i] = h + 1;
  FOR (i, 1, m) {
    a[i].first = read(), a[i].second = read();
    chkmin( r[ a[i].first ] , a[i].second);
    chkmin( c[ a[i].second ], a[i].first);
  }
  sort(a + 1, a + m + 1);
  FOR (i, 1, c[1] - 1) 
	  ans += r[i] - 1;
	FOR (i, c[1], h)
	  r[i] = 1;
	FOR (i, 1, h)
	  g[ r[i] ].emplace_back(i);
	FOR (i, 1, w) {
		if (c[i] == 1) break;
		ans += ask(c[i] - 1);
		FORP (j, g[i]) change(j, 1);
	}
	printf("%lld\n", ans);
  return 0;
}
/*
哦，一个网格, h, w<= 2e5，从左上角的车开始，可以移动两部，有 m 个障碍物
问能到达多少个格子，这种有障碍物之类的，大概我一般考虑的算法是扫描线？
不对啊，想想，他往下和往右的区间是不是其实被卡住了。

*/
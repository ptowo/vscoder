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
const int N = 2e6;
int n, now;
pair <int,int> a[N];
priority_queue < pair<int,int> > q;
vector <int> ans;
signed main () {
  n = read();
  FOR (i, 1, n)
    a[i].first = read();
  FOR (i, 1, n) 
    a[i].second = read();
  FOR (i, 1, n) {
    now += a[i].first; 
    if (now >= a[i].second) 
      now -= a[i].second, q.push( {a[i].second, i} );
    else 
      if ( !q.empty() && q.top().first > a[i].second ) 
        now += q.top().first, q.pop(), now -= a[i].second, q.push( {a[i].second, i} );
  }
  while ( !q.empty() )  
    ans.emplace_back( q.top().second), q.pop();
  sort(ans.begin(), ans.end());
  printf("%lld\n", (int)ans.size());
  FORP (x, ans)
    printf("%lld ", x);
  return 0;
}
/*
看看，一种贪心是，能卖就卖，很傻逼。
然后反悔，如果当前不能卖，但是之前有一个，哦，完了。
咦，好像过不去样例，画一下。
写挂了。
*/
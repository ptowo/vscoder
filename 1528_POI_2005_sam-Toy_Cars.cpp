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
const int N = 4e6;
int n, k, ans, p, a[N], nex[N], pre[N], vis[N], las[N];
vector <int> pos[N];
priority_queue < pair<int,int> > q;
signed main () {
  n = read(), k = read(), p = read();
  FOR (i, 1, p)
    a[i] = read(), las[ a[i] ] = p + 1;
  DFR (i, p, 1) 
    nex[i] = las[ a[i] ], las[ a[i] ] = i;
  FOR (i, 1, p) {
    if (vis[ a[i] ])
      { q.push( make_pair(nex[i], a[i]) ); continue; }
    if (k != 0) 
      k--, ans++, q.push( make_pair(nex[i], a[i]) ), vis[ a[i] ] = 1; 
    else {
      while ( !vis[q.top().second] ) 
        q.pop();
      int now = q.top().second;
      while (q.top().second == now)
        q.pop();
      vis[ now ] = 0, ans++, vis[ a[i] ] = 1; q.push(make_pair(nex[i], a[i]));
    }
  }
  printf("%lld\n", ans);
  return 0;
}
/*
哦，原来这是要自己思考的题目
n个不同的玩具，任何时候地板上不会超过k个玩具
知道玩玩具的顺序，求问最少拿多少次车
考虑贪心，如果我还地上没放过，那我直接拿这个下来
否则如果地上放满了，这个时候出现了一个不在地上的，我就需要拿一个下来
额，放回下次时间最远的
*/
// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
#define int long
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
#define x1 _x1
#define x2 _x2
#define y1 _y1
#define y2 _y2
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
const int N = 2e5, inf = 2e16;
int n, m, qq, num = 1, nex[N], first[N], v[N], w[N];
void add(int from,int to,int val) {
  nex[++num] = first[from]; first[from] = num;
  v[num] = to; w[num] = val;
}
int id(int i,int j) {
  return (i - 1) * m + j; }
struct node {
  int x, y, id;
  
};
int dis[N];
priority_queue < pair<int,int> > q;
void dij(int l1,int r1,int l2,int r2,int s) {
  FOR (i, l1, l2)
    FOR (j, r1, r2)
      dis[ id(i,j) ] = inf;
  dis[s] = 0;
  q.push( make_pair(0, s) );
  while (!q.empty()) {
    auto u = q.top(); q.pop();
    if (-u.first > )
  }
}
	for(int i=lx;i<=rx;i++)for(int j=ly;j<=ry;j++)dis[id(Point(i,j))]=INF,vis[id(Point(i,j))]=0;
	dis[id(Point(x,y))]=0;
	pq.push(mp(0,Point(x,y)));
	while(!pq.empty()){
		Point u=pq.top().se;int d=pq.top().fi;pq.pop();
		if(d!=dis[id(u)]||vis[id(u)])continue;
		vis[id(u)]=true;
		for(int i=head[id(u)];i;i=e[i].nxt){
			Point v=e[i].to;
			if(in(v,lx,rx,ly,ry)&&dis[id(u)]+e[i].w<dis[id(v)]){
				dis[id(v)]=dis[id(u)]+e[i].w;
				pq.push(mp(dis[id(v)],v));
			}
		}
	}
}
signed main () {
  n = read(), m = read();
  FOR (i, 1, n) 
    REP (j, 1, m) {
      int x = read();
      add( (i - 1) * m + j, (i - 1) * m + j + 1, x);
      add( (i - 1) * m + j + 1, (i - 1) * m + j, x);
    }
  REP (i, 1, n) 
    FOR (j, 1, m) {
      int x = read();
      add( (i - 1) * m + j, i * m + j, x);
      add( i * m + j, (i - 1) * m + j, x);
    }
  qq = read();
  FOR (i, 1, qq) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();

  }
  return 0;
}
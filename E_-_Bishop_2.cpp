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
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
const int N = 2300, M = 5e6;
int n, ax, ay, bx, by;
int a[N][N], vis[N][N], step[N][N];
int dx[5] = {1, 1, -1, -1};
int dy[5] = {-1, 1, -1, 1};
pair <int, pair<int,int> > q[M];
int l, r;
signed main () {
  n = read();
  ax = read(), ay = read(), bx = read(), by = read();
  FOR (i, 1, n) {
    char s[N];  scanf("%s", s);
    REP (j, 0, n) a[i][j + 1] = (s[j] == '.');
  }
  //queue < pair <int, pair<int,int> > > q;
  q[r = 1] = make_pair(0, make_pair(ax, ay)); 
  //q.push (make_pair(0, make_pair(ax, ay))); 
  vis[ax][ay] = 1; 
  while (l < r) {
    auto u = q[++l];
    //auto u = q.front(); q.pop();
    int nx = u.second.first, ny = u.second.second;
    if (nx == bx && ny == by) {  cout << u.first << "\n";  return 0;  }
    REP (i, 0, 4) {
      int xx = nx + dx[i], yy = ny + dy[i];
      while (xx >= 1 && xx <= n && yy >= 1 && yy <= n && a[xx][yy]) {
        if (!step[xx][yy]) {
          step[xx][yy] = step[nx][ny] + 1;
          q[++r] = make_pair( u.first + 1, make_pair(xx, yy) );
          //q.push(  );
        }
        else if (step[xx][yy] <= step[nx][ny]) break;
        xx += dx[i], yy += dy[i];
      }
    }
  }
  cout << "-1\n";
  return 0;
}
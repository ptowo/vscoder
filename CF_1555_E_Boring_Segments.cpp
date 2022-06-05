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
const int N = 5e6;
struct node { int tag, val; }s[N];
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
void push(int p, int val) { s[p].tag += val, s[p].val += val; }
void pushdown(int p) {
  if(s[p].tag) {
    push(ls(p), s[p].tag);  push(rs(p), s[p].tag); s[p].tag = 0;
  }
}
void pushup(int p) { s[p].val = wmin(s[ls(p)].val, s[rs(p)].val); }
void change(int p,int l,int r,int nx,int ny, int val) {
  if(nx <= l && r <= ny) {
    push(p, val);  return;
  }  pushdown(p);
  int mid = (l + r) >> 1;
  if(nx <= mid) change(ls(p), l, mid, nx, ny, val);
  if(ny > mid) change(rs(p), mid + 1, r, nx, ny, val);
  pushup(p);
}
int n, m, ans = INT_MAX;
pair <int, pair<int,int> > a[N];
int cmp( pair<int, pair<int,int>> a, pair<int, pair<int,int>> b) {  return a.second.second < b.second.second;  }
signed main () {
  n = read();  m = read() - 1; FOR(i, 1, n) {
    a[i].first = read(); a[i].second.first = read() - 1; a[i].second.second = read();
  } 
  sort(a + 1, a + n + 1, cmp);
  int j = 0;
  FOR(i, 1, n) {
    while(j < n && s[1].val < 1) j++, change(1, 1, m, a[j].first, a[j].second.first, 1);
    //cout << a[i].second.second << " " << a[j].second.second << "\n";
    if(s[1].val >= 1) ans = min(ans, a[j].second.second - a[i].second.second);
    change(1, 1, m, a[i].first, a[i].second.first, -1);
  }
  cout << ans << "\n";
  return 0;
}
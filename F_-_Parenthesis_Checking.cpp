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
const int N = 2e6, INF = 2e9;
int s[N], tag[N], a[N], b[N], n, q;
int ls(int p) { return p << 1; }
int rs(int p) { return p << 1 | 1; }
void pushup(int p) {  s[p] = min(s[ls(p)], s[rs(p)]); }
void build(int p,int l,int r) {
  if(l == r) { s[p] = a[l];  return; } int mid = (l + r) >> 1;
  build(ls(p), l, mid), build(rs(p), mid + 1, r);  pushup(p);
}
void solve(int p, int val) { s[p] += val;  tag[p] += val;  }
void pushdown(int p) {
  if(!tag[p]) return;  solve(ls(p), tag[p]), solve(rs(p), tag[p]); 
  tag[p] = 0;
}
void update(int p,int l,int r,int nx,int ny,int val){
  if(nx <= l && r <= ny) {  solve(p, val);  return;
  }  pushdown(p);  int mid = (l + r) >> 1;
  if(nx <= mid) update(ls(p), l, mid, nx, ny, val); 
  if(ny > mid) update(rs(p), mid + 1, r, nx, ny, val);
  pushup(p);
}
int ask(int p,int l,int r,int nx,int ny) {
  int ans = INF;
  if(nx <= l && r <= ny) return s[p];  pushdown(p); int mid = (l + r) >> 1;
  if(nx <= mid) ans = min(ans, ask(ls(p), l, mid, nx, ny));
  if(ny > mid) ans = min(ans, ask(rs(p), mid + 1, r, nx, ny)); 
  pushup(p);  return ans;
}
signed main () {
  n = read(), q = read();  FOR(i, 1, n) {
    char ch = getchar();
    a[i] = a[i - 1];
    if(ch == '(') a[i]++, b[i] = 1;
    else a[i]--;
    //cout << a[i] << " " << b[i] << "\n";
  }
  //cout << "\n";
  build(1, 1, n);
  FOR(i, 1, q) {
    int op = read(), l = read(), r = read();
    if(op == 1) {
      if(b[l] == b[r]) continue;
      if(b[l]) update(1, 1, n, l, r - 1, -2);
      else update(1, 1, n, l, r - 1, 2);  swap(b[l], b[r]);
    }  else {
      int s;  if(l == 1) s = 0;
      else s = ask(1, 1, n, l - 1, l - 1);
      //cout << s << " " << ask(1, 1, n, l, r) << " " << ask(1, 1, n, r, r) << "qwq\n";
      if(ask(1, 1, n, l, r) - s < 0 || ask(1, 1, n, r, r) != s) printf("No\n");
      else printf("Yes\n");
    }
  }
  return 0;
}
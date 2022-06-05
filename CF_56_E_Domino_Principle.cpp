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
const int N = 2e6;
int n, s[N], mp[N], tot;
struct node {  int pos, h, id;  } a[N];
inline int cmp(node x, node y) {
  return x.pos < y.pos;
}
int ls(int p) { return p << 1;}
int rs(int p) { return p << 1 | 1;}
void change(int p,int l,int r,int pos,int val) {
  if(pos < l || pos > r) return;
  if(l == r) {  s[p] = wmax(s[p], val);  return;  }
  int mid = (l + r) >> 1;
  change(ls(p), l, mid, pos, val), change(rs(p), mid + 1, r, pos, val);
  s[p] = wmax(s[ls(p)], s[rs(p)]);
}
int ask(int p,int l,int r,int nx,int ny) {
  if(nx <= l && r <= ny) return s[p];
  int mid = (l + r) >> 1, ans = 0;
  if(nx <= mid)  ans = wmax(ans, ask(ls(p), l, mid, nx, ny));
  if(ny > mid)  ans = wmax(ans, ask(rs(p), mid + 1, r, nx, ny));
  return ans;
}
int Ans[N], R[N], New[N];
signed main () { 
  n = read();
  FOR(i, 1, n) a[i].pos = read(), a[i].h = read(), a[i].id = i;
  sort(a + 1, a + n + 1, cmp);
  DFR(i, n, 1) {
    int x = a[i].pos, y = a[i].pos + a[i].h - 1;
    int l = 1, r = n, ans = i;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(a[mid].pos <= y) {
        ans = mid;
        l = mid + 1;
      }  else r = mid - 1;
    }  R[i] = ans;
    int qwq = ask(1, 1, n, i, ans);  qwq = max(qwq, ans);
    change(1, 1, n, i, qwq);
  }
  FOR(i, 1, n) {
    int rr = ask(1, 1, n, i, R[i]);
    New[a[i].id] = rr - i + 1;
  }
  FOR(i, 1, n) printf("%d ", New[i]);
  return 0;
}
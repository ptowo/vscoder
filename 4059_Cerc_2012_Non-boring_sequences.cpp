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
const int N = 2e6;
int T, n, ans, a[N], pre[N], nxt[N], b[N];
vector <int> pt[N];
void solve(int l,int r) {
  if (ans || l >= r)
    return;
  int ql = l, qr = r, op = 0, pos = 0;
  while (ql <= qr) {
    if (op)
      if ( pre[ql] < l && nxt[ql] > r ) 
        { pos = ql; break; }
      else 
        ql++;
    else  
      if ( pre[qr] < l && nxt[qr] > r ) 
        { pos = qr; break;}
      else 
        qr--;
    op ^= 1;   
  }
  if (!pos) 
    { ans = 1; return; }
  solve(l, pos - 1), solve(pos + 1, r);
}
void build(int o,int l,int r) {
    if(l==r) cin>>tree[o];
    build(ls,l,mid);
    build(rs,mid+1,r);
    tree[o] = max(tree[ls],tree[rs]);
}
int get(int o, int l, int r, int x) {
    if (l == r) return l;
    return tree[ls] > x ? get(ls, l, mid, x) : get(rs, mid+1, r, x);
}
int query(int o, int l, int r, int ql, int qr, int x) { //查询[ql,qr]内第一个大于x的数的位置
    if (qr < l || r < ql) return -1;
    if (ql <= l && r <= qr) return tree[o] > x ? get(o, l, r, x) : -1;
    int t = query(ls, l, mid, ql, qr, x);
    return t != -1 ? t : query(rs, mid+1, r, ql, qr, x);
}
int get(int p,int l,int r,int x) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  return s[ls(p)] > x ? get(ls(p), l, mid, x) : get(rs(p), mid + 1, r, x);
}
int ask(int p,int l,int r,int nx,int ny,int x) {
  if (ny < l || nx > r) return -1;
  if (nx <= l && r <= ny) 
    return s[p] > x ? get(p, l, r, x) : -1;
  int t = ask(ls(p), l, mid, nx, ny, x);
  if (t != -1) return t;
  return ask(rs(p), mid + 1, r, nx, ny);
}
signed main () {
  T = read();
  while (T--) {
    n = read();
    FOR (i, 1, n)
      b[i] = a[i] = read();
    sort(b + 1, b + n + 1);
    int num = unique(b + 1, b + n + 1) - (b + 1);
    FOR (i, 1, n) 
      a[i] = lower_bound(b + 1, b + num + 1, a[i]) - b;
    FOR (i, 1, num)
      pt[i].clear();
    FOR (i, 1, n)
      pt[ a[i] ].emplace_back(i);
    FOR (i, 1, num) {
      if (pt[i].size() == 1) 
        {  pre[ pt[i][0] ] = 0; nxt[ pt[i][0] ] = n + 1; continue;  }
      int now = pt[i].size() - 1;
      pre[ pt[i][now] ] = pt[i][now - 1]; nxt[ pt[i][now] ] = n + 1;
      pre[ pt[i][0] ] = 0; nxt[ pt[i][0] ] = pt[i][1];
      for (int j = 1; j < pt[i].size() - 1; j++) 
        pre[ pt[i][j] ] = pt[i][j - 1], nxt[ pt[i][j] ] = pt[i][j + 1];
    }
    ans = 0;  solve(1, n);
    if (ans)
      printf("boring\n");
    else 
      printf("non-boring\n");
  }
  return 0;
}
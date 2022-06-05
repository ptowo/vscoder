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
#define mid (l + r) >> 1
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
int n, m, s[N], s1[N], s2[N];
// sp 表示的是 p 的答案， s1p 表示的是 往左最近的一个 (XXX s2[p] 表示的是是否有往右的 XXX)
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return p << 1 | 1; }
void pushup(int p) {

}
void build(int p,int l,int r) {
  if (l == r)  return;
  build (ls(p), l, mid), build (rs(p), mid + 1, r);
  pushup(p);
}
void change(int p,int l,int r) {
  if (l == r) {

    return;
  }
  change(ls(p), l, mid), change(rs(p), mid + 1, r);
  pushup(p);
}
int ask(int p,int l,int r,int nx,int ny) {
  if (nx <= l && r <= ny) 
}
signed main () {
  n = read(), m = read();
  FOR (i, 1, m) {
    int op = read(), l, r; char c;
    if (op == 1) {
      scanf("%c", &c);

    }  else {
      l = read(), r = read();
    }
  } 
  return 0;
}
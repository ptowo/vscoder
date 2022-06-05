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
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
const int N = 2e5 + 5;
int n, m, k, c[N], ans[N];
struct node { int a, b, c, cnt, ans; } q[N], a[N];
int cmp(node x, node y) { return x.a != y.a ? x.a < y.a : x.b != y.b ? x.b < y.b : x.c < y.c; }
int cmpb (node x, node y) { return x.b != y.b ? x.b < y.b : x.c < y.c; }
int lowbit(int x) { return x & (-x); }
void add(int x, int val) {  for (int i = x; i <= k; i += lowbit(i)) c[i] += val;  }
int ask(int x) { int ans = 0; for (int i = x; i; i -= lowbit(i)) ans += c[i];  return ans; }
void cdq(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;  cdq(l, mid); cdq(mid + 1, r);
  sort(a + l, a + mid + 1, cmpb), sort(a + mid + 1, a + r + 1, cmpb);
  int i = l, j = mid + 1;
  for (; j <= r; j++) {
    while (a[i].b <= a[j].b && i <= mid) add(a[i].c, a[i].cnt), i++;
    a[j].ans += ask(a[j].c);
  }
  for (int j = l; j < i; j++) add(a[j].c, -a[j].cnt);
} 
signed main () {
  n = read(), k = read();
  FOR (i, 1, n) q[i].a = read(), q[i].b = read(), q[i].c = read(), q[i].cnt++;
  sort(q + 1, q + n + 1, cmp);  a[++m] = q[1];
  FOR (i, 2, n) 
    if (q[i].a == q[i - 1].a && q[i].b == q[i - 1].b && q[i].c == q[i - 1].c) a[m].cnt++;
    else a[++m] = q[i];
  cdq(1, m);  FOR (i, 1, m) ans[ a[i].ans + a[i].cnt - 1] += a[i].cnt;
  REP (i, 0, n) write(ans[i]), putchar('\n');
  return 0;
}
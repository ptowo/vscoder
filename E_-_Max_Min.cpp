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
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return ;
}
const int N = 2e7;
int n, x, y, a[N];
int tot, lc[N], rc[N], siz[N], rt[N], tp;
void update(int k,int pre,int &now,int l,int r) {
  now = ++tot; lc[now] = lc[pre];  rc[now] = rc[pre];
  siz[now] = siz[pre] + 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (k <= mid) update(k, lc[pre], lc[now], l, mid);
  else update(k, rc[pre], rc[now], mid + 1, r);
}
int ask(int pre,int now,int nx,int ny,int l,int r) {
  if (nx <= l && r <= ny) return siz[now] - siz[pre];
  int mid = (l + r) >> 1, ans = 0;
  if (nx <= mid) ans += ask( lc[pre], lc[now], nx, ny, l, mid);
  if (ny > mid) ans += ask( rc[pre], rc[now], nx, ny, mid + 1, r);
  return ans;
}
int sa[N], num, ans;
signed main () {
  n = read(), x = read(), y = read();
  swap(x, y);
  sa[++num] = x;  sa[++num] = y;
  FOR (i, 1, n) a[i] = read(), sa[++num] = a[i];
  sort(sa + 1, sa + num + 1);  num = unique(sa + 1, sa + num + 1) - (sa + 1);
  FOR (i, 1, n) a[i] = lower_bound(sa + 1, sa + num + 1, a[i]) - sa + 1;
  x = lower_bound(sa + 1, sa + num + 1, x) - sa + 1;
  y = lower_bound(sa + 1, sa + num + 1, y) - sa + 1;
  num += 3;
  FOR (i, 1, n) update( a[i], rt[i - 1], rt[i], 1, num);
  FOR (i, 1, n) {
    //cout << a[i] << " "  << x << " " << y << "\n";
    if (a[i] < x || a[i] > y) continue;
    //cout << "Case : " << i << "\n";
    int l = i, r = n, pos = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if ( ask(rt[i - 1], rt[mid], 1, x - 1, 1, num) ) r = mid - 1;
      else pos = mid, l = mid + 1;
    }
    //只要存在下面的数就不行这个可以直接二分出右边界
    //cout << "The first is : " << pos << "\n";
    if (!pos) continue;
    int pos2 = pos;
    l = i, r = n; pos = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int now2 = ask(rt[i - 1], rt[mid], 1, num, 1, num);
      int now1 = ask(rt[i - 1], rt[mid], 1, y, 1, num);
      if (now2 - now1) r = mid - 1;
      else l = mid + 1, pos = mid;
    }
    //只要存在上面的数就也不行，这个可以二分出右边界
    //cout << "The second is : " << pos << "\n";
    if (!pos) continue;
    int now = min(pos2, pos); //右边界
    //现在找左边界
    //找到第一个具有 x 的值的数，这个就是左边界
    l = i, r = n; pos = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int now1 = ask(rt[i - 1], rt[mid], 1, x, 1, num);
      int now2 = ask(rt[i - 1], rt[i], 1, x - 1, 1, num);
      if (now1 - now2 > 0) {
        pos = mid;
        r = mid - 1;
      }  else l = mid + 1;
    }
    //不存在就推出啊，x 都没有
    //cout << "The third is : " << pos << "\n";
    if (!pos) continue;
    l = i, r = n; pos2 = 0;
    //找到第一个具有 y 的值的数，这个就是左边界
    while (l <= r) {
      int mid = (l + r) >> 1;
      int now1 = ask(rt[i - 1], rt[mid], 1, y, 1, num);
      int now2 = ask(rt[i - 1], rt[mid], 1, y - 1, 1, num);
      if (now1 - now2 > 0) {
        pos2 = mid;
        r = mid - 1;
      }  else l = mid + 1;
    }
    //cout << "The fourth is : " << pos2 << "\n";
    if (!pos2) continue;
    int now2 = max(pos, pos2);
    //cout << "The pt : "<< now << " " << now2 << "\n";
    if (now2 > now) continue;
    ans += now - now2 + 1;
  }
  write(ans), putchar('\n');
  return 0;
}
/*
枚举中间位置 x
查询出两边第一个位置比他大的，要容斥？
|..x...x..|
这样会算重，
还是考虑枚举 l，如果 al < x 跳过 al > y 跳过
al 在 [x,y] 之间
往后找到第一个 pos satisfied : apos < x 
solution 二分后面的位置，然后查询区间中 < x 的数拉个主席树
*/
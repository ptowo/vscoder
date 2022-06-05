// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 3e6, inf = 2e14;
int n, num, rt, q, pre[N], a[N], nex[N], first[N], v[N], w[N];
struct node { int op, l, r; } ask[N];
void add(int from,int to,int val) { nex[++num] = first[from]; first[from] = num; v[num] = to; w[num] = val; }
int f[N][22], dis[N][22], dep[N];
void dfs(int x,int fa) {
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i], val = w[i]; if (to == fa) continue;
    dep[to] = dep[x] + a[to];
    f[to][0] = x; dis[to][0] = val;
    dfs(to, x);
  }
}
int getfar(int x,int k) {
  for (int i = 20; i >= 0; i--) {
    if (dis[x][i] <= k) {
      k -= dis[x][i];
      x = f[x][i];
    }
  }
  return x;
}
int st[N], tp;
signed main () {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  if (n <= 3000) {
    for (int t = 1; t <= q; t++) {
      int op = read(), l = read(), r = read();
      if (op == 1) {
        for (int j = l; j < r; j++) a[j] = max(a[j], a[j + 1]);
      }  else {
        tp = 0; int ans = 0, mx = 0;
        for (int j = l; j <= r; j++) {
          if (a[j] > mx) ans += a[j];
          mx = max(mx, a[j]);
        }
        printf("%lld\n", ans);
      }
    }
    return 0;
  }
  int now = 0; 
  for (int i = 1; i <= q; i++) {
    ask[i].op = read(), ask[i].l = read(), ask[i].r = read();
    if (ask[i].op == 1) {
      if (ask[i].l != 1 || ask[i].r != n) now = 1;
    }
  }
  if (!now) {
    rt = n + 1;
    a[n + 1] = 0; st[0] = n + 1;
    for (int i = n; i; i--) {
      while (tp && a[ st[tp] ] <= a[i]) tp--;
      if (!tp) add(i, st[tp], inf), add(st[tp], i, inf);
      else add(i, st[tp], st[tp] - i + 1), add(st[tp], i, st[tp] - i + 1);
      ++tp, st[tp] = i;
    }
    dfs(rt, 0);
    f[rt][0] = rt;
    for (int j = 1; j <= 20; j++) 
      for (int i = 1; i <= n + 1; i++) {
        f[i][j] = f[ f[i][j - 1] ] [j - 1];
        dis[i][j] = dis[ f[i][j - 1] ][j - 1] + dis[i][j - 1];
      }
    int cnt = 0;
    for (int i = 1; i <= q; i++) {
      int po = ask[i].op;
      if (po == 1) { cnt++;}
      else {
        int x = ask[i].l, len = ask[i].r - ask[i].l + 1;
        int n1 = getfar(x, cnt);
        int n2 = getfar(x, len + cnt);
        printf("%lld\n", dep[n1] - dep[n2] + a[n2]);
      }
    }
  }
  return 0;
}
/*
维护 pre[i], spre[i] 表示 ai 前面第一个不小于他的数的位置和值
询问依次为所有 pre[i] < l 的 ai 之和
考虑一次修改发生了什么，一次修改等价于是将这段区间内的 pre[i] 进行重构
如果当前值的 pre[i] < l 那么没有影响
如果当前值的 pre[i] >= l 那么，
考虑一手 [1, n] 全局，等价于我们需要寻找的是那些无论如何前面都不会比他大的数
每次操作之后答案一定递减
原先已经是最大值的自然不会变，然后原先不是最大值的会继续往下变
就是你发现，只有其前面为一个单调递增状物时，答案会一直贡献
然后对于其他的地方，只有找到大于他前面最大值的一段递增序列，可以一直贡献，然后每次会往下面标记 + 1
然后每次暴力存下区间之后修改即可？
均摊一下，复杂度为线性的，每次只要到达左端点了，就弹出去，不管
相当于存下所有单调递增的序列，为一块
其实他的区间询问相当于询问区间单调栈元素个数和
假设进行了 k 次全局操作
咦，相当于一个 [l,r] 的询问直接拿 max{ai} i\in [l, l + k] 
开始跑 [l + k + 1, r + k]
然后这东西直接 RMQ， RMQ 然后离线倒着跑维护一个单调栈，二分一下起点和终点就好了

谔谔，那么，维护区间单调栈元素个数，同时询问为全局的

然后我们考虑将这个给做出来

不对，这东西，咋二分啊，让我们二分一下起点和终点，那就是我先二分出一个起点，再去二分一个终点，然后最后得到的这个区间
还是不会，被打爆了

答案，答案为啥，哦，直接从 l 点往上跳，只要不超过区间长度的点权和

每次删除，一定是删除一个叶子节点，我们维护每个叶子节点

实质上也没必要？

直接每次跳区间长度

*/

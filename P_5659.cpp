// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
#define clr(f, n) memset(f, 0, sizeof(int) * n)
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * n);
using namespace std;
namespace io {
  const int SIZE = (1 << 21) + 1;
  char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
  #define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
  inline void flush () {  fwrite (obuf, 1, oS - obuf, stdout); oS = obuf; }
  inline void putc (char x) { *oS ++ = x; if (oS == oT) flush (); }
  template <class I>
	inline void gi (I &x) {
    for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
  string getstr(void) {
    string s = "!"; char c = gc();
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF) c = gc();
    while (!(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF))s.push_back(c), c = gc();
    return s;
  }
  template <class I>
  inline void print (I x) {
    if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
    while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
    while (qr) putc (qu[qr --]);
  }
  struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
const int N = 2e5;
int T, n, id[N], a[N], b[N], num = 1, nex[N], first[N], v[N], F[N], anst[N], deg[N];
void add(int from,int to ){
  nex[++num] = first[from];  first[from] = num;  v[num] = to;
}
void dfs(int x,int fa) {
  F[x] = fa;
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i];
    if (to == fa)
      continue;
    dfs(to, x);
  }
}
pair <int,int> qwq[N];
int p[N];
namespace subtask2 {
  int fa[N], ans[N], vis[N];
  void init(int n) {
    for (int i = 1; i <= n; i++)
      fa[i] = i;
  }
  int getfa(int x) {
    if (fa[x] != x)
      fa[x] = getfa(fa[x]);
    return fa[x];
  }
  void merge(int x,int y) {
    x = getfa(x), y = getfa(y);
    if (x ^ y)
      fa[x] = y;
  }
  void solve() {
    init(n);
    for (int i = 1; i <= n; i++)
      vis[i] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (!vis[j] && (i == n || getfa(j) != getfa(a[i]))) {
          vis[j] = 1; ans[i] = j; merge(j, a[i]); break; 
        }
      }
    }
    for (int i = 1; i <= n; i++)
      print(ans[i]), putc(' '); 
    putc('\n');
  }
}
namespace subtask3 {
  int dfn[N], nfd[N], pt, vis[N], tag[N], ans[N];
  void dfs(int u,int f) {
    dfn[u] = ++pt; nfd[pt] = u;
    for (int i = first[u]; i; i = nex[i]) {
      int to = v[i]; 
      if (to == f)
        continue;
      dfs(to, u);
    }
  }
  //tag = 1 表示向左走，tag = 2 表示向右走
  int check_l(int p1,int p2) {
    if (tag[p1] == 1 || tag[p2] == 1)
      return false;
    for (int i = p1 + 1; i < p2; i++) 
      if (tag[i] == 2)
        return false;
    return true;
  }
  int check_r(int p1,int p2) {
    if (tag[p1 ] == 2 || tag[p2] == 2)
      return false;
    for (int i = p2 + 1; i < p1; i++) 
      if (tag[i] == 1)
        return false;
    return true;
  }
  void push_l(int p1,int p2) {
    if (p1 != 1 && p1 != n) 
      tag[p1] = 2;
    if (p2 != 1 && p2 != n)
      tag[p2] = 2;
    for (int i = p1 + 1; i < p2; i++)
      tag[i] = 1;
  }
  void push_r(int p1,int p2) {
    if (p1 != 1 && p1 != n)
      tag[p1] = 1;
    if (p2 != 1 && p2 != n)
      tag[p2] = 1;
    for (int i = p2 + 1; i < p1; i++)
      tag[i] = 2;
  }
  int find_l(int u) {
    int res = n + 1;
    if (tag[ dfn[u] ] == 2) 
      return res;
    for (int j = dfn[u] - 1; j >= 1; j--) {
      if (tag[j] == 1) {
        if (!vis[j])
          res = min(res, nfd[j]);
        break;
      }
      if (!tag[j] && !vis[j])
        res = min(res, nfd[j]);
    }
    return res;
  }
  int find_r(int u) {
    int res = n + 1;
    if (tag[dfn[u]] == 1) 
      return res;
    for (int j = dfn[u] + 1; j <= n; j++) {
      if (tag[j] == 2) {
        if (!vis[j]) 
          res = min(res, nfd[j]);
        break;
      }
      if (!tag[j] && !vis[j])
        res = min(res, nfd[j]);
    }
    return res;
  }
  void solve() {
    for (int i = 1; i <= n; i++)
      tag[i] = vis[i] = ans[i] = 0; pt = 0;
    for (int i = 1; i <= n; i++) 
      if (deg[i] == 1) {  dfs(i, 0); break; }
    for (int i = 1; i <= n; i++) {
      int rt = find_l(p[i]), tp = find_r(p[i]);
      if (rt < tp) 
        push_r(dfn[p[i]], dfn[rt]);
      else rt = tp, push_l(dfn[p[i]], dfn[rt]);
      ans[i] = rt; vis[ dfn[rt] ] = 1;
    }
    for (int i = 1; i <= n; i++)
      print(ans[i]), putc(' ');
    putc('\n');
  }
}
const int M = 3000;
namespace subtask4 {
  struct DSU {
    int fa[M], fir, lst, pre[M], nxt[M];
    void init(int n) {
      for (int i = 1; i <= n; i++)
        pre[i] = nxt[i] = 0, fa[i] = i;
      fir = lst = 0;
    }
    int getfa(int x) {
      if (fa[x] != x)
        fa[x] = getfa(fa[x]);
      return fa[x];
    }
    bool same(int x,int y) {
      return getfa(x) == getfa(y);
    }
    void merge(int x,int y) {
      x = getfa(x), y = getfa(y);
      fa[x] = y;
    }
  }t[M];
  int dfs(int u,int fa) {
    int res = n + 1;
    //deg[x] 表示剩下的 x 的没被删的边数
    //然后要么当前没有最后删除的边，要么最后删除的边已经是上一个
    if (fa && (!t[u].lst || t[u].lst == fa))
      if (!t[u].nxt[fa] && !(t[u].fir && deg[u] > 1 && t[u].same(fa, t[u].fir)))
        res = u;           //!(当前还有点没被删，但是此时首尾在一条链上)
      //最后删除的边没有后继
    for (int i = first[u]; i; i = nex[i]) {
      int to = v[i], id = (i >> 1); //当前边标号
      if (fa == id)
        continue;
      if (!fa) {
        if (!t[u].fir || t[u].fir == id) { 
          //起点判断，前一个转移过来的边是第一个被删除的边，或者还没有被删除的边
          if (t[u].pre[id]) //第一个删除的边有前驱就g
            continue;
          if (t[u].lst && deg[u] > 1 && t[u].same(t[u].lst, id)) 
          //有最后删边，并且还有没删的边，并且 last[u] 和起点边在一个集合
            continue;
          res = min(res, dfs(to, id)); //可以作为起点
        }  else  continue;
      }  else {
        if (t[u].fir == id || t[u].lst == fa || t[u].same(id, fa)) 
          continue;
        // 中间点判断
        if (t[u].pre[id] || t[u].nxt[fa])
          continue;
        // 当前的边有前驱了， 上一个点边后继了，那这条边不能更着他们删
        if (t[u].fir && t[u].lst && deg[u] > 2 && t[u].same(t[u].fir, fa) && t[u].same (t[u].lst, id))
          continue;
        //作为中间点判断
        res = min(res, dfs(to, id));
      }
    }
    return res;
  }
  bool push(int u,int f,int end) {
    if (u == end) {
      t[u].lst = f; return true;
    }
    for (int i = first[u]; i; i = nex[i]) {
      int to = v[i], id = (i >> 1);
      if (id == f)
        continue;
      if(push(to, id, end)) {
        if (!f)
          t[u].fir = id;
        else {
          t[u].nxt[f] = t[u].pre[id] = 1;
          deg[u]--; t[u].merge(f, id);
        } 
        return true;
      }
    }
    return false;
  }
  void solve() {
    for (int i = 1; i <= n; i++)
      t[i].init(n);
    for (int i = 1; i <= n; i++) {
      int res = dfs(p[i], 0);
      push(p[i], 0, res);
      print(res), putc(' ');
    }
    putc('\n');
  }
};

signed main () {
  // freopen("tree.in", "r", stdin);
  // freopen("tree.out", "w", stdout);
  gi(T);
  for (int cas = 1; cas <= T; cas++) {
    for (int i = 1; i <= num; i++)
        nex[i] = first[i] = F[i] = v[i] = 0;
    num = 1;
    gi(n);
    for (int i = 1; i <= n; i++)
      deg[i] = 0, anst[i] = 0;
    for (int i = 1, x; i <= n; i++) 
      gi(x), a[x] = i, p[i] = x;
    for (int i = 1, x, y; i < n; i++) 
      gi(x), gi(y), add(x, y), add(y, x), ++deg[x], ++deg[y];
    int fl = 0, rt = 0;
    for (int i = 1; i <= n; i++)
      fl = max(fl, deg[i]);
    if (fl == n - 1) { subtask2 :: solve();  continue; }
    else if (fl == 2) { subtask3 :: solve(); continue;}
    else { subtask4 :: solve(); continue;}
    if (n <= 10) {
      for (int i = 1; i < n; i++)
        id[i] = i + 1;
      for (int i = 1; i <= n; i++)
        anst[i] = n;
      dfs(1, 0);
      do {
        for (int i = 1; i <= n; i++) 
          b[i] = a[i];
        for (int i = 1; i < n; i++) 
          swap(b[ id[i] ], b[F[id[i]]]);
        for (int i = 1; i <= n; i++) 
          qwq[i] = make_pair(b[i], i); 
        sort(qwq + 1, qwq + n + 1);
        for (int i = 1; i <= n; i++) {
          int now = qwq[i].second;
          if (now == anst[i]) 
            continue;
          if (now > anst[i]) 
            break;
          if (now < anst[i]) {
            for (int j = 1; j <= n; j++) 
              anst[j] = qwq[j].second;
            break;
          }
        }
      } while(next_permutation(id + 1, id + n));
      for (int i = 1; i <= n; i++)
        print(anst[i]), putc(' ');
      putc('\n'); 
    } 
  }
  return 0;
}
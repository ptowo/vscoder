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
const int N = 2e6;
int num, nex[N], first[N], v[N];
void add(int from,int to) {
  nex[++num] = first[from];  first[from] = num; v[num] = to; 
}
int ls[N], rs[N], rt[N], tot, s[N], t[N];
void pushup(int p) {
  if(s[ls[p]] > s[rs[p]]) {
    s[p] = s[ls[p]]; t[p] = t[ls[p]];
  }  else {
    s[p] = s[rs[p]];  t[p] = t[rs[p]];
  }
}
void change(int &p,int l,int r,int pos,int val) {
  if(!p) p = ++tot;
  if(l == r) {
    s[pos] += val;
    t[p] = pos; 
    return;
  }
  int mid = (l + r) >> 1;
  if(pos <= mid) change(ls[p], l, mid, pos, val);
  else change(rs[p], mid + 1, r, pos, val);
  pushup(p);
}
int merge(int a,int b,int x,int y) {
  if(!a || !b) return a + b;
  int rt = ++tot;
  if(x == y) {
    s[rt] = s[a] + s[b];  t[rt] = x;
    return;
  }
  int mid = (l + r) >> 1;
  ls[rt] = merge(l[a], l[b], x, mid);
  rs[rt] = merge(r[a], r[b], mid + 1, y);
}
int dep[N], siz[N], fa[N], son[N], top[N];
void dfs(int x,int f) {
  fa[x] = f;  dep[x] = dep[fa] + 1;  siz[x] = 1;
  for(int i = first[x]; i; i = nex[i]) {
    int to = v[i];
    if(to == f) continue;
    dfs(to, x);
    siz[x] += siz[to];
    if(siz[to] > siz[son[x]]) son[x] = to;
  }
}
void dfs2(int now,int x) {
  top[now] = x;
  if(son[now]) dfs2(son[now], x);
  for(int i = first[now]; i; i = nex[i]) {
    int to = v[i];
    if(to == son[now] || to == fa[now]) continue;
    dfs2(to, to);
  }
}
signed main () {
  n = read(), m = read();
  FOR(i, 2, n) {
    int a = read(), b = read();
    add(a, b), add(b, a);
  }
  dfs(1, 0);  dfs2(1, 1);
  FOR(i, 1, m) {
    
  }
  return 0;
}
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
const int N = 2e6, inf = 2e8;
int n, m, vt[N], num, nex[N], first[N], v[N];
void add(int from,int to) {
	nex[++num] = first[from]; first[from] = num; v[num] = to; 
}//存储原图
int vis[N], siz[N], son[N], SUM, cent, ff[N], top[N], dep[N];
vector <int> G[N];//存储新图
void dfs1(int x,int fa) {
	siz[x] = 1; son[x] = 0; ff[x] = fa; dep[x] = dep[fa] + 1;
	for (int i = first[x]; i; i = nex[i]) {
		int to = v[i]; if (to == fa) continue; dfs1(to, x); siz[x] += siz[to]; 
		if (siz[to] > son[x]) son[x] = to;
	}
}
void dfs2(int now,int x) {
	top[now] = x; if (son[now]) dfs2(son[now], x);
	for (int i = first[now]; i; i = nex[i]) 
		{int to = v[i]; if (to == son[now] || to == ff[now]) continue; dfs2(to, to); }
}
int lca(int x,int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] >= dep[top[y]]) x = ff[top[x]];
		else y = ff[top[y]];
	}
	return dep[x] < dep[y] ? x : y;
}
void getroot(int u,int fa) {
	siz[u] = 1; son[u] = 0;
	for (int i = first[u]; i; i = nex[i]) {
		int to = v[i]; if (to == fa || vis[to]) continue;
		getroot(to, u); siz[u] += siz[to]; son[u] = max(son[u], siz[to]);
	}
	son[u] = max(son[u], SUM - son[u]);
	if (son[u] < son[cent]) cent = u;
}
int fa2[N];
void solve(int u) {
	vis[u] = 1;
	for (int i = first[u]; i; i = nex[i]) {
		int to = v[i];  if (vis[to]) continue;
		SUM = siz[to]; cent = 0; son[0] = inf; getroot(to, u); 
		G[u].push_back(cent); fa2[cent] = u;
		//cout << u << " " << cent << "\n";
		solve(cent);
	}
}
int sz[N];
void dfs3(int x) {
  sz[x] = 1;
  for (int i = 0; i < G[x].size(); i++) {
    int to = G[x][i]; dfs3(to); sz[x] += sz[to];
  }
}
class BIT {
	public: 
	int n;
	vector <int> c;
	void resize(int len) { 
		c.resize(len + 1);
		n = len + 1;
	}
	int lowbit(int x) { return x & (-x); }
	void change(int x,int val) {
    x++;
		for (int i = x; i <= n; i += lowbit(i) ) 
			c[i] += val;
	}
	int ask(int x) {
    x++;
		int ans = 0;
		for (int i = x; i; i -= lowbit(i)) 
			ans += c[i];
		return ans;
	}
} t1[N], t2[N];
int getdis(int x,int y) {
	return dep[x] + dep[y] - dep[lca(x, y)] * 2;
}
void update(int x,int val) {
	for (int i = x; i; i = fa2[i]) t1[i].change(getdis(x, i), val);
	for (int i = x; fa2[i]; i = fa2[i]) t2[i].change(getdis(x, fa2[x]), val);
}
int ask(int x,int k) {
	int ans = t1[x].ask(k);
	for (int i = x; fa2[i]; i = fa2[i]) {
		int d = getdis(x, fa2[i]);
		if (k >= d) ans += t1[fa2[i]].ask(k - d) - t2[i].ask(k - d);
	}
	return ans;
}
signed main () {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) vt[i] = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		add(u, v), add(v, u);
	}
	dfs1(1, 0), dfs2(1, 0);
	for (int i = 1; i <= n; i++) son[i] = siz[i] = 0;
	son[0] = SUM = n; getroot(1, 0); int qwq = cent;
	solve(cent); int las = 0; dfs3(qwq);
	for (int i = 1; i <= n; i++) t1[i].resize( sz[i] + 1), t2[i].resize( sz[i] + 1);
  for (int i = 1; i <= n; i++) update(i, vt[i]);
	for (int i = 1; i <= m; i++) {
		int op = read(), x = read(), y = read();
		x ^= las, y ^= las;
		if (op == 1) {
			update(x, y - vt[x]), vt[x] = y;
		}  else {
			las = ask(x, y);
			printf("%lld\n", las);
		}
	}
	return 0;
}

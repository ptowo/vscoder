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
const int N = 6e6, M = (1ll << 23) * 2 + 4;
int n, c, k, d = 60, tong[M];
vector <int> ver[N], A, B, tb;
void dfs(int dep,int lim,int k,vector <int> & res) {
  if (dep > lim) { res.emplace_back(k); return; }
  for (int i = 0; i < ver[dep].size(); i++) {
    dfs(dep + 1, lim, (k ^ ver[dep][i]), res);
  }
}
int calc(int now,int k) {
  int ans = 0;
  if (d - k <= 23) {
    int siz = (1ll << (d - k)) * 2;
    for (int i = 0; i <= siz; i++) tong[i] = 0;
    for (auto x : A) tong[x >> k] ++;
    for (auto x : B) ans += tong[(x ^ now) >> k];
  }  else { 
    tb.resize(B.size());
    for (int i = 0; i < B.size(); i++) tb[i] = (B[i] ^ now) >> k;
    sort(tb.begin(), tb.end());
    for (int i = 0, j1 = 0, j2 = 0; i < A.size(); i++) {
      int cur = (A[i] >> k);
      while (j1 < tb.size() && tb[j1] < cur) ++j1;
      while (j2 < tb.size() && tb[j2] <= cur) ++j2;
      ans += (j2 - j1);
    }
  }
  return ans;
}
int cmp(vector<int> A, vector <int> B) { return A.size() < B.size(); }
signed main () {
  n = read(), c = read(), k = read();
  for (int i = 1; i <= n; i++) { 
    int d = read(), v = read(); 
    ver[d].emplace_back(v);
  }
  sort(ver + 1, ver + c + 1, cmp);
  int now = 0, ways = 1, lim = 2e5;
  while (now < c && ways <= lim) { ++now; ways *= ver[now].size(); }
  dfs(1, now, 0, A), dfs(now + 1, c, 0, B);
  sort(A.begin(), A.end()), sort(B.begin(), B.end());
  //for (auto x : A) cout << x << " "; cout << "\n";
  int qwq = 0;
  for (int i = d - 1; i >= 0; i--) {
    int cur = calc(qwq ^ (1ll << i), i);
    //cout << cur << " " << i << "\n";
    if (cur >= k) qwq ^= (1ll << i);
    else k -= cur;
  }
  printf("%lld\n", qwq);
  return 0;
}
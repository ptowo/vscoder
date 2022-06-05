// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 2e6;
int T, n, p[N], ans[N][2];
vector <int> tp, q;
void ins(int id,int k) {
  int x = k ? p[id] : -p[id];
  int i = upper_bound(q.begin(), q.end(), x) - q.begin(); if (!i) return;
  int j = q.size() - i;
  tp.emplace_back(min(q[j], x)); tp.emplace_back(max(q[j], x));
  if (abs(q[q.size() - 1 - j]) == p[id - 1]) ans[id][k] = q[q.size() - 1- j] > 0;
  if (abs(q[j]) == p[id - 1]) ans[id][k] = q[j] > 0;
  return;
}
bool check() {
  q.clear(); if (tp.empty()) return false;
  if (tp[0] <= tp[2] && tp[1] <= tp[3]) { tp.pop_back(); tp.pop_back(); }
  sort(tp.begin(), tp.end()); q = tp; return true;
}
void solve() {
  n = read();
  for (int i = 1; i <= n; i++) p[i] = read(); q.clear(); tp.clear();
  for (int i = 1; i <= n; i++) {
    tp.clear();
    if (q.empty()) { q.push_back(- n - 1); q.push_back(-p[i]); continue; }
    ins(i, 0); ins(i, 1);
    if (!check()) { printf("NO\n"); return;}
  }
  printf("YES\n");
  for (auto v : q) {
    if (abs(v) == p[n]) {
      p[n] = v; int t = v > 0, i = n;
      while (i > 1) {t = ans[i][t]; i--; if (!t) p[i] = -p[i];}
      for (int j = 1; j <= n; j++) printf("%d ", p[j]); printf("\n");
    }
  }
}
signed main() {
  T = read(); while (T--) solve();
  return 0;
}
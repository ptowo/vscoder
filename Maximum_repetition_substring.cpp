// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include  <map>
#include  <set>
#include  <cmath>
#include  <queue>
#include  <cstdio>
#include  <vector>
#include  <climits>
#include  <cstring>
#include  <cstdlib>
#include  <iostream>
#include  <algorithm>
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
const int N = 2e5 + 6;
int n;
char ch[N], ch1[N], ch2[N];
int lg[N];
class Sa{
  //
  //
  public: int num, f1[N], f2[N], sa[N], tong[N], height[N], rk[N];
  public: int f[N][20];
  public: void SA() {
    num = 260;
    FOR (i, 1, num) tong[i] = 0;  FOR(i, 1, n) ++tong[ f1[i] = ch[i] ];
    FOR (i, 1, num) tong[i] += tong[i - 1];  DFR(i, n, 1)  sa[ tong[f1[i]]-- ] = i;
    for (int l = 1; l <= n; l <<= 1) {  int cnt = 0;
      FOR (i, n - l + 1, n) f2[++cnt] = i;  FOR(i, 1, n) if(sa[i] > l) f2[++cnt] = sa[i] - l;
      FOR (i, 1, num) tong[i] = 0;  FOR(i, 1, n) ++tong[f1[i]];  FOR(i, 1, num) tong[i] += tong[i - 1];
      DFR (i, n, 1) sa[ tong[ f1[ f2[i] ] ] -- ] = f2[i], f2[i] = 0;  
      FOR(i, 1, n) swap(f1[i], f2[i]);
      f1[ sa[1] ] = 1;  cnt = 1;
      FOR (i, 2, n) f1[ sa[i] ] = ( f2[ sa[i] ] == f2[ sa[i - 1] ] && f2[ sa[i] + l ]  == f2[ sa[i - 1] + l] ) ? cnt : ++cnt;
      if(cnt == n) break;  num = cnt;
    }
    FOR(i, 1, n) rk[i] = f1[i];
  }
  public: void Getheight() {
    int k = 0;  FOR(i, 1, n) {
      if(k) k--;  int j = sa[f1[i] - 1];
      while (ch[i + k] == ch[j + k]) k++;  height[ f1[i] ] = k;
    }
  }
  public: void buildst() {
    FOR (i, 1, n) f[i][0] = height[i];
    //cout << "\n";
    for (int j = 1; (1 << j) <= n; j++) {
      for (int i = 1; i + (1 << j) - 1 <= n; i++) {
        f[i][j] = wmin(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        //cout << f[i][j] <<" " ;
      }
      //cout << "\n";
    }
  }
  public: int query(int l,int r) {  
    l = rk[l], r = rk[r];  
    if (l > r) swap(l, r);
    int k = lg[r - (++l) + 1];  
    return wmin(f[l][k], f[r - (1 << k) + 1][k]);
  }  
  public: void clear() {
    memset(rk, 0, sizeof(rk));
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    memset(sa, 0, sizeof(sa));
    memset(f, 0, sizeof(f));
  }
}A, B;
int f[N][20];
void buildst(int *a,int n) {
  FOR (i, 1, n) f[i][0] = a[i];
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      f[i][j] = wmin(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int query(int l,int r) {  int k = lg[r - l + 1];  
  return wmin(f[l][k], f[r - (1 << k) + 1][k]);
}
signed main () {
  REP (i, 2, N) lg[i] = lg[i >> 1] + 1;  int tim = 0;
  for ( ; ; ) {
    scanf("%s", ch + 1);  n = strlen(ch + 1);
    FOR(i, n + 1, 2 * n) ch[i] = ' ';
    if (n == 1 && ch[1] == '#') return 0;
    A.clear(), B.clear(); 
    //FOR(i, 1, n) cout << ch[i]; cout << "\n";
    A.SA();  A.Getheight();  A.buildst();
    reverse(ch + 1, ch + n + 1); 
    B.SA();  B.Getheight();  B.buildst();
    reverse(ch + 1, ch + n + 1);
    buildst(A.rk, n);
    int mx = 0, RK = n + 1, ansl = 0, ansr = 0;
    FOR (l, 1, n) {
      for (int i = 1, j = l + 1; j <= n; i += l, j += l ) {
        int R = A.query(i, j), L = B.query(n - i + 2, n - j + 2);
        //cout << R << " " << L<< "\n";
        int k = L + R, cnt = k / l + 1;
        if (cnt > mx) mx = cnt, RK = n + 1;
        if (cnt == mx) {
          int mn = query(i - L, i - L + k % l);
          if (mn < RK) RK = mn, ansl = A.sa[mn], ansr = ansl + mx * l - 1;
        }
      }
  
    }
    //printf("QWQWQWQWQWQWQWQ\n");
    printf("Case %d: ", ++tim);
    FOR (i, ansl, ansr) printf("%c", ch[i]);  printf("\n");
  }
  return 0;
}
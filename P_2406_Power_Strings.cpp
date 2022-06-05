// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢，这是因为德丽莎很可爱！
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <string>
#include <iostream>
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
int fail[N], sl[N];
char s[N], t[N];
void build(char *s,int len,int *fail) {
  int p = 0;
  for(int i = 2; i <= len; i++) {
    while(p && s[p + 1] != s[i]) p = fail[p];
    if(s[p + 1] == s[i]) p++;
    fail[i] = p;
  }
}
void kmp(char *s,char *t,int len,int *fail,int *sl) {
  int p = 0;
  for(int i = 1; i <= len; i++) {
    while(p && s[p + 1] != t[i]) p = fail[p];
    if(s[p + 1] == t[i]) p++;
    sl[i] = p;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for( ; ; ) {
    cin >> (s + 1);
    int n = strlen(s + 1);
    if(n == 1 && s[1] == '.') break;
    build(s, n, fail);
    int ans = n % (n - fail[n]) ? 1 : n / (n - fail[n]);
    cout << ans << "\n";
  }
  return 0;
}
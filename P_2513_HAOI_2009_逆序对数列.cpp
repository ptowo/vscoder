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
const int M = 3;
int mod;
struct Martix
{
  int a[M][M];
  Martix() { memset(a, 0, sizeof(a)); }
  Martix operator*(const Martix &b)
  {
    Martix res;
    for (int i = 1; i <= 2; i++)
    {
      for (int j = 1; j <= 2; j++)
      {
        for (int k = 1; k <= 2; k++)
        {
          res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
          //				res.a[i][j]= (res.a[i][j]+a[i][k]*b.a[k][j]);
        }
      }
    }
    return res;
  }
};
int f[2000][2000];
int n, t;
int g[2][1];
Martix power(int k, Martix &ans)
{
  Martix b;
  b.a[1][1] = n;
  b.a[1][2] = 0;
  b.a[2][1] = 1;
  b.a[2][2] = 2 * n;

  while (k)
  {
    if (k & 1)
    {
      ans = (ans * b);
    }
    b = (b * b);
    k >>= 1;
  }
  return ans;
}
Martix ans;
int sum;
int r[2000], c[2000];
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> t >> mod;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> f[i][j];
      sum += f[i][j];
      sum %= mod;
    }
  }
  for (int i = 1; i <= n; i++)
  { //考虑每行
    int gi0 = 0;
    for (int j = 1; j <= n; j++)
    {
      gi0 = gi0 + f[i][j];
      gi0 %= mod;
    }
    ans.a[1][1] = gi0;
    ans.a[1][2] = sum;
    ans = power(t - 1, ans);
    r[i] = ans.a[1][1];
  }

  for (int j = 1; j <= n; j++)
  {
    int gi0 = 0;
    for (int i = 1; i <= n; i++)
    {
      gi0 = gi0 + f[i][j];
      gi0 %= mod;
    }
    ans.a[1][1] = gi0;
    ans.a[1][2] = sum;
    ans = power(t - 1, ans);
    c[j] = ans.a[1][1];
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << (r[i] + c[j]) % mod << " ";
    }
    cout << "\n";
  }
  return 0;
}

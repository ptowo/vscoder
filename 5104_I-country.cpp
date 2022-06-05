#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 16
#define maxm 226
using namespace std;
 
int dp[maxn][maxm][maxn][maxn][2][2];
int n,m,sum,val[maxn][maxn];
int ans;
 
inline int read(){
    register int x(0),f(1); register char c(getchar());
    while(c<'0'||'9'<c){ if(c=='-') f=-1; c=getchar(); }
    while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
 
int main(){
    n=read(),m=read(),sum=read();
    for(register int i=1;i<=n;i++){
        for(register int j=1;j<=m;j++) val[i][j]=val[i][j-1]+read();
    }
 
    for(register int i=1;i<=n;i++){
        for(register int j=1;j<=sum;j++){
            for(register int l=1;l<=m;l++){
                for(register int r=l;r<=m;r++){
                    if(j<r-l+1) break;
                    for(register int p=l;p<=r;p++){
                        for(register int q=p;q<=r;q++){
                            dp[i][j][l][r][1][0]=max(dp[i][j][l][r][1][0],dp[i-1][j-(r-l+1)][p][q][1][0]+val[i][r]-val[i][l-1]);
                        }
                    }
                    for(register int p=l;p<=r;p++){
                        for(register int q=r;q<=m;q++){
                            dp[i][j][l][r][1][1]=max(dp[i][j][l][r][1][1],max(dp[i-1][j-(r-l+1)][p][q][1][0],dp[i-1][j-(r-l+1)][p][q][1][1])+val[i][r]-val[i][l-1]);
                        }
                    }
                    for(register int p=1;p<=l;p++){
                        for(register int q=l;q<=r;q++){
                            dp[i][j][l][r][0][0]=max(dp[i][j][l][r][0][0],max(dp[i-1][j-(r-l+1)][p][q][0][0],dp[i-1][j-(r-l+1)][p][q][1][0])+val[i][r]-val[i][l-1]);
                        }
                    }
                    for(register int p=1;p<=l;p++){
                        for(register int q=r;q<=m;q++){
                            dp[i][j][l][r][0][1]=max(dp[i][j][l][r][0][1],max(dp[i-1][j-(r-l+1)][p][q][0][1],max(dp[i-1][j-(r-l+1)][p][q][1][0],max(dp[i-1][j-(r-l+1)][p][q][1][1],dp[i-1][j-(r-l+1)][p][q][0][0])))+val[i][r]-val[i][l-1]);
                        }
                    }
                    if(j==sum) ans=max(ans,max(dp[i][j][l][r][0][0],max(dp[i][j][l][r][1][0],max(dp[i][j][l][r][0][1],dp[i][j][l][r][1][1]))));
                    for (int x = 0; x <= 1; x++)
            for (int y = 0; y <= 1; y++)
              cout << i << " " << j << " " << l << " " << r << " " << x << " " << y << " qwq : " << dp[i][j][l][r][x][y] << "\n";
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

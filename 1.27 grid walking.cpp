#include<stdio.h>
typedef long long int LL;
int mod=(int)(1e9+7);
int ways[302][102],fact[501],mi[501];
LL dp[12][302],tmp;
int x[12],d[12],i,j,k,t,n,m;
int res;
int raise(int pow,int power){
    res=1;
    while(power){
        if(power&1) res=((LL)res*pow)%mod;
        pow=((LL)pow*pow)%mod;
        power>>=1;
    }
    return res;
}
int modularInverse(int num){
    return raise(fact[num],mod-2);
}
int main(){
    fact[0]=1;
    for(i=1;i<=300;i+=1) fact[i]=((LL)fact[i-1]*i)%mod;
    mi[0]=1;
    for(i=1;i<=300;i+=1) mi[i]=modularInverse(i);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i+=1) scanf("%d",&x[i]);
        for(i=1;i<=n;i+=1) scanf("%d",&d[i]);
        dp[0][0]=1;
        for(k=1;k<=n;k+=1){
            for(j=1;j<=d[k];j+=1) ways[0][j]=1;
            for(i=1;i<=m;i+=1){
                for(j=1;j<=d[k];j+=1){
                    ways[i][j]=0;
                    if(j>1)
                    ways[i][j]+=ways[i-1][j-1];
                    if(ways[i][j]>=mod) ways[i][j]-=mod;
                    if(j<d[k])
                    ways[i][j]+=ways[i-1][j+1];
                    if(ways[i][j]>=mod) ways[i][j]-=mod;
                }
            }
            for(i=0;i<=m;i+=1){
                dp[k][i]=0;
                for(j=0;j<=i;j+=1){
                    tmp=(dp[k-1][i-j]*ways[j][x[k]])%mod;
                    dp[k][i]=(dp[k][i]+(tmp*mi[j])%mod);
                    if(dp[k][i]>=mod) dp[k][i]%=mod;
                }
            }
        }
        printf("%lld\n",(dp[n][m]*fact[m])%mod);
    }
    return 0;
}
#include<stdio.h>

int i,j,k,n,mod;
long long ans1,ans2;
long long f[2600][2600],g[2600][2600];

main()
{
	mod=1000000007;
	scanf("%d%d",&n,&k);
	f[1][0]=1;
	for (i=2; i<=n; i++)
	{
		f[i][0]=1;
		for (j=1; j<=k && j<=i*(i-1)/2; j++)
		{
			f[i][j]=f[i][j-1];
			if (j<=(i-1)*(i-2)/2) f[i][j]=(f[i][j]+f[i-1][j])%mod;
			if (j>=i) f[i][j]=(f[i][j]-f[i-1][j-i]+mod)%mod;
		}
	}
	ans1=0;
	for (i=0; i<=k; i++)
		if ((k-i)%2==0) ans1=(ans1+f[n][i])%mod;
	g[1][1]=1;
	for (i=2; i<=n; i++)
	{
		g[i][1]=g[i-1][1]*(i-1)%mod;
		for (j=2; j<i; j++)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(i-1)%mod)%mod;
		g[i][i]=1;
	}
	ans2=0;

	for (i=n; i>=n-k && i>=1; i--)
		ans2=(ans2+g[n][i])%mod;
	printf("%lld %lld\n",ans1,ans2);
}



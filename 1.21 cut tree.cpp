#include<iostream>
#include<string.h>
using namespace std;

#define MAXN 100
int first[MAXN], next1[MAXN], v[MAXN];
int edgeindex;
int n, k;
long long dp[MAXN][MAXN];
bool vis[MAXN];

void addedge(int a, int b)
{
	v[edgeindex] = b;
	next1[edgeindex] = first[a];
	first[a] = edgeindex++;
}

void solve(int cur, int root)
{
	if(vis[cur])
	    return;
	    
	for(int i = first[cur]; i != -1; i = next1[i])
	{
		if(v[i] == root)
			continue;
		solve(v[i], cur);
		for(int j = k; j > 0; --j)
		{
			int tmp = 0;
			for(int x = j; x > 0; x--)
			{
				dp[cur][j] += dp[cur][j-x] * dp[v[i]][x];
			}
			dp[cur][j] += dp[cur][j-1];
		}
	}
	return;
}

int main()
{
	while(cin>>n>>k)
	{
		edgeindex = 0;
		memset(first, -1, sizeof(first));
		memset(dp, 0, sizeof(dp));
		memset(vis, false, sizeof(vis));
		int a, b;
		for(int i = 1; i < n; ++i)
		{
			cin>>a>>b;
			addedge(a, b);
			addedge(b, a);
		}
		
		for(int i = 1; i <= n; ++i)
		{
			dp[i][0] = 1;
		}
		
		solve(1, -1);
		
		long long ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 0; j < k; ++j)
			{
				ans += dp[i][j];
			}
		}
		ans += dp[1][k];
		cout<<ans+1<<endl;
	}
}


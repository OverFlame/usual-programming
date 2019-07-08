#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int a[110],dp[60][110],n,K,ans=inf;
int main()
{
	cin>>n>>K;
	K+=3;
	for(register int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(register int i=1;i<=K;++i)
		for(register int j=i*2;j<=n;++j)
		{
			dp[i][j]=inf;
			for(register int k=2*(i-1);k<=j-2;++k)
				dp[i][j]=min(dp[i][j],dp[i-1][k]+(a[j-1]-a[j])*(a[j-1]-a[j]));
		}
	for(register int i=2*K;i<=n;++i)
		ans=min(ans,dp[K][i]);
	printf("%d\n",ans);
	return 0;
}

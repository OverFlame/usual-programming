#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int a[3010],dp[3010],n,maxn=-inf;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<=a[i])
              dp[i]=max(dp[j]+1,dp[i]);
        }
    for(int i=0;i<n;i++)
        maxn=max(maxn,dp[i]);
    cout<<maxn<<endl;
    return 0;
}

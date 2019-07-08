#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int a[11010],dp[11010],n,maxn=-inf;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        dp[i]=a[i];
    }
    for(int i=1;i<n;i++)
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])
              dp[i]=max(dp[j]+a[i],dp[i]);
        }
    for(int i=0;i<n;i++)
        maxn=max(maxn,dp[i]);
    cout<<maxn<<endl;
    return 0;
}

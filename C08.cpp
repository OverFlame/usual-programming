#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int m[110][110];
int a[110][110];
int n;
int main()
{
	cin>>n;
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++)
		{
			cin>>m[i][j];
			a[i][j]=m[i][j];
		}
	for(register int i=0;i<=n;i++)
		a[i][0]=a[0][i]=inf;	
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++)
		{
			if(i==1&&j==1)
			  continue;
			else
			  a[i][j]=m[i][j]+min(a[i-1][j],a[i][j-1]);	
		}
	cout<<a[n][n];
	return 0;
}

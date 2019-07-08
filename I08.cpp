#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
struct Node{
	int x,y,h;
}a[10010];
int m[110][110],dp[110][110],r,c,maxn=-inf,id=0,xx,yy,x_,y_,head=1;
int cr[4]={1,0,-1,0},cc[4]={0,1,0,-1};
int cmp(Node a,Node b)
{
	return a.h<b.h;
}
int main()
{
	cin>>r>>c;
	for(register int i=1;i<=r;++i)
		for(register int j=1;j<=c;++j)
		{
			cin>>m[i][j];
			dp[i][j]=1;
			a[id].h=m[i][j];
			a[id].x=i;
			a[id++].y=j;
		}
	for(register int i=0;i<=r;++i)
		m[i][0]=inf;
	for(register int i=0;i<=c;++i)
		m[0][i]=inf;
	sort(a,a+id,cmp);
	while(head<=id)
	{
		for(register int i=0;i<4;++i)
		{
			x_=a[head].x;
			y_=a[head].y;
			xx=x_+cr[i];
			yy=y_+cc[i];
			if(m[xx][yy]<m[x_][y_])
			  dp[x_][y_]=max(dp[xx][yy]+1,dp[x_][y_]);	
		}
		++head;
	}
	for(register int i=1;i<=r;i++)
		for(register int j=1;j<=c;j++)
			maxn=max(maxn,dp[i][j]);
	cout<<maxn<<endl;
	return 0;
}

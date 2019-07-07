#include<cstdio>
#include<algorithm>
#define INF 0x7f7f7f7f
using namespace std;
struct Node{
	int id,c,root,time;
}a[200010];
int n,ans=INF;
inline void dfs(int i,int r,int t)
{
	a[i].root=r;
	a[i].time=t;
	if(!a[a[i].c].root)
	  dfs(a[i].c,r,t+1);
	else
		if(a[a[i].c].root==r)
		  ans=min(ans,a[i].time-a[a[i].c].time+1);
	return;
}
int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].c);
		a[i].id=i;
		a[i].root=0;
	}
	for(register int i=1;i<=n;i++)
		if(!a[i].root)
		  dfs(i,i,0);
	printf("&d\n",ans);
	return 0;
}

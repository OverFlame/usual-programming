#include<cstdio>
#include<algorithm>
#define INF 0x7f7f7f7f
using namespace std;
struct Node{
	int value,lchild,rchild;
}a[1000010];
int n,maxn=-INF,sum=1;
bool flag;
inline void dfs(int l,int r)
{
	if(!flag)
	  return;
	if(l==-1&&r==-1)
	  return;
	if((l==-1&&r!=-1)||(l!=-1&&r==-1))
	{
		flag=false;
		return;
	}
	if(a[l].value!=a[r].value)
	{
		flag=false;
		return;
	}
	sum+=2;
	dfs(a[l].lchild,a[r].rchild);
	dfs(a[l].rchild,a[r].lchild);
	return;
}
int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;++i)
		scanf("%d",&a[i].value);
	for(register int i=1;i<=n;++i)
		scanf("%d%d",&a[i].lchild,&a[i].rchild);
	for(register int i=1;i<=n;++i)
	{
		flag=true;
		sum=1;
		dfs(a[i].lchild,a[i].rchild);
		if(flag)
		  maxn=max(maxn,sum);
	}
	printf("%d",maxn);
	return 0;
}

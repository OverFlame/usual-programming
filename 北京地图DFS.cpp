#include<cstdio>
#include<iostream>
using namespace std;
char m[1010][1010];
int mv[1010][1010];
int cr[4]={1,0,-1,0},cc[4]={0,1,0,-1};
int r,c,t;
int dep=0;
inline void dfs(int x,int y)
{
	cout<<++dep<<endl;
	int xx,yy;
	if(m[x][y]=='+')
		for(register int i=0;i<4;++i)
		{
			xx=x+cr[i];
			yy=y+cc[i];
			if(xx<=0||xx>r||yy<=0||yy>c)
			  continue;
			if(m[xx][yy]=='*'||((mv[xx][yy]<mv[x][y]+1)&&mv[xx][yy]!=0))
			  continue;
			mv[xx][yy]=mv[x][y]+1;
			dfs(xx,yy);
		}
	if(m[x][y]=='|')
		for(register int i=0;i<4;++i)
		{
			if(i==1||i==3)
			  continue;
			xx=x+cr[i];
			yy=y+cc[i];
			if(xx<=0||xx>r||yy<=0||yy>c)
			  continue;
			if(m[xx][yy]=='*'||((mv[xx][yy]<mv[x][y]+1)&&mv[xx][yy]!=0))
			  continue;
			mv[xx][yy]=mv[x][y]+1;
			dfs(xx,yy);
		}
	if(m[x][y]=='-')
		for(register int i=0;i<4;++i)
		{
			if(i==0||i==2)
			  continue;
			xx=x+cr[i];
			yy=y+cc[i];
			if(xx<=0||xx>r||yy<=0||yy>c)
			  continue;
			if(m[xx][yy]=='*'||((mv[xx][yy]<mv[x][y]+1)&&mv[xx][yy]!=0))
			  continue;
			mv[xx][yy]=mv[x][y]+1;
			dfs(xx,yy);
		}
	dep--;
	return;
}
int main()
{
	freopen("data1.txt","r",stdin);
	freopen("d.txt","w",stdout);
	cin>>t;
	do
	{
		cin>>r>>c;
		for(register int i=1;i<=r;++i)
			for(register int j=1;j<=c;++j)
			{
				cin>>m[i][j];
				mv[i][j]=0;
			}
		mv[1][1]=2;
		dfs(1,1);
		cout<<mv[r][c]-1<<endl;
/*		for(register int i=1;i<=r;++i)
		{
			for(register int j=1;j<=c;++j)
				cout<<mv[i][j];
			cout<<endl;
		}
		cout<<endl;
		for(register int i=1;i<=r;++i)
		{
			for(register int j=1;j<=c;++j)
				cout<<m[i][j];
			cout<<endl;
		}	*/
	}while(--t);
	return 0;
}

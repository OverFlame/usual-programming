#include<cstdio>
#include<iostream>
using namespace std;
struct Node{
	int x,y,step;
}a[1000010];
char m[1010][1010],bis[1010][1010];
int cr[4]={1,0,-1,0},cc[4]={0,1,0,-1};
int r,c,t;
int head=0,tail=1;
bool flag=true;
inline void bfs()
{
	int xx,yy;
	while(head<=tail)
	{
		if(a[head].x==r&&a[head].y==c)
		{
			cout<<a[head].step-1<<endl;
			flag=false;
			return;
		}
		if(m[a[head].x][a[head].y]=='+')
			for(register int i=0;i<4;++i)
			{
				xx=a[head].x+cr[i];
				yy=a[head].y+cc[i];
				if(xx<=0||xx>r||yy<=0||yy>c)
				  continue;
				if(bis[xx][yy]=='*'||m[xx][yy]=='*')
				  continue;
				bis[xx][yy]='*';
				a[tail].step=a[head].step+1;
				a[tail].x=xx;
				a[tail].y=yy;
				tail++;
			}
		if(m[a[head].x][a[head].y]=='|')
			for(register int i=0;i<4;++i)
			{
				if(i==1||i==3)
				  continue;
				xx=a[head].x+cr[i];
				yy=a[head].y+cc[i];
				if(xx<=0||xx>r||yy<=0||yy>c)
				  continue;
				if(bis[xx][yy]=='*'||m[xx][yy]=='*')
				  continue;
				bis[xx][yy]='*';
				a[tail].step=a[head].step+1;
				a[tail].x=xx;
				a[tail].y=yy;
				tail++;;
			}
		if(m[a[head].x][a[head].y]=='-')
			for(register int i=0;i<4;++i)
			{
				if(i==0||i==2)
				  continue;
				xx=a[head].x+cr[i];
				yy=a[head].y+cc[i];
				if(xx<=0||xx>r||yy<=0||yy>c)
				  continue;
				if(bis[xx][yy]=='*'||m[xx][yy]=='*')
				  continue;
				bis[xx][yy]='*';
				a[tail].step=a[head].step+1;
				a[tail].x=xx;
				a[tail].y=yy;
				tail++;
			}
			head++;
	}
	return;
}
int main()
{	freopen("data1.txt","r",stdin);
	cin>>t;
	while(t--)
	{
		flag=true;
		head=0;tail=1;
		cin>>r>>c;
		for(register int i=1;i<=r;++i)
			for(register int j=1;j<=c;++j)
			{
				cin>>m[i][j];
				bis[i][j]=' ';
			}
		a[0].x=a[0].y=1;
		a[0].step=2;
		bfs();
		if(flag)
		  cout<<-1<<endl;
	}
	return 0;
}

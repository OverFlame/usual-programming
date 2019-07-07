#include<bits/stdc++.h>
using namespace std;
queue<string> q;
struct Node{
	string data;
	int l,r;
}t[1000000];
string str;
int n;
inline void dfs(int i)
{
	if(t[i].l!=-1)
	  dfs(t[i].l);
	if(t[i].r!=-1)
	  dfs(t[i].r);
	bool flag=false;
	int le=t[i].data.length();
	char co=t[i].data[le-1],c;
	while(--le)
	{
		c=t[i].data[le-1];
		if(c!=co)
		{
			printf("F");
			flag=true;
			break;
		}
		co=c;
	}
	if(flag)
	  return;
	if(co=='0')
	  printf("B");
	else
	  printf("I");
	return;
}
int main()
{
	cin>>n>>str;
	q.push(str);
	int idx=0;
	while(q.size())
	{
		string x=q.front();
		q.pop();
		t[++idx].data=x;
		int len=x.size();
		if(len==1)
		  t[idx].l=t[idx].r=-1;
		else
		{
			t[idx].l=idx*2;
			t[idx].r=idx*2+1;
			q.push(x.substr(0,len/2));
			q.push(x.substr(len/2,len/2));
		}
	}
	dfs(1);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int cow_[100010];
int N,r,l=0,C,mid,x,tot;
int main()
{
	cin>>N>>C;
	for(register int i=0;i<N;i++)
		cin>>cow_[i];
	sort(cow_,cow_+N);
	r=cow_[N-1];
	while(l<r)
	{
		mid=(l+r)/2+1;
		tot=1;
		x=0;
		for(register int i=1;i<N;i++)
		{
			if(cow_[i]-x<mid)
			  continue;
			else
			{
				tot++;
				x=cow_[i];
			}
		}
		if(tot>=C)
		  l=mid+1;
		else
		  r=mid-1;
	}
	cout<<mid;
	return 0;
}

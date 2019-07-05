#include<bits/stdc++.h>
using namespace std;
int n,a[20010],sum=0,tot;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	tot=sum;
	sort(a,a+n);
	for(int i=n-1;i>1;i--)
	{
		sum+=tot-a[i];
		tot-=a[i];
	}
	cout<<sum;
	return 0;
}

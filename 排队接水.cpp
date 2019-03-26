#include<bits/stdc++.h>
using namespace std;
struct Node{
	int id, time;
	int wait = 0;
};
Node people[1010];
double sum_wait = 0, a_wait;
int n;
void waiter()
{
	for(register int i = 2;i <= n;i ++)
	{
		people[i].wait = people[i-1].wait + people[i-1].time;
		sum_wait += people[i].wait;
	}
	a_wait=sum_wait/double(n);
	return;
}
int comp(Node a,Node b)
{
	return a.time < b.time;
}
int main()
{
	cin >> n;
	for(register int i = 1;i <= n;i ++)
	{
		people[i].id = i;
		cin >> people[i].time;
	}
	sort(people+1,people+n+1,comp);
	waiter();
	for(register int i = 1;i <= n;i ++)
	{
		cout << people[i].id << " ";
	}
	cout << endl;
	printf("%.2f",a_wait);
	return 0;
}

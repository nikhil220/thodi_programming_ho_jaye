#include <stdio.h>
#include <math.h>
#include<iostream> 
#include<vector>
#include<cstring>
#include<deque>

using namespace std;
#define LL long long int
#define SC(n) scanf("%d",&n)
#define SCL(n) scanf("%ld",&n)
int mx[1000000]={0},mn[1000000]={0};
void find_max(int n,int k,int a[])
{
	deque<int> q(3);
	q.push_back(0);
	int i;
	for( i=1;i<k;i++)
	{
		while(!q.empty() && a[i]>a[q.back()])
		q.pop_back();
		q.push_back(i);
		
	}
	int j=0;
	for(;i<n;i++,j++)
	{
		mx[j]=a[q.front()];
		while(!q.empty() && q.front()<=i-k)
		q.pop_back();
		while(!q.empty() && a[i]>a[q.back()])
		q.pop_back();
		q.push_back(i);	
	}
	mx[j]=a[q.front()];
}
void find_min(int n,int k,int a[])
{
	deque<int> q(3);
	q.push_back(0);
	int i;
	for( i=1;i<k;i++)
	{
		while(!q.empty() && a[i]<a[q.back()])
		q.pop_back();
		q.push_back(i);
		
	}
	int j=0;
	for(;i<n;i++,j++)
	{
		mn[j]=a[q.front()];
		while(!q.empty() && q.front()<=i-k)
		q.pop_back();
		while(!q.empty() && a[i]<a[q.back()])
		q.pop_back();
		q.push_back(i);	
	}
	mn[j]=a[q.front()];
}
int main()
{
	int k,i,n,flag,max;
	SC(n);
	SC(k);
	int a[n+5];
	for(int i=0;i<n;i++)
	SC(a[i]);
	find_max(n,k,a);
	find_min(n,k,a);
	int c=0;
	
	for(int i=0;i<=(n-k);i++)
	{
		cout<<mx[i]<<" "<<mn[i]<<endl;
		if(mx[i]-mn[i]+1 == k) c++;
	}
	cout<<c<<endl;
	system("pause");
	return 0;
}

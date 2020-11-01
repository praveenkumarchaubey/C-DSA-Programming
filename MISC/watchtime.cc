#include<iostream>
using namespace std;
int lcm(int *a,int n);
int main()
{
	int n,x,y;
	cout<<"enter number of watches";
	cin>>n;
	int *a=new int[n];
	cout<<"enter the delays";
	for(x=0;x<n;x++)
	{
		cout<<"delay"<<x+1;
		cin>>a[x];
	}
	for(x=0;x<n;x++)
	{
		for(y=1;y<=a[x];y++)
		{
			if(60*y%a[x]!=0)
				break;
		}
		a[x]=(60*y)/a[x];
	}
	cout<<lcm(a,n);
}
int lcm(int *a,int n)
{
	int p,q,b;
	for(int x=0;x<n-1;x++)
	{
		if(x==0)
		{
			p=a[x];
			q=a[x+1];
		}
		if(p>q)
		{
			p=p+q;
			q=p-q;
			p=p-q;
		}
		while(q%p)
		{
			b=p;
			p=q%p;
			q=b;
		}
	}
}

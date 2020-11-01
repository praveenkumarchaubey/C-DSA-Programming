#include<iostream>
using namespace std;
int main()
{
	cout<<"enter the numbers";
	int m,n,sum;
	cin>>m>>n;
	cout<<"triangular numbers are\n";
	for(int i=m;i<=n;i++)
	{   sum=0;
		for(int x=1;x<=n;x++)
		{
			sum=sum+x;
			if(sum==i)
			{
				cout<<sum<<"\t";
				break;
			}
		}
	}
}

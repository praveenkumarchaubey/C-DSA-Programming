// Program to print the number of perfect squares
//  between m and n where m and n are the inputs.
#include<iostream>
#include<cmath>
using namespace std;
int work(int x,int n);
int main()
{
	system("clear");
	int m,n;
	cout<<"Enter two numbers";
	cin>>m>>n;
	cout<<"The number of perfect squares ";
	cout<<"between "<<m<<" and "<<n<<" is" <<work(m,n);
	cout<<endl;
	cout<<"Press any key to continue"<<endl;
	return 0;
}
int work(int x,int n)
	{
		float b;
		int a,s=0;
		for(float i=x;i<n;i++)
			{
				b=sqrt(i);
				a=sqrt(i);
				if(a==b)
					{
						s=s+1;
					}
			}
		return s;
	}

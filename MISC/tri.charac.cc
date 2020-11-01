//Program to print out a triangle of a character of specified lines
#include<iostream>
using namespace std;
int i,j;
void printnc(char c,int n)
	{
		for(j=0;j<n;j++)
			{
				cout<<c;
			}
	}
void printTriangle(int n)
	{
		const int Center=20;		// Print out a triangle of size n
		for(i=0;i<n;i++)
			{
				printnc(' ',Center-i);
				printnc('X',2*i+1);
				cout<<endl;
			}
	}	
int main()
	{			// Get dimension of triangle from user
		int m;
		system("clear");
		cout<<"Enter an integer m [0<m<12]:\n";
		cin>>m;
		while(m>0 && m<12)
			{
				printTriangle(m);
				cout<<"Enter an integer m [0<m<12]:";
				cin>>m;
			}
		cout<<"Press enter to exit"<<endl;
		return 0;
	}

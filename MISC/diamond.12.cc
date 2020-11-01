// Program to  Print out any number of diamonds of any size less than 12
#include<iostream>
using namespace std;
const int Center=20;
void printnc(char c,int n)
    {
		for(int lcv=0;lcv<n;lcv++)
			{
				cout<<c;
			}
     }
void printTriangle(int n)      // Print out a triangle of size n
     {
		 for(int i=0;i<n;i++)
			{
				printnc(' ',Center-i-1);
 		        printnc('*', 2*i+1);
				cout<<endl;
			}
  }
void printRTriangle(int n)         // Print reverse of triangle printed by printTriangle
 	{
		for(int i=0;i<n;i++)
			{
				printnc(' ',Center-n+i);
				printnc('X',2*n-2*i-1);
				cout<<endl;
			}
	}
int main()                     // Get dimension of triangle from user
	{
		int m;
		cout<<"Enter an integer m [0 < m < 12]: "<<endl;
		cin>>m;
		while(m>0 && m<12)
			{
				printTriangle(m);
				printRTriangle(m-1);
				cout<<"Enter an integer m [0 < m < 12]: ";
				cin>>m;
				
			}
	return 0;		
  }

#include<iostream>
using namespace std;
int function(int g);
int main()
    {
		int n,l;
		cout<<"Enter a number to give its inverse"<<"\t";
		cin>>n;
		l=function(n);
	return 0;
   }
int function(int g)
   {
	   int p=1,f,i;
	   while(p!=0)
		   {
			   p=g/10;
			   f=p*10;
			   i=g-f;
			   g=p;
			   cout<<i;
		   }
	return 0;
}

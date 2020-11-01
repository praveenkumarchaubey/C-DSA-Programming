/* Program to display a pyramid
	    *
      * * *
    * * * * *
  * * * * * * *
    * * * * *
      * * *
        *       */

#include<iostream>
using namespace std;
#include<iomanip>
int main()
{
system("clear");
int i,j,c=40;
for(i=1;i<7;i=i+2)
{
cout<<setw(c);
for(j=1;j<=i;j=j+1)
{
cout<<"*"<<" ";
}
c=c-2;
cout<<"\n";
}
for(i=7;i>=1;i=i-2)
{
cout<<setw(c);
for(j=i;j>=1;j=j-1)
{
cout<<"*"<<" ";
}
c=c+2;
cout<<"\n";
}
return 0;
}

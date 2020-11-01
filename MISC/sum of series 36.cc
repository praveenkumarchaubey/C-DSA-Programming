// Program to print the sum of the following series:
// 1 + (1+2)+(1+2+3)+......N where N is the input.
#include<iostream>
using namespace std;
int series(int);
int main()
{

int term, sum =0;
cout<<"Enter the value of N"<<endl;
cin>>term;
sum=series(term);
cout<<"The sum of the series of "<<term<<" terms is "<<sum<<endl;
cout<<"Press any key to continue"<<endl;

return 0;
}
int series(int num)
{
int s=0,ss=0, i,j;
for(i=1;i<=num;i++)
{
ss=0;
for(j=1;j<=i;j++)
ss=ss+j;
s=s+ss;
}
return s;
}

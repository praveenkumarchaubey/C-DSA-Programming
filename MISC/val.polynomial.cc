// The program calculates the value of a polynomial
#include<iostream>
using namespace std;
const int MAXDEGREE=10;  
int main() 
	{
		float x,y;
		float coefficients[MAXDEGREE+1];  // coefficients of a polynomial
		float x_powers[MAXDEGREE+1];      // powers of x
		int degree,i;
		cout<<"\nCalculation of polynomial";
		cout<<"\nEnter degree ";
		cin>>degree;
		if(degree>MAXDEGREE || degree<0)
			{
				cout<<"\nError";
				exit(0);
			}
		for(i=degree;i>=0;i--)        // read coefficients, highest first:
			{
				cout<<"\nEnter coefficient "<<i<<" ";
				cin>>coefficients[i];
			}
		cout<<"\nEnter x ";        // read x:
		cin>>x;
		x_powers[0]=1;             // calculate powers of x
		for(i=1;i<=degree;i++)
			x_powers[i]=x_powers[i-1]*x;
		y=0;
		for(i=0;i<=degree;i++)      // calculate polynomial
			y=y+coefficients[i]*x_powers[i];
		cout<<"\n\nResult is "<<y;      // write result
		cout<<"press enter to exit";
		return 0;
	}

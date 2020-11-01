// Program to compute the GCD (Greatest Common Divisor) using
// RECURSIVE FUNCTION
#include<iostream>
using namespace std;
int main()
	{
		system("clear");
		int m,n;   
// Functions used ...
// RECURSIVE FUNCTION TO FIND GREATEST COMMOM DIVISOR
        int gcd(int,int);
		cout<<endl<<"Enter two positive integers separated by a space: ";
		cin>>m>>n;
		cout<<endl;
		cout<<"Their greatest common divisor is "<<gcd(m,n)<<endl;
	return 0;
   }
// RECURSIVE GCD FUNCTION
// FINDS THE GREATEST COMMON DIVISOR OF TWO INTEGERS
int gcd(int m,int n) 
	{
		if(n<=m && m%n==0) 			// m and n are defined and both are > 0.
			return n;               // returns the greatest common divisor of m and n.
		else 
			if(m<n)
				return gcd(n,m);
			else
				return gcd(n,m%n);
		}

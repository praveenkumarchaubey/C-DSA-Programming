// Program for computation of:
//1). Natural Log (Ln)
//2). Log with Base 10(Log10)
//3).Log of your desired Base (LogA^x)
#include<iostream>
using namespace std;
class logarithm
	{
		protected:
			long ans;
		public:
			double loga(double);
			double ln(double x);
			double checking(double);
	};
double logarithm::loga(double b)
	{
		double LOG10=0,c;
		c=ln(b);
		LOG10=c/2.30258509299404;
		return LOG10;
    }
double logarithm::ln(double x)
	{
		double lnX=0.000001,check;
		do
			{
				lnX=lnX-(exp(lnX)-x)/exp(lnX);
				check=checking(lnX);
			}
		while(check!=0);
		return lnX;
	}
double logarithm::checking(double x)
    {
		static double x1=0;
		double x2;
		if(x1==0)
			{
				x1=x;
				return 1;
			}
		else
			{
				x2=x1-x;
				if(x2<0)
					x2*=-1;
				 x1=x;
				return x2;
			}
	}
int main()
	{
		system("clear");
	    logarithm a;
	    double b=0,k=0;
	    int opt1;
	    char ch;
	    system("clear");
	    cout<<"\n1. For Natural Log (ln) ";
		cout<<"\n2. For Log of Base 10";
		cout<<"\n3. For Log of x with Base a, Log a^x = Logx/Loga";
		cout<<"\n4. For Exit";
		cout<<"\n ";
		cout<<"\n\n\n\tEnter Your Option:- ";
		cin>>opt1;
	    switch(opt1)
		{
				case 2:
					cout<<"\n\nEnter the value of X : ";
					cin>>b;
					cout<<"\n\n\t( Log_10^ "<<b<< " is "<<a.loga(b)<<" )";
					break;
				case 1:
					cout<<"\n\nEnter the value of X"<<"\t";
					cin>>b;
					cout<<"\n\n\t( Ln "<<b<<" : "<<a.ln(b)<<" )";
					break;
				case 3:
					cout<<"\n\nEnter the value of a :"<<"\t";
					cin>>b;
					cout<<"\nEnter the value of x :"<<"\t";
					cin>>k;
					cout<<"\n\n\t( Log a^x = Log x/Log a "<<b<<" : "<<a.ln(k)/a.ln(b)<<" )";
					break;
				case 4:
					exit(0);
					break;
				default:
					cout<<"\n\n\t wrong data enetered.....";
		}
	return 0;
}

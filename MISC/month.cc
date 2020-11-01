// Program displays the month of any year
#include<iostream>
using namespace std;
int main()
	{
		system("clear");
		int b1,b2,o;
		int i,j,k=0,l=0,m=0,n=0,b3,c=0,c1,c2,c3,a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		int ab[12]={1,2,3,4,5,6,7,8,9,10,11,12};
		char*z[12]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
		cout<<"  ENTER THE MONTH  : ";
		cin>>b1;
		cout<<"  ENTER THE YEAR  : ";
		cin>>b2;
		cout<<"\n";
		o=b1-1;
		for(o=0;o<=11;o++)
			{
				if(b1==ab[o])
					{
						cout<<"\n         "<<z[o];
						cout<<"       "<<b2;
					}
			}
		if(b2%4==0)
			a[1]=29;
		else
			a[1]=28;
		if(b2>=2000)
			b3=b2-2000;
		else
			{
				b3=2000-b2;
				b3*=2;
			}
		if(b1==12)
			n=12;
		if(b1==1)
			{
				k=11;
				l=1;
				for(i=0;i<=k;i++)
					m+=a[i];
			}
		for(i=0;i<(b1-1);i++)
			c+=a[i];
		c2=(c+b3+1)%7;
		cout<<"\n\n\n\n";
		cout<<"  SU  MO  TU  WE  TH  FR  SA\n\n";
		for(j=0;j<c2;j++)
			cout<<"    ";
		for(i=1;i<=a[b1-1];i++)
			{
				if(i<10)
					cout<<"   "<<i;
				else
					cout<<"  "<<i;
				if((i+c2)%7==0)
					cout<<"\n\n";
			}
	return 0;
   }

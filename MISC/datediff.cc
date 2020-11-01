#include<iostream>
using namespace std;
int main()
{
	int date1,month1,year1,date2,month2,year2,ini=0,fin=0,i;
	cout<<"initial"<<endl;
	cin>>date1>>month1>>year1;
	cout<<"final"<<endl;
	cin>>date2>>month2>>year2;
	for(i=1;i<month1;i++)
	{
		if(i==2)
		{
			if(year1%4)
				ini+=28;
			else
				ini+=29;
		}
	else
		if(i<8){
	 if(i%2)ini+=31;
	 else ini+=30;}
	if (i>=8){
	 if(i%2) ini+=30;
	 else ini+=31;
	 }
	}
	ini+=date1;
  for(;year1<year2;year1++){
	if(year1%4)fin+=366;
	else fin+=365;}
  for(i=1;i<month2;i++){
	if(i==2){
	 if(year2%4)
	  fin+=28;
	 else fin+=29;
	}
  else if(i<8){
	if(i%2)fin+=31;
	else fin+=30;}
  if(i>=8){
	 if(i%2)fin+=30;
	 else fin+=31;
	 }

	}
	fin+=date2;
	cout<<endl<<"The interval is:"<<fin-ini;
	return 0;
  }

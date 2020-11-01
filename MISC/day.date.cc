// Program to  Identify the day on a particular date 
#include<iostream>
using namespace std; 
#define STD_DD 1 
#define STD_MM 1 Monday, 07 February, 2005
#define STD_YYYY 0001 
#define STD_DAY "Sunday" 
#define LEAP_YR 366 
#define NOT_LEAP 365 
unsigned int dd, mm, yyyy, y; 
void input(void); 
unsigned int select_days(unsigned int); 
void printday(unsigned int); 
int main()
{
	unsigned int daylimit,day=1,d,m; 
	system("clear");
	cout<<" This program tells you the day of the date typed in.\n";
	input();
	for(y=STD_YYYY;y<=yyyy;y++)
		{
			for(m=1;m<=12;m++)
				{
					daylimit=select_days(m);
					for(d=1;d<=daylimit;d++)
						{
							if(day==8)
								day=1;
							if(d==dd && m==mm && y==yyyy)
								break;
							++day;
						}
					if(d==dd && m==mm && y==yyyy)
						break;
				}
			if(d==dd && m==mm && y==yyyy)
				break;
		}
	cout<<endl;
	cout<<"The day on the date "<<mm<<" "<<dd<<" "<<yyyy<<" is ";
	printday(day);
	return 0;
}
void input() 
	{ 
		cout<<"\n Type in the date (mm dd yyyy) : ";
		cin>>mm;
		cin>>dd;
		cin>>yyyy;
		if(mm<=0 || mm>12)
			{			
				do 
					{
						printf(" Type in the month again : "); 
						scanf("%d",&mm); 
					}
				while(mm<=0 || mm>12);
			}
		if(dd<=0 || dd>31)
			{ 
				do
					{ 
						printf(" Type in the day date again : "); 
						scanf("%d",&dd); 
					}
				while(dd<=0 || dd>31); 
			}
		if(mm==4 || mm==6 || mm==9 || mm==11 && dd==31) 
			{
				printf(" Date can't be greater than 30 for this month!\n"); 
				do 
					{
						printf(" Type in the day date again : "); 
						scanf("%d",&dd); 
					}
				while(dd>30 || dd<=0);
			}
		else
			if(mm==2 && dd>29)
				{
					printf(" Date can't be greater than 29 for this month!\n"); 
					do
						{
							printf(" Type in the day date again : "); 
							scanf("%d", &dd); 
						}
					while(dd>29 || dd<=0);
				}
			if(yyyy%4!=0 && mm==2 && dd==29)
				{
					printf(" Date of 29 in the month 2 is only possible in the leap years!\n"); 
					do
						{
							printf(" Type in the day date again : "); 
							scanf("%d", &dd); 
						}
					while(dd>28 || dd<=0);
				}
			if(yyyy<=0)
				{
					do 
						{
							printf(" Type in the year : "); 
							scanf("%d",&yyyy); 
						}
					while(yyyy<=0); 
				}
				
				
} 
unsigned int select_days(unsigned int m) 
{ 
	switch(m)
		{
			case 2: 
				if(y%4!=0)
					return(28); 
				else 
					return(29); 
			case 1 : 
			case 3 : 
			case 5 : 
			case 7 : 
			case 8 : 
			case 10: 
			case 12: 
			return(31); 
			default: 
				return(30); 
		} 
		
} 
void printday(unsigned int day) 
{
	switch(day)
		{
			case 1: 
				printf("Sunday.\n"); break; 
			case 2: 
				printf("Monday.\n"); break; 
			case 3: 
				printf("Tuesday.\n"); break; 
			case 4: 
				printf("Wednesday.\n"); break; 
			case 5: 
				printf("Thursday.\n"); break; 
			case 6: 
				printf("Friday.\n"); break; 
			case 7: 
				printf("Saturday.\n"); break; 
		}
}

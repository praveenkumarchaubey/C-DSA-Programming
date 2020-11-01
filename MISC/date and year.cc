// Program to get the day the month starts on, and
//the number of days in the month to output a calendar.
//-------------------Includes-------------------- 
#include<iostream>
using namespace std;
//--------------Function Prototypes-------------- 
int ShowDateLine(int day, int EndDay, int BoxWidth); 
void ShowRestOfBox(int BoxWidth, int BoxHeight); 
void ShowDates(int BoxWidth); 
void Divider(int BoxWidth); 
//---------------------Main---------------------- 
int main()
	{
		int StartDay,EndDay,day,counter,weeks; 
		const int BoxWidth=8,BoxHeight=3; 
		char end; 
		cout<<"1. Sun  2. Mon  3. Tue  4. Wed "<<endl; 
		cout<<"5. Thu  6. Fri  7. Sat" << endl<<endl; 
		do
		{
			cout<<"Enter the starting day: "; 
			cin>>StartDay; 
			if (StartDay<1 || StartDay>7) 
				{ 
					cout << "\aError, must be between 1 and 7.\n"; 
				}
		}
		while(StartDay<1 || StartDay>7); /* Error checking */ 
		day=StartDay*-1+2; 
		do
		{
			cout<<"Enter the amount of days in the month: "; 
			cin>>EndDay; 
			cout<<endl;
			if (EndDay<1 || EndDay>31) 
				{ 
					cout << "\aError, must be between 1 and 31\n"; 
				} 		
		}
		while(EndDay<1 || EndDay>31);/* Error checking */
		weeks=(EndDay+StartDay-2)/7; 
		weeks++; 
	//----------------Draw Calendar------------------ 
        ShowDates(BoxWidth); 
		Divider(BoxWidth); 
		for(counter=0;counter<weeks;counter++) 
			{ 
				day=ShowDateLine(day,EndDay,BoxWidth); 
				ShowRestOfBox(BoxWidth,BoxHeight); 
				Divider(BoxWidth); 
			}
		 cout<<"Press any key to continue"<<endl;
		}
//------------------Functions-------------------- 
/* Outputs a '*' then it outputs the days till it reaches the 'EndWeek' value. 
If day reaches the EndDay value, then it will output a space instead of a day. 
After each date it will output a '*', then proceed 'BoxWidth' spaces ahead. */ 
int ShowDateLine(int day, int EndDay, int BoxWidth)
{
	int counter, EndWeek; 
    cout.setf(ios::right); 
    cout<<"*"; 
    EndWeek=day+7; 
    for(counter=0;counter<7;counter++,day++)
    { 
		cout.width(BoxWidth-1); 
		if (day<1 || day>EndDay) 
        { 
            cout<<" "; 
        } 
        else 
        { 
            cout<<day; 
        } 
        cout<<"*"; 
    } 
	
	
    cout<<endl; 

    return day; 
} 
//----------------------------------------------- 
/* Outputs a '*' every 'BoxWidth' length, for a total of 8 '*'. 
It does that 'BoxHeight' times. */ 
void ShowRestOfBox(int BoxWidth, int BoxHeight)
{
	int countera,counterb; 
    cout.setf(ios::right); 
    for(countera=1;countera<BoxHeight+0;countera++) 
    { 
        cout<<"*"; 
        for(counterb=0;counterb<7;counterb++) 
        { 
             cout.width(BoxWidth); 
             cout<<"*"; 
        } 
        cout<<endl; 
    } 
} 
//----------------------------------------------- 
/* Outputs the all 7 days of the week. It takes the 'BoxWidth' and outputs the 
day in the 
middle of where the box will be. */ 
void ShowDates(int BoxWidth)
{
	cout.setf(ios::right); 
	cout.width(BoxWidth/2+2); 
	cout<<"Sun"; 
	cout.width(BoxWidth); 
	cout<<"Mon"; 
	cout.width(BoxWidth); 
	cout<<"Tue"; 
	cout.width(BoxWidth); 
	cout<<"Wed"; 
	cout.width(BoxWidth); 
	cout<<"Thu"; 
	cout.width(BoxWidth); 
	cout<<"Fri"; 
	cout.width(BoxWidth); 
	cout<<"Sat"<<endl; 
	
} 
//----------------------------------------------- 
//Outputs a bar of '*' 'BoxWidth' * 7 + 1 
void Divider(int BoxWidth)
{ 
	int length,counter; 
	length=BoxWidth*7+1; 
	for (counter=0;counter<length;counter++) 
		{ 
			cout<<"*"; 
		}
    cout<<endl; 
}

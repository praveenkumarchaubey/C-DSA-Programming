// Program to implement a Recursive Function
#include<iostream>
using namespace std;
void recurfunc(int start,int stop,char*buff);
int main()
{
	system("clear");
	cout<<"enter how many times to loop: ";
	char buff[100];
	cin>>buff;
	int num;
	num=atoi(buff);
	if(num>=1)
		{
			recurfunc(0,num," this is a recursive function");
		}
	else
		{
			cout << "sorry you didnt enter valid data" << endl;
			return -1;
		}
	return 0;	
}
void recurfunc(int start,int stop,char*buff)
    {
		if(start<=stop)
			{
				start++;
				cout<<"\n"<<buff<<"\n";
				recurfunc(start,stop,buff);
			}
		else
			{
				return;
			}
	}

// Program to input a string and truncate all multiple occurrances of the
// characters and print the string with their only single occurrance.
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	system("clear");
	char s[31];
	cout<<"Please input your string:(not more than 30 characters long) ";
	cin.getline(s,30);
	cout<<"\n";
	int l=strlen(s);
	char t;
	for(int i=0;i<l-1;i++)
	{
		for(int j=i+1;j<l;j++)
		{
			if(s[i]==s[j] && s[i]!=' ')
			{
				for(int k=j;k<l;k++)
				{
					s[k]=s[k+1];
				}
			}
		}
	}
	cout<<"\nYour resultant string is: "<<s;
	cout<<"\nPress ENTER to close the window..";
return 0;
}

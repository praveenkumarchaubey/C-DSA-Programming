// Program to sort a string in ascending order
#include<iostream>
using namespace std;
char word[50];
void EnterString()
	{
		system("clear");
		cout<<"\nEnter a string: ";
		gets(word);
	}
void Sort()
	{
		int l=strlen(word);
		int i,j;
	    char tmp;
	    for(i=0;i<(l-1);i++)
			    for(j=i+1;j<l;j++)
					    if(word[i]>word[j])
							{
								tmp=word[i];
								word[i]=word[j];
								word[j]=tmp;
							}
	}
void ShowString()
	{
		int l=strlen(word);
	    int i;
		cout<<"\nThe sorted string is: ";
		for(i=0;i<l;i++)
			cout<<word[i];
		cout<<'\n';
	}
int main()
	{
		EnterString();
		Sort();
		ShowString();
		cout<<endl;
		cout<<"Press enter key to exit"<<endl;
		return 0;
	}

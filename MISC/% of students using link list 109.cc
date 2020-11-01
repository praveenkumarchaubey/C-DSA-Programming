
// Program Implementing Linked list to print the percentage
// marks of 5 students by inputting the name and
// marks of 3 subject in a linked list
#include<iostream>
using namespace std;
struct abc
{
char n[20];
float m,p,c;
abc *next;
};
int main()
{
int c=0;float per;
abc *list,*start=NULL,*ptr;
cout<<"enter the name and marks of three subjects of five children ";
for(int i=0;i<=4;i++)
{
if(start==NULL)
{
list=new abc;
cout<<endl;
cout<<"enter the details for name and three marks:";
cin>>list->n>>list->p>>list->c>>list->m;
cout<<endl;
start=list;
}
else
{
ptr=new abc;

cin>>ptr->n>>ptr->p>>ptr->c>>ptr->m;
list->next=ptr;
list=list->next;
}
}
ptr=start;
cout<<"\n the list is :\n";
cout<<"name \t\t\t\t percentage\n";
while(ptr!=NULL)
{
cout<<ptr->n;
per=(ptr->p+ptr->c+ptr->m)/3;
cout<<"\t\t\t\t"<<per<<"\n";
ptr=ptr->next;
}
return 0;

}

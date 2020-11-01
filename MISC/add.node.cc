//adding a new node at any place in a linked list 
//acording to users choice
#include<iostream>
using namespace std;
struct node
	{
		char n[20];
		int p;
		node*next;
		};
int main()
	{
		system("clear");
		int c=0,per,i,l;
		node*list,*start=NULL,*ptr,*prev;
		char nm[20],flag;
		cout<<"enter the no of children \n";
		cin>>l;
		cout<<"enter the name and percentage marks of "<<l<<" children \n";
		for(i=0;i<=l-1;i++)
			{
				if(start==NULL)
					{
						ptr=new node;
						cout<<"enter the details :\n";
						cin>>ptr->n>>ptr->p;
						start=ptr;
						prev=ptr;
					}
				else
					{
						ptr=new node;
						cin>>ptr->n>>ptr->p;
						prev->next=ptr;
						prev=prev->next;
					}
			}
		int ch,h;
		cout<<"do you want to add another data, then enter 1 for adding";
		cin>>h;
		while(h==1)
			{
				cout<<"\n enter the choice where the record is to be inserted \n";
				cout<<"\n 1. starting of the list ";
				cout<<"\n 2. in between ";
				cout<<"\n 3. at the end \n";
				cin>>ch;
				list=new node;
				cout<<"enter the name and percent of new student :\n";
				cin>>list->n>>list->p;
				if (ch==1)
					{
						list->next=start;
						start=list;
					}
				else 
					if(ch==3)
						{
							ptr=start;
							while(ptr!=NULL)
								{
									prev=ptr;
									ptr=ptr->next;
								}
							prev->next=list;
							list->next=NULL;
						}
				else
					{
						cout<<"enter the record number (2-"<<l<<") after which the node is to be inserted \n";
						cin>>c;
						if (c==1 || c==l)
							{
								cout<<"sorry wrong no. entered ";
							}
						i=0;
						ptr=start;		//insert the node
						cout<<"\n";
						cout<<"the list is :\n";
						cout<<"name"<<"\t\t\t"<<"percentage\n";
						while(ptr!=NULL)
							{
								i++;
								if (i==c)
									{
										list->next=ptr->next;
										ptr->next=list;
									}
								ptr=ptr->next;
							}
					}
			}
		ptr=start;
		while (ptr!=NULL)				//display all the records
			{
				cout<<ptr->n<<"\t\t\t"<<ptr->p;
				ptr=ptr->next;
				cout<<"\n";
			}
        return 0;
}

#include<iostream>
using namespace std;
class list{
	struct node{
		int data;
		node *next;
	}*start;
	public:
	 list(){start=NULL;}
     void addnode(int n){
		 if(start==NULL){
			 start=new node;
			 start->data=n;
			 start->next=NULL;
		 }
		 else{
			 node *temp=start;
			 while(temp->next!=NULL)
				 temp=temp->next;
			 node *newnode=new node;
			 newnode->data=n;
			 newnode->next=NULL;
			 temp->next=newnode;
		 }
	 }
	 void display(){
		 node *temp=start;
		 while(temp!=NULL){
			 cout<<temp->data;
			 temp=temp->next;
		 }
	 }
	 int removenode(int nodeno){
		 int c=0;
		 node *temp=start;
		 node *t1,*ptr=temp;
		 while(temp->next!=NULL)
		    {   
			 c++;
			  ptr=temp;
				ptr=ptr->next;
	     		if(nodeno==c){
				 int p=ptr->data;
				 t1=ptr->next;
				 delete ptr;
				 temp->next=t1;
			     return p; 
		        }
	         else
				  {
			    	   if(temp->next==NULL){
				       cout<<"does not exist";
					   return -1;
					   break;
				       }
			       }
			   }			
		  }
	 };
	 
int main(){
	list d;
	int c=0;
	char ch='y';
	while(ch=='y'){
	int x;
	cin>>x;
	d.addnode(x);
		c++;
		cout<<"do you want to continue";
		cin>>ch;}	
	
	d.display();
	int z;
	cin>>z;
	cout<<d.removenode(z);
	return 0;
}

#include<iostream>
using namespace std;
class queue{
		struct node{
		int data;
		node *next;
	}*front, *rear;
	public:
		queue(){
		front=rear=NULL;}
	void push(int n){
		node *temp=new node;
		temp->data=n;
		temp->next=NULL;
		if(front==NULL){
			front=rear=temp;
		}
		else{
			rear->next=temp;
			rear=temp;
		}
	}
		int pop(){
			if(front==NULL){
				cout<<"underflow";
				return -1;
			}
			else{
				int d;
				node *temp=front;
				d=front->data;
				front=front->next;
				delete temp;
				return d;
			}
		}
		void display(){
			node *temp;
			if(front==NULL) cout<<"underflow";
            else{
             for(temp=front;temp!=NULL;temp=temp->next)				
			    cout<<temp->data;
		 }
		}
	};
	int main(){
	queue d;
	int c=0;
	char ch='y';
	while(ch=='y'){
	int x;
	cin>>x;
	d.push(x);
		c++;
		cout<<"do you want to continue";
		cin>>ch;}	
	
	d.display();
	int z;
    cin>>z;
	for(int i=1;i<=z;i++) 	
	cout<<d.pop();
	return 0;
}

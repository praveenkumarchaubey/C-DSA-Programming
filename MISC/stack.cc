#include<iostream>
using namespace std;
class stack{
   struct node{
	int data;
	node *next;
	};
	node *top;
	public:  
	    stack(){top=NULL;}
		int empty(){return top==NULL;}
		void push(int n){
			node *t=new node;
			t->data=n;
			t->next=top;
			top=t;
		}
		int pop(){
			if(empty()){
				cout<<"underflow";
			}
			else{
				int d=top->data;
				node *t=top;
				top=top->next;
				delete t;
				return d;
			}
			return -1;
			}
		};
		int main(){
			int a[5],b[5],c[6];
			stack l,m;
			cout<<"enter the first number";
			for(int i=0;i<5;i++)
			{
				cin>>a[i];
			}
			cout<<"enter the second number";
			for(int i=0;i<5;i++)
			{
				cin>>b[i];
			}
			for(int i=0;i<5;i++)
			{
				l.push(a[i]);
				m.push(b[i]);
			}
			int p,quo=0;
			for(int i=5;i>=1;i--)
			{
				p=l.pop()+m.pop();
				c[i]=(p+quo)%10;
				quo=(p)/10;
			}
			c[0]=quo;
			for(int i=0;i<=5;i++)
			{
				cout<<c[i];
			}
			return 0;
		}

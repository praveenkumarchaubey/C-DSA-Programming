#include<iostream>
using namespace std;
class Fibonacci{
		public:
	int term(int a)
	{
		if(a<3) return 1;
			else return term(a-1)+term(a-2);
		}
	int gennext(int b)
	{
		return term(b)+term(b-1);
			}
		};
		int main(){
			Fibonacci h;int n,sum=0;
			cout<<"enter the number of fibonacci numbers to be generated\n";
			cin>>n;
			cout<<h.term(n)<<endl;
			cout<<h.gennext(n);
			for(int i=0;i<n;i++)
				sum=sum+h.term(i);
			cout<<"\n sum of"<<n<<"terms is"<<sum;
			return 0;
		}

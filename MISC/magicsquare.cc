#include<iostream>
using namespace std;
int arr[20][20], n, a,b,i;
void magic(int , int , int, int);
int main()
{ int j,x,k;
 system("clear");	
cout<<"Enter size of matrix (n X n, where n is odd):";
cin>>n;
/*int **arr=new int *[n];
for(i=0;i<n*n;i++)
arr[i]=new int[n];	*/
cout<<"Enter 1st element of the "<<n*n<<" sequential elements:";
cin>>x;
cout<<endl<<"The required matrix format is "<<endl;
arr[0][n/2]=x;
magic(0,n/2, x, n);
cout<<endl;
for (i=0; i<n; i++)
{
for (k=0; k<n; k++)
cout<<arr[i][k]<<"\t";
cout<<endl;
}
cout<<endl<<"Press any key to continue"<<endl;
return 0;
}
void magic( int a, int b, int x, int n)
{ //int **arr=new int *[n];   
int c=1;
for (x=x+1,i=2; i<=n*n; i++,c++,x++)
{  if(c<n)
{
a=a-1;
b=b-1;
if (a==-1)
a=n-1;
if (b==-1)
b=n-1;
}
else
{a=a+1;c=0;
}
arr[a][b]=x;
}
}

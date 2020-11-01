// PROGRAM Inputting  NINE INPUTS AND TREATS THE
// INPUTS  AS COMPONENTS OF THREE DIMENSIONAL MATRIX AND CALCULATES THE //
// DETERMINANT OF THE MATRIX.
#include<iostream>
using namespace std;
int main()
   {
       system("clear");
       int matrix[3][3];		
       int count,count1,result;
       int x,y;
       for(count1=1;count1<=3;count1++)        
		   {
			   for (count=1;count<=3;count++)
				   {
					   system("clear");
					   cout<<"PLEASE ENTER INTEGERS FOR THE MATRIX, ONE BY ONE: ";	
					   cin>>matrix[count][count1];
					}
           }
       count=matrix[1][1]*((matrix[2][2]*matrix[3][3])-(matrix[3][2]*matrix[2][3]));
	   count1=matrix[2][2]*((matrix[1][2]*matrix[3][3])-(matrix[3][2]*matrix[1][3]));
       result=matrix[3][3]*((matrix[1][2]*matrix[2][3])-(matrix[2][2]*matrix[1][3]));
       result=count-count1+result;
       cout<<"THE DETERMINANT OF MATRIX IS :"<<result; 
       return 0;  
}

//  Declaration of a Class and manipulation of member function.
//  Display of the result of students with computed grade of marks.
+#include<iostream>
using namespace std;
class result
{
int rollnum;
float total,percent;
public:
void inputdata(int rol,float tot,float per)
{
rollnum = rol;
total = tot;
percent = per;
}
void display(void)
{
cout<<"R E S U L T ";
cout<<endl;
char grade[20];
cout<<endl<<"The roll number is "<<rollnum;
cout<<endl<<"The total marks is "<<total;
cout<<endl<<"The percent marks is "<<percent;
if (percent<40) strcpy(grade,"Fail");
if (percent>=40 && percent<60) strcpy(grade,"Pass");
if (percent>=60 && percent<80) strcpy(grade,"First");
if (percent>=80) strcpy(grade,"Excellent");
cout<<endl<<"The grade obtained is "<<grade;
cout<<endl;
}
};
int main()
{
result studrecord;
int rol;
float tot,per;
cout<<"Enter the rollnumber"<<endl;
cin>>rol;
cout<<"Enter the total"<<endl;
cin>>tot;
per=tot/5;
studrecord.inputdata(rol,tot,per);
studrecord.display();
cout<<endl;
cout<<"Press any key to return ";
return 0;
 }

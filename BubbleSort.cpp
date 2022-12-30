#include <iostream>
#include<string.h>
using namespace std;
struct student
{
   int Rollno;
   char Name[10];
   float SGPA;
};
void getdata(struct student S[10],int n)
{
     for(int i=0;i<n;i++)
   {
       cout<<"\nEnter Rollno,Name,SGPA of student:"<<i<<"\t";
       cin>>S[i].Rollno>>S[i].Name>>S[i].SGPA;

   }
}
void putdata(struct student S[10],int n)
{
      cout<<"\n Rollno\tName\tSGPA";
      for(int i=0;i<n;i++)
      cout<<"\n"<<S[i].Rollno<<"\t"<<S[i].Name<<"\t"<<S[i].SGPA;

}
void bubble(struct student a[10],int n)
  {
      for(int i=0;i<n-1 ;i++)
    {
       for(int j=0;j<n-i-1;j++)

       {      if(a[j].Rollno>a[j+1].Rollno)

         { struct student t=a[j];

   a[j]=a[j+1];
   a[j+1]=t;

  }
  }
  }
  }

int linearSearch(struct student values[20], int n,int Key)
{   int flag=0;
    cout<<"\nRollno\tName\tSGPA";
    for(int i = 0; i < n; i++)
    {
        if (values[i].SGPA == Key )

        {
             flag=1;

           cout<<"\n"<<values[i]. Rollno<<"\t";
           cout<<values[i].Name<<"\t"<<values[i].SGPA;
        }
        }
    return flag;
}
int main()
{  int n,ch;
   char Name[20];
   int i,j,k;
   struct student S[20];
   cout<<"Enter number of records ";
   cin>>n;
   getdata(S,n);
  do
   {cout<<"\n1:Bubble sort \n2.Linear Search";
   cout<<"\n\nEnter the choice ";
   cin>>ch;
   switch(ch)
{
    case 1:
    cout<<"\nRecord of students in ascending order of there Roll no.";
      bubble(S,n);
      putdata(S,n);
      cout<<"\n\n";
      break;

   case 2:
   float find;
   cout<<"\nEnter SGPA of a student to find record: ";
   cin>>find;
   int flag;
   flag=linearSearch(S,n,find);
   if(flag==0) cout<<"\n Record Not present";
   cout<<"\n\n";
   putdata(S,n);
   break;
  

}
}while(ch<3);
}

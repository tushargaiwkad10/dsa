#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
using namespace std;
class stack
{
	struct node
	{
	   float   data;
	   node *next;
	};
	node *top;
public:
       stack()
       {
	 top=NULL;
       }
       int empty();
       void push(float);
       float pop();
       int Top();
};

int stack::empty()
{
 if(top==NULL)
	return 1;
else
 return 0;
}

void stack::push(float  x)
{  	node *newnode;
  newnode=new node;
  newnode->data=x;
  newnode->next=top;
  top=newnode;
}

float stack::pop()
{
   node *temp=top;
    float  x;
    top=top->next;
    x=temp->data;
 delete temp;
 return x;
}

int stack::Top()
{	return top->data;	}

int Priority(char Op)
{
if(Op=='(' || Op==')')
	return 0;
if(Op=='+' || Op=='-')
	return 1;
else if(Op=='*' || Op=='/')
	return 2;
else if(Op=='^')
	return 3;
else
	return 4;
}

float Operation(char Op,float A,float B)
{
float P;
if(Op=='*')
	P=A*B;
else if(Op=='/')
	P=A/B;
else if(Op=='+')
	P=A+B;
else if(Op=='-')
	  P=A-B;
else if (Op=='^')
        P=pow(A,B);

return P;
}

void infixtopostfix(char infix[20])
{
  char post[20],x,token;
  int i,j=0;
  stack s;
for(i=0;infix[i]!='\0';i++)
{	token=infix[i];
if(isalnum(token))//alphanumberic
         post[j++]=token;
else
   if(token == '(')
	s.push(token);
   else
	if(token == ')')
     while((x=s.pop())!='(')//pop till )
	       post[j++]=x;
	else
	{
	   while(!s.empty() && Priority(token)<=Priority(s.Top()))
	      {
               post[j++]=s.pop();
              }
	      s.push(token);
	}
}

while(!s.empty())
   post[j++]=s.pop();
  post[j]='\0';
cout<<"\nPostfix Expression=>";
cout<<post;
}

void infixtoprefix(char infix[20])
{
  char prefix[20],x,token;
 int i,j=0;
 stack S;
for(i=strlen(infix)-1;i>=0;i--)
{
  token=infix[i];
if(isalnum(token))
  prefix[j++]=token;
else
  if(token == ')')
  S.push(token);
else
  if(token == '(')
 while((x=S.pop())!=')')
prefix[j++]=x;
else
{
	while(!S.empty() && Priority(token)<Priority(S.Top()))
    {
   prefix[j++]=S.pop();
    }
    S.push(token);
 }
}

while(!S.empty())
   prefix[j++]=S.pop();
prefix[j]='\0';
cout<<"\nPrefix Expression=>";
for(i=strlen(prefix)-1;i>=0;i--)
  cout<<prefix[i];
}


int main()
{
    int ch;
    char infix[20],post[20],prefix[20];
 do
  {
   cout<<"\n\nSELECT THE CHOICE FROM BELOW\n1:Infix to Postfix\n2:Infix to Prefix\n3:Postfix Evaluation\n4:Prefix Evaluation";
   cout<<"\nEnter your Choice: ";
   cin>>ch;
   switch(ch)
   {
    case 1:
          cout<<"\nEnter infix Expression=>";
          cin>>infix;
	  	  infixtopostfix(infix);
		  break;

    case 2:
          cout<<"\nEnter infix Expression=>";
          cin>>infix;
		  infixtoprefix(infix);
		  break;

}
}while(ch!=3);
}

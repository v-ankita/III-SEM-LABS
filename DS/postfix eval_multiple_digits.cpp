//evluation of postfix multidigit
#include <iostream>
using namespace std;

int s[50];
int top=-1;
int flag=0;

int pop()
{      
  return(s[top--]); 
}

int push(int element)
{
  if(flag==1)
  {
    int num;
    num=pop();
    s[++top]=element+10*num;
 }
  else if(flag==0)
  {
    s[++top]=element;
    flag=1;
  }
}

int postEval(char postfix[])
{
	int i=0,op1,op2;
	char ch;
	while( (ch=postfix[i++]) != '\n')
  {
    if(ch>='0' && ch<='9') push(ch-'0');
    else if(ch==' ')
      flag=0;
    else
    {  
      flag=0;
      op2=pop();
      op1=pop();
      switch(ch)
      {
        case '+':push(op1+op2);break;
        case '-':push(op1-op2);break;
        case '*':push(op1*op2);break;
        case '/':push(op1/op2);break;
        default:
                 cout<<"Input invalid"<<endl;
                 break;
      }
    }
  }
  return(s[top]);
}
int main()
{   
  char postfix[50];
  cout<<"Enter the Postfix Expression:"<<endl;
  fgets(postfix,100,stdin);
  int result=postEval(postfix);
  cout<<"The answer is: "<<result;
}

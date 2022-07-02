#include<iostream>
#include<string.h>
#define Max 3
#define Len 25
using namespace std;
class Queue
{
 char Q[Max][Len];
 int Front,Rear;
 public:
 Queue(){Front=0;Rear=-1;}
 int is_Queue_Full();
 int is_Queue_Empty();
 int eQueue(char[]);
 int dQueue(char[]);
};
   int Queue::is_Queue_Full()
   {
     if(Rear!=-1 && Front==(Rear+1)%Max)
    return 1;
     return 0;
   }
  int Queue::is_Queue_Empty()
   {
     if(Rear==-1)
    return 1;
     return 0;
   }
  int Queue::eQueue(char Data[Len])
   {
     if(is_Queue_Full()) 
        return false;
     Rear=(Rear+1)%Max;
     strcpy(Q[Rear],Data);
     return true;
    }
  int Queue::dQueue(char Data[Len])
   {
      if(is_Queue_Empty())
         return false;
      strcpy(Data,Q[Front]);
      Q[Front][0]='\0';
      Front=(Front+1)%Max;
      if(Front==(Rear+1)%Max)
         { Front=0; Rear=-1; }    
      return true;
    }
 
int main()
     {
 
    Queue QU;   
    char Element[Len];
        int Choice;
    char Answer;
    do
      { 
        cout<<"\n1:Entry\t2:Exit\n Enter your Choice: ";
        cin>>Choice;
        switch(Choice)
              {
            case 1: 
                            cout<<"Enter Data";
                cin>>Element;
                if(QU.eQueue(Element))
                                     cout<<"\n Entered Successfully";
                else
                         cout<<"\nQueue Full Can not Enter";
                                break;
            case 2: 
                                if(QU.dQueue(Element))               
                         cout<<"\nExit Element "<<Element;
                else9
                                     cout<<"Queue is Empty can not Remove";           
                    break;
               }//switch end
        cout<<"\nContinue(y/n)...";
        cin>>Answer;
      }while(Answer=='y'||Answer=='Y');//while end
    return 1;
     }//main end

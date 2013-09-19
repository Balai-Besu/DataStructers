# include <iostream>
# include <malloc.h>
# include <stdlib.h>

using namespace std;

class queue
{
    struct list
    {
       int data;
       struct list *next;
    }*front,*rear;
   
    public: 
        void insert();
        void Delete();
        void display();
};

void queue :: insert(void)
{
   int a; 
   struct list *tmp;
   cin>>a;
   tmp= (struct list *)malloc(sizeof(struct list));
   tmp->data=a;
   tmp->next=NULL;
   if(front==NULL)
   {
      front=rear=tmp;
   }
   else
   {
      tmp->next=rear;
      rear=tmp;
   }
}

void queue :: Delete(void)
{
    struct list *tmp;
    if(front==NULL)
    {
       cout<<"Queue is empty!!"<<endl;
    }
    else if(front==rear)
    {
       cout<<"Removed item is -->"<<rear->data<<endl; 
       front=rear=NULL;
    }
    else
    { 
      tmp=rear;
      while( tmp->next!=front)
      {
         tmp=tmp->next;
      }
      tmp->next=NULL;
      free(front);
      front=tmp;
    }   
}

void queue :: display(void)
{
    struct list *tmp;
    tmp=rear;
    while(tmp!=NULL) 
    { 
       cout<<tmp->data<<"-->";
       tmp=tmp->next;
    }
    cout<<"NULL"<<endl;

}

int main()
{
     int choice;
     queue q;
     while(1)
     {
        cout<<"\n1.Enqueue\n2.Dequeue\n3.Display\n4.Quit\nEnter ur choice: ";
        cin>>choice;
        switch(choice)
        {
          case 1:
            q.insert();
            break;

          case 2:
            q.Delete();
            q.display();
            break;

          case 3:
            q.display();
            break;

          case 4:
            exit(0);

          default:
            printf("Wrong choice!!\n");
        }
     }
}

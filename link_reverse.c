#include <stdio.h>
#include <stdlib.h>

struct linklist
{
   int data;
   struct linklist *next;
}*top=NULL;

void insert()
{
   int x;
   struct linklist *temp;
   printf("Enter the data: ");
   scanf("%d",&x);
   temp=(struct linklist *)malloc(sizeof(struct linklist));
   temp->data=x;
   if(top==NULL)
   {
     top=temp;
     top->next=NULL;
   }
   else
   {
     temp->next=top;
     top=temp;
   }
}

void delete()
{
           struct linklist *temp;
           temp=top;
           if(temp==NULL)
           {
             printf("List is overflow!!\n");
           }
           else
           {
             printf("Removed item is: %d\n",temp->data);
             top=top->next;
             free(temp);
           }
}

void reverse()
{
           struct linklist *temp,*temp1=NULL;
           temp=top;
           if(temp==NULL)
           {
             // printf("List is empty!!\n");
           }
           else
           {
              top=temp1;
              while(temp!=NULL)
              {
                 if(top==NULL)
                 {
                     temp1=(struct linklist *)malloc(sizeof(struct linklist));
                     temp1->data=temp->data;
                     temp1->next=NULL;
                     top=temp1;
                 }
                 else
                 {
                    temp1=(struct linklist *)malloc(sizeof(struct linklist));
                    temp1->data=temp->data;
                    temp1->next=top;
                    top=temp1;
                 }
                 temp=temp->next;
              }
           //   display();
            }
}

void display()
{
           struct linklist *temp;
           temp=top;
           if(top==NULL)
           {
             printf("List is empty!!\n");
           }
           else
           {
             while(temp!=NULL)
             {
                printf("%d --> ",temp->data);
                temp=temp->next;
             }
             printf("NULL\n");
           }
}
  
int main()
{
  int choice;
  while(1)
  {   
      printf("\n1.Insert\n2.Delete\n3.Reverse the list\n4.Display\n5.Quit\n");
      printf("Enter ur choice:");
      scanf("%d",&choice);
      switch(choice) 
      {
         case 1:
           insert(); 
           break;

         case 2:
           delete();
           break;

         case 3:
           reverse();      
           display();
           break;
           
         case 4:
           display();
           break;
 
         case 5:
           exit(1);
 
         default:
           printf("Wrong choice!!\n");
     }
   }
}   

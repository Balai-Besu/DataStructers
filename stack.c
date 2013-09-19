# include <stdio.h>
# include <stdlib.h>

struct stack
{
   int data;
   struct stack *next;
}*top=NULL;

int main()
{
  int choice;
  while(1){
  printf("\n1.Push\n2.Pop\n3.Display\n4.Quit\nEnter ur choice: ");
  scanf("%d",&choice);  
  switch(choice)
  {
    case 1:
       push();
       break;
    case 2:
       pop();
       break;
    case 3:
       display();
       break;
    case 4:
       exit(0);
    default :
       printf("Wrong choice !!\n");
  }
  }
}

push()
{
   int a;
   struct stack *temp;
   temp=(struct stack *)malloc(sizeof(struct stack));
   printf("Enter the data: ");
   scanf("%d",&a);
   temp->data=a;
   temp->next=top;
   top=temp;
}

pop()
{
  struct stack *temp;
  if(top==NULL)
  {
     printf("Stack is empty!!\n");
  }
  else
  {
     temp=top;
     printf("Deleted item is: %d\n",temp->data);
     top=top->next;
     free(temp);
  }
}

display()
{
   struct stack *ptr;
   ptr=top;
   if(ptr==NULL)
   {
      printf("Stack is empty!!\n");
   }
   else
   {
      printf("Stack is: ");
      while(ptr!=NULL)
      {
         printf("%d-->",ptr->data);
         ptr=ptr->next;
      }
      printf("NULL\n");
   }
}





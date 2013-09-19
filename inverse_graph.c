# include <stdio.h>
# include <stdlib.h>

struct graph 
{
     int data;
     struct graph *next;
};

void insert(struct graph *n,struct graph *in,int m)
{
     int i,j,d,x;
     struct graph *temp,*start;
     for(i=0;i<m;i++)
     {
        printf("Enter the value of %d vertex : ",i+1);
        scanf("%d",&d);
        n[i].data=d; 
        n[i].next=NULL;
        in[i].data=d;
        in[i].next=NULL;
     }
     for(i=0;i<m;i++)
     {
        printf("Enter the number of adjcent vertex of %d : ",n[i].data);
        scanf("%d",&x);
        for(j=0;j<x;j++)
        { 
           printf("Enter the adjacent vertex of %d : ",n[i].data);
           scanf("%d",&d);
           temp=(struct graph *)malloc(sizeof(struct graph));
           temp->data=d;
           temp->next=NULL;
           if(n[i].next == NULL)
           {
               n[i].next=temp;
               start=temp;
           }
           else
           {
               start->next=temp;
               start=temp;
           }
        }
     }
}

void display(struct graph *n,int m)
{
     int i,j;
     struct graph *ptr;
     printf("\n\nThe graph is : \n");
     for(i=0;i<m;i++)
     {
        printf("NODE %d : ",n[i].data);
        ptr=n[i].next;
        while(ptr != NULL)
        {
           printf("--> %d ",ptr->data);
           ptr=ptr->next;
        }
        printf("\n");
     }
}

void inverse(struct graph *n,struct graph *in,int m)
{
      int i,j;
      struct graph *ptr, *start, *temp;
      for(i=0;i<m;i++)
      {
         ptr=n[i].next;
	 while(ptr != NULL)
         {
              for(j=0;j<m;j++)
              {
		  if(ptr->data == in[j].data)
		  {
		     temp=(struct graph *)malloc(sizeof(struct graph));
		     temp->data=n[i].data;
		     temp->next=NULL;
		     if(in[j].next==NULL)
		     {
                   	in[j].next=temp;
                        start=temp;
		     }
                     else
	             {
                        start=in[j].next;
			for(;start->next!=NULL;start=start->next);
			start->next=temp;
                     }	
                  }
              }
              ptr=ptr->next;
          }
       }
}


int main()
{
   int a,b,c;
   printf("Enter the number of vertex : ");
   scanf("%d",&a);
   struct graph node[a];
   struct graph inode[a];
   insert(node,inode,a);
   display(node,a);
   inverse(node,inode,a);
   display(inode,a);
}

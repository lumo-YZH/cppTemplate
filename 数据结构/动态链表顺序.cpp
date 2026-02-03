#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* insert(struct node * p,int x,int add)
{ 
    int i;
    struct node * temp=p; 
    for(i=1;i<add;i++)
    {
        temp = temp->next;
    }
    struct node * c=(struct node*)malloc(sizeof(struct node)); 
    if(add)
    {
	    c->data = x; 
	    c->next=temp->next; 
	    temp->next = c;
	}
	else
	{
		c->data = x; 
	    c->next=p; 
	    p=c;
	}
    return p; 
}
struct node* del(struct node * p,int add,int n)
{
    int i;
    struct node * temp=p;
    for (i=1; i<add; i++) {
        temp=temp->next;
    }
    if(add>=n)
    	return p;
    //if(add)
    //{
	    struct node * del=temp->next;
	    temp->next=temp->next->next; 
	    free(del);
//	}
	//else
//	//{
//		struct node * del=p;
//		p=p->next;
//		free(del);
//	//}
    return p; 
}

int main()
{
    int i,n;
    scanf("%d",&n);
    struct node *p,*q,*head=NULL;
    for(i=0;i<n;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&(p->data));
        if(head==NULL)
			head=p;
        else 
			q->next=p;
        q=p;
    }
    q->next=NULL;
    head=insert(head,100,0);
    //head=del(head,5,n);
    for(p=head;p!=NULL;p=p->next)
    {
        if(p==head)
            printf("%d",p->data);
        else
            printf(" %d",p->data);
    }
    
    return 0;
}


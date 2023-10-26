#include <stdio.h>
#include <stdlib.h>
#include "BigInteger.h"


struct node ** convertnumtoLL(struct node **start,int num)
{
	int rem=0;
	struct node *itr;
	
		struct node *newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=num;
		newnode->next=NULL;
		if(*start==NULL)
		{
			*start=newnode;
			itr=*start;
		}
		else
		{
			itr->next=newnode;
			itr=itr->next;
		}
		
	
}

int compare(struct BigInteger p1,struct BigInteger p2)
{
	if(p1.length>p2.length)
	{
		return 1;
	}
	else if(p1.length<p2.length)
	{
		return 0;
	}
	else
	{
		struct node *ptr,*qtr;
		ptr=p1.head;
		qtr=p2.head;
		while(ptr!=NULL && ptr->data==qtr->data)
		{
			ptr=ptr->next;
			qtr=qtr->next;
		}
		if(ptr==NULL)
		{
			return 2;
		}
		else
		{
		
			if(ptr->data>qtr->data)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}
struct BigInteger initialize(char *s)
{
  int i=0;
  struct BigInteger ll;
  ll.head=NULL;
  if(*s=='-')
  {
    ll.sign=-1;
    i++;
  }
  else
  ll.sign=1;
  while(*(s+i)!='\0')
  {
    convertnumtoLL(&ll.head,s[i]-'0');
    i++;
	}

  if(ll.sign==-1)
  ll.length=i-1;
  else
  ll.length=i;
  return ll;
}
void dis(struct node *l)
{
	struct node *rtr=l;
	while(rtr!=NULL)
	{
	
		printf("%d",rtr->data);
		rtr=rtr->next;
	}
	printf("\n");
}
int length(struct node *start)
{
	struct node *ptr=start;
	int count=0;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}
void display(struct BigInteger ll)
{
 if(ll.sign==-1)
 {
  printf("-");
 }
 dis(ll.head);
}
void reverseLL(struct node **start)
{
	struct node *curr,*prev,*nextt;
	curr=*start;
	prev=NULL;
	nextt=NULL;
	while(curr!=NULL)
	{
		nextt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextt;
	}
	*start=prev;
}
struct BigInteger add(struct BigInteger p1,struct BigInteger p2)
{
	struct node *ptr=p1.head,*qtr=p2.head,*temp=NULL,*rtr=NULL;
	struct BigInteger p3;
	p3.head=NULL;
  	p3.length=0;
	reverseLL(&p1.head);
	reverseLL(&p2.head);
	int carry=0,sum=0;
	ptr=p1.head;
	qtr=p2.head;
	while(ptr!=NULL && qtr!=NULL)
	{
		sum=ptr->data+qtr->data+carry;
		carry=sum/10;
		sum=sum%10;
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=sum;
		newnode->next=NULL;
		if(p3.head==NULL)
		{
			p3.head=newnode;
		}
		else
		{
			newnode->next=p3.head;
			p3.head=newnode;
		}
		ptr=ptr->next;
		qtr=qtr->next;
		p3.length++;
	}
	if(ptr==NULL)
	{
		ptr = qtr;
	}
	while(ptr!=NULL)
	{
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->next=NULL;
		int sum=ptr->data+carry;
		newnode->data=sum%10;
		carry=sum/10;
		if(p3.head==NULL)
		{
			p3.head=newnode;
		}
		else
		{
			newnode->next=p3.head;
			p3.head=newnode;
		}
		ptr=ptr->next;
		p3.length++;
	}
	if(carry!=0)
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->data=carry;
        newnode->next=p3.head;
        p3.head=newnode;
        p3.length++;
    }
    reverseLL(&p1.head);
	reverseLL(&p2.head);
	return p3;
}

struct BigInteger sub(struct BigInteger p1,struct BigInteger p2)
{
	int l1=p1.length;
	int l2=p2.length;
	int borrow=0,f=0,diff;
	struct BigInteger p3;
	p3.head=NULL;
	p3.length=0;
	p3.sign=1;
	if(compare(p1,p2)==0)
	{
		f=1;
		struct node *temp;
		temp=p1.head;
		p1.head=p2.head;
		p2.head=temp;
		p3.sign=-1;
	}
	reverseLL(&p1.head);
	reverseLL(&p2.head);
	struct node *ptr=p1.head;
	struct node *qtr=p2.head;
	while(ptr!=NULL && qtr!=NULL)
	{
		if(ptr->data<qtr->data)
		{
			if(borrow==0)
			{
				diff=ptr->data+10-qtr->data;
				borrow=1;
			}
			else{
				diff=ptr->data+9-qtr->data;
				borrow=1;
			}
		}
		else
		{
			if(borrow==0)
			diff=ptr->data-qtr->data;
			else
			{
				diff=ptr->data-qtr->data-1;
				borrow=0;
			}
		}
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=diff;
		newnode->next=NULL;
		if(p3.head==NULL)
		{
			p3.head=newnode;
		}
		else
		{
			newnode->next=p3.head;
			p3.head=newnode;
		}
		ptr=ptr->next;
		qtr=qtr->next;
		p3.length++;
	}
	while(ptr!=NULL)
	{
		struct node *newnode;
		newnode=(struct node *)malloc(sizeof(struct node));
		if(borrow==1)
		{
		diff=ptr->data-1;
		borrow=0;
		}
		else
		diff=ptr->data;
		newnode->data=diff;
		newnode->next=NULL;
		if(p3.head==NULL)
		{
			p3.head=newnode;
		}
		else
		{
			newnode->next=p3.head;
			p3.head=newnode;
		}
		ptr=ptr->next;
		p3.length++;
	}
		reverseLL(&p1.head);
	    reverseLL(&p2.head);
		return p3;
   
}

struct BigInteger mul(struct BigInteger p1,struct BigInteger p2)
{
	struct node *ptr=p1.head,*qtr=p2.head,*temp=NULL,*rtr=NULL;
	struct BigInteger p3;
	p3.head=NULL;
  	p3.length=0;
	int carry=0;	
	int l1=p1.length;
	int l2=p2.length;
	if(l1<l2)
	{
		struct node *temp;
		temp=p1.head;
		p1.head=p2.head;
		p2.head=temp;
	}
	reverseLL(&p1.head);
	reverseLL(&p2.head);
	ptr=p1.head;
	qtr=p2.head;
	if(qtr!=NULL)
	{
		carry=0;
		ptr=p1.head;
		while(ptr!=NULL)
		{
			struct node *newnode=(struct node *)malloc(sizeof(struct node));
			int multi=((ptr->data)*(qtr->data))+carry;
			newnode->next=NULL;
			newnode->data=multi%10;
		
			carry=multi/10;
			if(p3.head==NULL)
			{
				p3.head=newnode;
				rtr=p3.head;
			}
			else
			{
				rtr->next=newnode;
				rtr=rtr->next;
			}
			ptr=ptr->next;
			p3.length++;
		}
		if(carry!=0)
		{
			struct node *newnode=(struct node *)malloc(sizeof(struct node));
			newnode->data=carry;
			newnode->next=NULL;
			rtr->next=newnode;
			rtr=rtr->next;	
			p3.length++;
		}	
	}

	qtr=p2.head->next;
	struct node *wtr=p3.head->next,*mtr;

	carry=0;
	int mol;
	while(qtr!=NULL)
	{
			ptr=p1.head;	
			mtr=wtr;
			while(mtr!=NULL && ptr!=NULL)
			{
				mol=mtr->data+(ptr->data*qtr->data)+carry;
				mtr->data=mol%10;
				carry=mol/10;
				mtr=mtr->next;
				ptr=ptr->next;
				
			}
			while(ptr!=NULL)
			{
				struct node *newnode=(struct node *)malloc(sizeof(struct node));
				newnode->next=NULL;
				mol=(ptr->data*qtr->data)+carry;
				newnode->data=mol%10;
				carry=mol/10;
				rtr->next=newnode;
				rtr=rtr->next;
				ptr=ptr->next;
				p3.length++;
			}
		qtr=qtr->next;
		wtr=wtr->next;
	}
		if(carry!=0)
		{
			struct node *newnode=(struct node *)malloc(sizeof(struct node));
			newnode->data=carry;
			newnode->next=NULL;
			rtr->next=newnode;
			rtr=rtr->next;	
			p3.length++;
		}
		reverseLL(&p3.head);
         reverseLL(&p1.head);
	reverseLL(&p2.head);
	return p3;
}


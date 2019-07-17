#include<stdio.h>
#include<stdlib.h>

typedef struct node_tag
{
	int data;
	struct node_tag *next;
} node;
int powr(int a,int b)
{
	int i,j;
	i=a;	
	j=b-1;
	while(j>0)
	{
		i=i*a;
		j--;
	}
	return i;
}
void print(node *l)
{
	if(l!=NULL)
	{
		print(l->next);	
		printf("%d",l->data);
	}
}
void insert(node **l,int a)
{
	int p;
	node *t1,*nptr;
	p=a/10;
	nptr=(node*)malloc(sizeof(node));
	nptr->data=a%10;
	nptr->next=NULL;
	*l=t1=nptr;
	while(p!=0)
	{
		nptr=(node*)malloc(sizeof(node));
		nptr->data=p%10;
		nptr->next=NULL;
		t1=t1->next=nptr;
		p=p/10;
	}
}
void add(node *l1, node *l2)
{
	int sum,carry=0;
	node *head,*tail,*nptr,*p1,*p2;
	p1=l1;
	p2=l2;
	nptr=(node*)malloc(sizeof(node));
	nptr->next=NULL;
	head=tail=nptr;
	if(p1!=NULL && p2!=NULL)
	{
		sum=p1->data+p2->data+carry;
		carry=sum/10;
		tail->data=sum%10;
		p1=p1->next;
		p2=p2->next;
	}
	while(p1!=NULL && p2!=NULL)
	{
		sum=p1->data+p2->data+carry;
		carry=sum/10;
		nptr=(node*)malloc(sizeof(node));
		nptr->next=NULL;
		tail=tail->next=nptr;
		tail->data=sum%10;
		p1=p1->next;
		p2=p2->next;
	}
	if(p1!=NULL)
	{
		while(p1!=NULL)
		{
			sum=p1->data+carry;
			carry=sum/10;
			nptr=(node*)malloc(sizeof(node));
			nptr->next=NULL;
			tail=tail->next=nptr;
			tail->data=sum%10;
			p1=p1->next;
		}
	}
	if(p2!=NULL)
	{
		while(p2!=NULL)
		{
			sum=p2->data+carry;
			carry=sum/10;
			nptr=(node*)malloc(sizeof(node));
			nptr->next=NULL;
			tail=tail->next=nptr;
			tail->data=sum%10;
			p2=p2->next;
		}
	}
	if(carry!=0)
	{
		nptr=(node*)malloc(sizeof(node));
		nptr->next=NULL;
		tail=tail->next=nptr;
		tail->data=carry;
	}
	print(head);
	printf("\n");
	
}
void subtract(node *l1, node *l2)
{
	int sub,brw=0,counter=0;
	node *head,*tail,*nptr,*p1,*p2;
	p1=l1;
	p2=l2;
	nptr=(node*)malloc(sizeof(node));
	nptr->next=NULL;
	head=tail=nptr;
	if(p1!=NULL && p2!=NULL)
	{
		counter++;
		sub=p1->data-p2->data-brw;
		brw=(sub<0)?1:0;
		sub=(brw==1)?(10+sub):sub;
		tail->data=sub;
		p1=p1->next;
		p2=p2->next;
	}
	while(p1!=NULL && p2!=NULL)
	{
		counter++;
		sub=p1->data-p2->data-brw;
		brw=(sub<0)?1:0;
		sub=(brw==1)?(10+sub):sub;
		nptr=(node*)malloc(sizeof(node));
		nptr->next=NULL;
		tail=tail->next=nptr;
		tail->data=sub;
		p1=p1->next;
		p2=p2->next;
	}
	if(p1!=NULL)
	{
		while(p1!=NULL)
		{
			sub=p1->data-brw;
			brw=(sub<0)?1:0;
			sub=(brw==1)?(10+sub):sub;
			nptr=(node*)malloc(sizeof(node));
			nptr->next=NULL;
			tail=tail->next=nptr;
			tail->data=sub;
			p1=p1->next;
		}
	}
	if(p2!=NULL)
	{
		while(p2!=NULL)
		{
			counter++;
			sub=-p2->data-brw;
			brw=(sub<0)?1:0;
			sub=(brw==1)?(10+sub):sub;
			nptr=(node*)malloc(sizeof(node));
			nptr->next=NULL;
			tail=tail->next=nptr;
			tail->data=sub;
			p2=p2->next;
		}
	}
	if(brw==1)
	{
		printf("-");
		node *n;
		n=NULL;
		int c=powr(10,counter);
		insert(&n,c);
		subtract(n,head);
	
	}
	else
	{
		print(head);
	}
	printf("\n");
}	
void multiplication(node *l1, node *l2)
{	
	int m,carry=0,d;
	node *head,*tail,*nptr,*p1,*p2,*p;
	nptr=(node*)malloc(sizeof(node));
	nptr->next=NULL;
	p=head=nptr;
	head->data=0;
	p1=l1;
	while(p1!=NULL)
	{
		tail=p;
		d=p1->data;
		p2=l2;
		carry=0;
		while(p2!=NULL)
		{
			m=d*(p2->data)+carry+tail->data;
			carry=m/10;
			m=m%10;
			tail->data=m;
			if(tail->next==NULL)
			{
				nptr=(node*)malloc(sizeof(node));
				nptr->next=NULL;
				nptr->data=0;
				tail->next=nptr;
			}
			tail=tail->next;
			p2=p2->next;
		}
		if(carry!=0)
		{
			tail->data=carry+tail->data;
		}
		p1=p1->next;
		p=p->next;
	}
	print(head);
	printf("\n");
}
	
			
			
int main()
{
	int e=1;
	while(e==1)
	{
		int a,b,c;
		printf("Which operation you want to perform-\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1 :
				{
					printf("Enter two nos to add\n");
					scanf("%d%d",&a,&b);
					node *l1,*l2,*ad;
					l1=l2=NULL;
					insert(&l1,a);
					print(l1);
					printf("\n");
					insert(&l2,b);
					print(l2);
					printf("\n");
					printf("sub is:\n");
					add(l1,l2);
				}	break;
			case 2 :
				{
					printf("Enter two nos to add\n");
					scanf("%d%d",&a,&b);
					node *l1,*l2,*ad;
					l1=l2=NULL;
					insert(&l1,a);
					print(l1);
					printf("\n");
					insert(&l2,b);
					print(l2);
					printf("\n");
					printf("sub is:\n");
					subtract(l1,l2);
				}	break;
			case 3 :
				{
					printf("Enter two nos to add\n");
					scanf("%d%d",&a,&b);
					node *l1,*l2,*ad;
					l1=l2=NULL;
					insert(&l1,a);
					print(l1);
					printf("\n");
					insert(&l2,b);
					print(l2);
					printf("\n");
					printf("multiplication is:\n");
					multiplication(l1,l2);
				}	break;
			default  : 	printf("Enter correct option\n");
					break;	
		}
		printf("press 0 to exit\npress 1 to continue\n");
		scanf("%d",&e);
	}
	return 0;
}

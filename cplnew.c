#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum {NEGATIVE,POSITIVE} flag;
typedef struct node_type {
	int data;
	struct node_type * next;
}node;

typedef struct bigInt_type {
	node * tail;
	node* start;
}bigInt;

void Init(bigInt * num){
	num->tail=num->start=NULL;
}

node * makenode(node * num,int n){
	num=(node*)malloc(sizeof(node));
	num->next=NULL;
	num->data=n;
	return num;
}

void createInt(bigInt * num1)
{
	printf("please enter number\n");
	int n,i,c,t;
	char s[310];
	node * num;
	Init(num1);
	scanf("%s",s);
	i=strlen(s);
	i--;
	while(i>=0){
		c=0;
		n=0;
		t=1;
		while(c<9 && i>=0)
		{
			n=((int)s[i]-48)*t+n;
			i--;
			t=t*10;
			c++;
		}
		num=makenode(num,n);
		if(num1->start==NULL){
			num1->start=num1->tail=num;
		}
		else{
			(num1->tail)->next=num;
			num1->tail=num;
		}
	}
	
}

void printnode(node * num){
	node * temp= num;
	if(temp!=NULL){
		printnode(temp->next);
		printf("%d\n",temp->data);
	}
}


void print(bigInt * num1){
	node*num=num1->start;
	printnode(num);
	printf("\n");
}

bigInt add(bigInt *l1, bigInt *l2,bigInt *b)
{
	Init(b);
	int sum,carry=0;
	node *num,*p1,*p2;
	p1=l1->start;
	p2=l2->start;
	while(p1!=NULL && p2!=NULL)
	{
		sum=p1->data+p2->data+carry;
		carry=sum/1000000000;
		sum=sum%1000000000;
		num=makenode(num,sum);
		if(b->start==NULL){
			b->start=b->tail=num;
		}
		else{
			(b->tail)->next=num;
			b->tail=num;
		}
		p1=p1->next;
		p2=p2->next;
	}
	if(p1!=NULL)
	{
		while(p1!=NULL)
		{
			sum=p1->data+carry;
			carry=sum/1000000000;
			sum=sum%1000000000;
			num=makenode(num,sum);
			if(b->start==NULL){
				b->start=b->tail=num;
			}
			else{
				(b->tail)->next=num;
				b->tail=num;
			}
			p1=p1->next;
		}
	}
	if(p2!=NULL)
	{
		while(p2!=NULL)
		{
			sum=p2->data+carry;
			carry=sum/1000000000;
			sum=sum%1000000000;
			num=makenode(num,sum);
			if(b->start==NULL){
				b->start=b->tail=num;
			}
			else{
				(b->tail)->next=num;
				b->tail=num;
			}
			p2=p2->next;

		}
	}
	if(carry!=0)
	{
		num=makenode(num,carry);
		(b->tail)->next=num;
		b->tail=num;
	}
	return * b;
	
	
}
flag subtract(bigInt *l1, bigInt *l2,bigInt *b)
{
	Init(b);
	flag sign=POSITIVE;
	int sub,brw=0;
	node *num,*p1,*p2;
	p1=l1->start;
	p2=l2->start;
	while(p1!=NULL && p2!=NULL)
	{
		sub=p1->data-p2->data-brw;
		brw=(sub<0)?1:0;
		sub=(brw==1)?(1000000000+sub):sub;
		num=makenode(num,sub);
			if(b->start==NULL){
				b->start=b->tail=num;
			}
			else{
				(b->tail)->next=num;
				b->tail=num;
			}
		p1=p1->next;
		p2=p2->next;
	}
	if(p1!=NULL )
	{
		while(p1!=NULL)
		{
			sub=p1->data-brw;
			brw=(sub<0)?1:0;
			sub=(brw==1)?(1000000000+sub):sub;
			num=makenode(num,sub);
			if(b->start==NULL){
				b->start=b->tail=num;
			}
			else{
				(b->tail)->next=num;
				b->tail=num;
			}
			p1=p1->next;
		}
	}
	if(brw==1 || p2!=NULL)
	{
		sign=NEGATIVE;
		
		subtract(l2,l1,b);
	
	}
	return sign;
}	
bigInt  multiplication(bigInt *l1, bigInt *l2,bigInt *b)
{	
	Init(b);
	long int m,carry=0,d;
	node *num,*p1,*p2,*p,*t;
	p1=l1->start;
	p=b->tail;
	while(p1!=NULL)
	{
		d=p1->data;
		p2=l2->start;
		carry=0;
		while(p2!=NULL)
		{
			if(p==NULL){
				num=makenode(num,0);
				if(b->start==NULL){
					t=p=b->start=b->tail=num;
				}
				else{
					(b->tail)->next=num;
					p=b->tail=num;
					if(t==NULL)
					{
						t=p;
					}
				}
			}
			m=d*(p2->data)+carry+p->data;
			carry=m/1000000000;
			m=m%1000000000;
			p->data=m;
			p=p->next;
			p2=p2->next;
		}
		if(carry!=0)
		{
				num=makenode(num,carry);
				if(b->start==NULL){
					p=b->start=b->tail=num;
				}
				else{
					(b->tail)->next=num;
					p=b->tail=num;
				}
		}
		p1=p1->next;
		p=t=t->next;
	}
	return * b;
}

int main()
{
	int e=1;
	flag sign=POSITIVE;
	while(e==1)
	{
		int a,b,c;
		printf("Which operation you want to perform-\n1.Addition\n2.Subtraction\n3.Multiplication\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1 :
				{
					bigInt a,b,sum;
					createInt(&a);
					print(&a);
					createInt(&b);
					print(&b);
					printf("addition is:\n");
					sum=add(&a,&b,&sum);
					print(&sum);

				}	break;
			case 2 :
				{
					bigInt a,b,diff;
					createInt(&a);
					print(&a);
					createInt(&b);
					print(&b);
					printf("subtraction is:\n");
					sign=subtract(&a,&b,&diff);
					if(sign==POSITIVE){
						print(&diff);
					}
					else{
						printf("-");
						print(&diff);
					}
				}	break;
			case 3 :
				{
					bigInt a,b,mul;
					createInt(&a);
					print(&a);
					createInt(&b);
					print(&b);
					printf("multiplication  is:\n");
					mul=multiplication(&a,&b,&mul);
					print(&mul);
				}	break;
			default  : 	printf("Enter correct option\n");
					break;	
		}
		printf("press 0 to exit\npress 1 to continue\n");
		scanf("%d",&e);
	}
	return 0;
}

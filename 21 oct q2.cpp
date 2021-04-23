#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *lptr;
	struct node *rptr;
};
struct stack{
	int top;
	struct node *ptr;
	struct stack *top;
};
struct node create(struct node **root,int data);
void stack(struct stack **s,struct node *ptr);
void preorder(struct node **root);
int main()
{
	struct stack *s;
	s->top=NULL;
	int ch ,dat;
	struct node *root=NULL;
	struct node *NODE=NULL;
	struct node *in=NULL;
	while (1)
	{
		printf("1.create\n");
		printf("2.preorder\n");
		printf("3.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data \n");
				scanf("%d",&dat);
				create(&root,dat);
				break;
			case 2:
				preorder(&root);
				printf("\n");
				break;
			case 3:
				exit(1);
				break;
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
struct node create(struct node **root,int data)
{
	struct node *newnode,*parent,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->lptr=NULL;
	newnode->rptr=NULL;
	if (*root==NULL)
	{
		*root=newnode;
	}
	else 
	{
		ptr=*root;
		parent=*root;
		while(ptr!=NULL)
		{
			parent=ptr;
			if (data<ptr->data)
			{
				ptr=ptr->lptr;
			}
			else  
			{
				ptr=ptr->rptr;
			}
		}
	if (data<parent->data)
	{
		parent->lptr=newnode;
	}
	else
	{
		parent->rptr=newnode;
	}
  }
}
void preorder(struct node **root)
{
	struct node *ptr=*root;
	while (ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		if (ptr->right!=NULL)
		{
			push(ptr->right);
		}
		if (ptr->left!=NULL)
		{
			ptr=ptr->left;
		}
		else 
		{
			ptr=pop();
		}
	}
}
void stack(struct stack **s,struct node *ptr)
{
	struct stack *newnode=(struct stack*)malloc(sizeof(struct stack));
	newnode->ptr=ptr;
	newn
}

#include<stdio.h>
#include<stdlib.h>
#define N 5
struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct stack{
	struct node *ptr;
	struct stack *next;
};
struct stack *top=NULL;
void create(struct node **root,int data);
void push(struct stack **ptr,struct node *pt);
struct stack *pop(struct stack **ptr);
void display(struct node *root);
void preorder(struct node **root);
int main()
{
	int ch,data;
	struct node *root=NULL;
	while (1)
	{
		printf("1.create\n");
		printf("2.display\n");
		printf("3.preorder non recursive\n");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				printf("enter the data\n");
				scanf("%d",&data);
				create(&root,data);
				break;
			case 2:
				display(root);
				printf("\n");
				break;
			case 3:
				preorder(&root);
				break;
		}
		
	}
	return 0;
}
void create(struct node **root,int data)
{
	struct node *newnode,*parent,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	if (*root==NULL)
	{
		*root=newnode;
	}
	else 
	{
		ptr=*root;
		while (ptr!=NULL)
		{
			parent=ptr;
			if (data<ptr->data)
			{
				ptr=ptr->left;
			}
			else
			{
				ptr=ptr->right;
			}
		}
		if (data<parent->data)
		{
			parent->left=newnode;
		}
		else 
		{
			parent->right=newnode;
		}
	}
}
void display(struct node *root)
{
	if (root!=NULL)
	{
		printf("\n%d",root->data);
		display(root->left);
		display(root->right);
	}
}
void push(struct stack **ptr,struct node *pt)
{
		struct stack *newnode=(struct stack*)malloc(sizeof(struct stack));
		newnode->ptr=pt;
		newnode->next=top;
		top=newnode;
}
struct node pop(struct node *ptr)
{
	if (top==NULL)
	{
		printf("underflow\n");
	}
	else 
	{
		struct stack *pt;
		struct stack *temp=pt->ptr;
		top=top->next;
		return temp;
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

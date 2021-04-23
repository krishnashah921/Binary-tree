//1905921
//Krishna Kumar Shah 28th October 
#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};
void create(struct node **root,int data);
void display(struct node *root);
void inorder(struct node *root);
void zerodegree(struct node **root,int value);
void degreeone(struct node **root,int value);
void degreetwo(struct node **root,int value);
int main()
{
	struct node *root=NULL;
	int ch,data,value;
	while (1)
	{
		printf("1.create\n");
		printf("2.display\n");
		printf("3.0 degree node\n");
		printf("4.1 degree node\n");
		printf("5.2 degree node\n");
		printf("6.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data\n");
				scanf("%d",&data);
				create(&root,data);
				break;
			case 2:
				display(root);
				printf("\n");
				//preorder
				break;
			case 3:
				printf("enter the value to be deleted\n");
				scanf("%d",&value);
				zerodegree(&root,value);
				break;
			case 4:
				printf("enter the value to be deleted\n");
				scanf("%d",&value);
				degreeone(&root,value);
				break;
			case 5:
				printf("enter the value to be deleted\n");
				scanf("%d",&value);
				degreetwo(&root,value);
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
void create(struct node **root,int data)
{
	struct node *newnode,*parent,*temp=*root;
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
		while (temp!=NULL)
		{
			parent=temp;
			if (data<temp->data)
			{
				temp=temp->left;
			}
			else 
			{
				temp=temp->right;
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
		printf("%d\t",root->data);
		display(root->left);
		display(root->right);
	}
}
void zerodegree(struct node **root,int value)
{
	struct node *parent,*ptr;
	parent=NULL;
	ptr=*root;
	if (ptr==NULL)
	{
		printf("list is empty\n");
	}
	else if (ptr->data==value) 
	{
		*root=NULL;
		free(ptr);
	}
	else 
	{
		while (ptr->data!=value)
		{
			parent=ptr;
			if (value<ptr->data)
			{
				ptr=ptr->left;
			}
			else 
			{
				ptr=ptr->right;
			}
		}
		if (value<parent->data)
		{
			parent->left=NULL;
			free(ptr);
		}
		else
		{
			parent->right=NULL;
			free(ptr);
		}
	}
}
void degreeone(struct node **root,int value)
{
	struct node *parent,*ptr,*temp;
	parent=NULL;
	ptr=*root;
	if (ptr==NULL)
	{
		printf("no record\n");
	}
	else if (ptr->data==value)
	{
		if (ptr->left!=NULL)
		{
			temp=ptr->left;
		}
		else 
		{
			temp=ptr->right;
		}
		*root=temp;
	}
	else 
	{
		while (ptr->data !=value)
		{
			parent=ptr;
			if (value<ptr->data)
			{
				ptr=ptr->left;
			}
			else 
			{
				ptr=ptr->right;
			}
		}
		if (ptr->left!=NULL)
		{
			temp=ptr->left;
		}
		else 
		{
			temp=ptr->right;
		}
		if (temp->data<parent->data)
		{
			parent->left=temp;
		}
		else 
		{
			parent->right=temp;
		}
	}
}
void inorder(struct node *root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void degreetwo(struct node **root,int value)
{
	struct node *parent=NULL,*ptr=*root,*temp,*save,*succossor;
	if (ptr==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		while (ptr->data !=value)
		{
			parent=ptr;
			if (value<ptr->data)
			{
				ptr=ptr->left;
			}
			else 
			{
				ptr=ptr->right;
			}
		}
		temp=ptr->right;
		save=ptr;
		while (temp->left!=NULL)
		{
			save=temp;
			temp=temp->left;
		}
		succossor=temp;
		zerodegree(root,succossor->data);
		if (parent!=NULL)
		{
			if (ptr==parent->left)
			{
				parent->left=temp;
			}
			else 
			{
				parent->right=temp;
			}
		}
		else 
		{
			*root=temp;
			succossor->left=ptr->left;
			succossor->right=ptr->right;
			
		}
	}
}

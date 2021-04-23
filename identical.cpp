#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *lptr;
	struct node *rptr;
};
void create(struct node **root,int data);
struct node *display(struct node *NODE);
int check(struct node *root1,struct node *root2);
int main()
{
	int ch ,dat,k;
	struct node *root1=NULL,*root2;
	struct node *NODE=NULL;
	while (1)
	{
		printf("1.create for root 1\n");
		printf("2.create for root 2\n");
		printf("3.display\n");
		printf("4.check whether it is identical or not\n");
		printf("5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data \n");
				scanf("%d",&dat);
				create(&root1,dat);
				break;
			case 2:
				printf("enter the data \n");
				scanf("%d",&dat);
				create(&root2,dat);
				break;
			case 3:
				NODE=root1;
				display(NODE);
				printf("\n\n");
				printf("\n");
				display(root2);
				printf("\n");
				break;
			case 4:
				 k=check(root1,root2);
				//printf("%d\n",check(root1,root2));
				break;
			case 5:
				exit(1);
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
void create(struct node **root,int data)
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
struct node *display(struct node *NODE)
{
//	preorder print 
	if (NODE!=NULL)
	{
		printf("\n%d",NODE->data);
		display(NODE->lptr);
		display(NODE->rptr);
	}
}
int check(struct node *root1,struct node *root2)
{
	if (root1==NULL && root2==NULL)
	{
		return 1;
	}
	if (root1!=NULL && root2!=NULL)
	{
		if (root1->data==root2->data && check(root1->lptr,root2->lptr) && check(root1->rptr,root2->rptr))
		{
			return 1;
		}
	}
	return 0;
}

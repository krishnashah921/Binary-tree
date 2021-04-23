#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *lptr;
	struct node *rptr;
};
void create(struct node **root,int data);
struct node *preorder(struct node *NODE);
struct node *inorder(struct node *in);
struct node *postorder(struct node *post);
int main()
{
	int ch ,dat;
	struct node *root=NULL;
	struct node *NODE=NULL;
	struct node *in=NULL;
	struct node *post;
	while (1)
	{
		printf("1.create\n");
		printf("2.preorder\n");
		printf("3.exit\n");
		printf("4.inorder\n");
		printf("5.postorder\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data \n");
				scanf("%d",&dat);
				create(&root,dat);
				break;
			case 2:
				NODE=root;
				preorder(NODE);
				printf("\n");
				break;
			case 3:
				exit(1);
				break;
			case 4:
				in=root;
				inorder(in);
				printf("\n");
				break;
			case 5:
				post=root;
				postorder(post);
				printf("\n");
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
struct node *preorder(struct node *NODE)
{
//	preorder print 
	if (NODE!=NULL)
	{
		printf("\n%d",NODE->data);
		preorder(NODE->lptr);
		preorder(NODE->rptr);
	}
}
struct node *inorder(struct node *in)
{
	if (in!=NULL)
	{
		inorder(in->lptr);
		printf("\n%d",in->data);
		inorder(in->rptr);
	}
}
struct node *postorder(struct node *post)
{
	if (post!=NULL)
	{
		postorder(post->lptr);
		postorder(post->rptr);
		printf("\n%d",post->data);
	}
}

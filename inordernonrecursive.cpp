//inordernonrecursive
#include<stdio.h>
#include<stdlib.h>
#define N 10
struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node *arr[100];
struct node *topp();
int top=-1;
void create(struct node **root,int data);
void display(struct node *root);
struct node *pop();
void push(struct tree **root);
void postorder(struct node **root);
void inordernonrecursive(struct node *); 
int main()
{
	int ch,data;
	struct node *root=NULL;
	while (1)
	{
		printf("1.create\n");
		printf("2.display\n");
		printf("3.postorder non recursive\n");
		printf("4.inorder non recursive\n");
		printf("5.exit\n");
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
				postorder(&root);
				printf("\n");
				break;
			case 4:
				inordernonrecursive(root);
				printf("\n");
				break;
			case 5:
				exit(1);
			default:
				printf("invalid\n");
		}
		
	}
	return 0;
}
void push(struct node **root)
{
	top=top+1;
	arr[top]=*root;
}
struct node *topp()
{
	return arr[top];
}
struct node *pop()
{
	struct node *temp=arr[top];
	top=top-1;
	return temp;
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
		display(root->left);
		display(root->right);
		printf("\n%d",root->data);
	}
}
void postorder(struct node **root)
{
	struct node *current=*root;
	while (1)
	{
		if (current!=NULL)
		{
			push(&current);
			current=current->left;
		}
		else 
		{
			if (top==-1)
			{
				exit(1);
				break;
			}
			else 
			{
				if (topp()->right==NULL)
				{
					current=pop();
					printf("%d\t",current->data);
					while (current==topp()->right)
					{
						printf("%d\t",topp()->data);
						current=pop();
					}
				}
				if (top!=-1)
				{
					current=topp()->right;
				}
				else 
				{
					current=NULL;
				}
			}
		}
	}
}
void inordernonrecursive(struct node *tree) 
{ 
    struct node *current, *pre; 
  
    if (tree == NULL) 
        return; 
  
    current = tree; 
    while (current != NULL) 
    { 
  
        if (current->left == NULL) 
        { 
            printf("%d\t ", current->data); 
            current = current->right; 
        } 
        else 
        { 
  			pre = current->left; 
               while (pre->right != NULL && pre->right != current) 
               pre = pre->right; 
  
           
            if (pre->right == NULL) 
            { 
                pre->right = current; 
                current = current->left; 
            }
            else 
            { 
                pre->right = NULL; 
                printf("%d\t ", current->data); 
                current = current->right; 
            } 
        } 
    } 
} 


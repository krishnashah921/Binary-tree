#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *tree;
void create(struct node *);
struct node *insert(struct node *,int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void inordernonrecursive(struct node *); 
void preordernonrecursive(struct node *); 
void printGivenLevel(struct node* , int );
int height(struct node* );
void LevelOrder(struct node* );

int main()
{
	int option,val;
	struct node *ptr;
	create(tree);
	do
	{
		printf("\n1.Insert element\n2.Inorder Traversal\n3.Postorder Traversal\n4.Preorder Traversal\n5.Inorder Nonrecursive\n6.Preorder Nonrecursive\n7.Level Order Traversal\n8.Exit\n");
		printf("Enter your option\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the value of new node:");
				scanf("%d",&val);
				tree=insert(tree,val);
				break;
			case 2:
				printf("\nThe elements of the tree in Inorder traversal are:\n");
				inorder(tree);
				break;
			case 3:
				printf("\nThe elements of the tree in Postorder traversal are:\n");
				postorder(tree);
				break;
			case 4:
				printf("\nThe elements of the tree in Preorder traversal are:\n");
				preorder(tree);
				break;
			case 5:
				printf("\nThe elements of the tree in Inorder traversal are:\n");
				inordernonrecursive(tree);
				break;
			case 6:
				printf("\nThe elements of the tree in Preorder traversal are:\n");
				preordernonrecursive(tree);
				break;
			case 7:
				printf("\nThe elements of the tree in Levelorder traversal are:\n");
				LevelOrder(tree);
				break;
		}
	}while(option!=8);
	return 0;
}

void create(struct node *tree)
{
	tree=NULL;
}

struct node *insert(struct node *tree,int val)
{
	struct node *ptr,*nodeptr,*parentptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	if(tree==NULL)
	{
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parentptr=nodeptr;
			if(val<nodeptr->data)
				nodeptr=nodeptr->left;
			else
				nodeptr=nodeptr->right;
		}
		if(val<parentptr->data)
			parentptr->left=ptr;
		else
			parentptr->right=ptr;
	}
	return tree;
}

void inorder(struct node *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->left);
		printf("%d\t",tree->data);
		inorder(tree->right);
	}
}

void postorder(struct node *tree)
{
	if(tree!=NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d\t",tree->data);
	}
}

void preorder(struct node *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		preorder(tree->left);
		preorder(tree->right);
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

void preordernonrecursive(struct node *tree)
{
	struct node *current, *pre; 
	
	while (tree!=NULL) 
    	{ 
        if (tree->left == NULL) 
        { 
            printf("%d\t", tree->data ); 
            tree = tree->right; 
        } 
        else
        { 
            struct node* current = tree->left; 
            while (current->right && current->right != tree) 
                current = current->right; 
  
            if (current->right == tree) 
            { 
                current->right = NULL; 
                tree = tree->right; 
            } 
  
            else
            { 
                printf("%d\t", tree->data); 
                current->right = tree; 
                tree = tree->left; 
            } 
        } 
    } 
}
void printGivenLevel(struct node* tree, int level)
{
    if (tree == NULL)
        return;
    if (level == 1)
        printf("%d\t", tree->data);
    else if (level > 1)
    {
        printGivenLevel(tree->left, level-1);
        printGivenLevel(tree->right, level-1);
    }
}
int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {

        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return(lheight+1);

        else return(rheight+1);
    }
}

void LevelOrder(struct node* tree)
{
    int h = height(tree);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(tree, i);
}



//Write a program for *Inorder Traversal* of a Binary Tree.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
} node;

node* createnode();
void traverse_inorder (node*);


node* createnode()
{
	int data;
	node *temp;
	temp=(node*)malloc(sizeof(node));

	if(temp==NULL)
	{
		printf("Memory not allocated\n");
		return NULL;
	}

	printf("Enter data(-1 for no node):\n");
	scanf("%d",&data);

	if(data==-1)
		return NULL;

	temp->data=data;
	printf("Enter left child of %d:\n",data );
	temp->left=createnode();
	printf("Enter right child of %d:\n",data );
	temp->right=createnode();

	return temp;

}

void traverse_inorder (node *temp)
{
	if(temp!=NULL)
	{
		traverse_inorder(temp->left);
		printf("%d ",temp->data);
		traverse_inorder(temp->right);
	}
	else
		return;
}

int main()
{
	node* root;
	root=createnode();
	printf("\nInorder tranversal is:\n");
	traverse_inorder(root);
	
	return 0;
}
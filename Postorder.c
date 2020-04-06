//Write a program for *Postorder Traversal* of a Binary Tree.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
} node;

node* createnode();
void traverse_postorder (node*);


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

void traverse_postorder (node* temp)
{
	if(temp!=NULL)
	{
		traverse_postorder(temp->left);
		traverse_postorder(temp->right);
		printf("%d ",temp->data );
	}
	else
		return;
}


int main()
{
	node* root;
	root=createnode();
	printf("\nPostorder tranversal is:\n");
	traverse_postorder(root);
	
	return 0;
}
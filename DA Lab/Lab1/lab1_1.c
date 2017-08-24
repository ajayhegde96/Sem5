#include <stdio.h>
#include <stdlib.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree *createtree( struct tree *root,int data)
{
	if(root==NULL){
		struct tree * root=(struct tree *)malloc(sizeof(struct tree ));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(data==root->data){
		printf("Data Found\n");
		return root;
	}
	if(data<root->data){
		root->left=createtree(root->left,data);
	}
	if(data>root->data){
		root->right=createtree(root->right,data);
	}
	return root;
}
void inorder(struct tree * root)
{
	if(root!=NULL){
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	}
}
void preorder(struct tree * root)
{
	if(root!=NULL){
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
	}
}

void postorder(struct tree * root)
{
	if(root!=NULL){
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
	}
}

int main()
{
	struct tree * root=NULL;
	int data;
	printf("\n Enter data for tree ");
	scanf("%d",&data);
	root=createtree(root,data);
	int n;
	while(1){
		printf("\n Continue? ");
		scanf("%d",&n);
		if(n!=1)
			break;
		printf("\n Enter data for tree ");
	scanf("%d",&data);
	root=createtree(root,data);
	}
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	postorder(root);
	
	return 0;
}

#include <stdio.h>
struct node
{
    int data;
    struct node* left, *right;
};
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
int max(int a, int b)
{
  return (a >= b)? a: b;
}
int diameterOpt(struct node *root, int* height)
{
  int lh = 0, rh = 0;
  
  int ldiameter = 0, rdiameter = 0;
  
  if(root == NULL)
  {
    *height = 0;
     return 0;
  }  
  ldiameter = diameterOpt(root->left, &lh);
  rdiameter = diameterOpt(root->right, &rh);
  
  *height = max(lh, rh) + 1;
  
  return max(lh + rh + 1, max(ldiameter, rdiameter));
}
int main()
{
 
  struct node *root=NULL;
	int dir;
	while(1)
	{
		printf("Enter the data\n");
		int data;
		scanf("%d",&data);
		if(root==NULL)
		{
			root=(struct node*)malloc(sizeof(struct node));
			root->data=data;
			root->left=NULL;
			root->right=NULL;
			printf("Do you want to continue?\n");
			int check;
			scanf("%d",&check);
			if(check==0)
				break;
			else
				continue;
		}
		struct node *parent;
		struct node *child=root;
		while(child!=NULL)
		{
			printf("Enter the direction\n");
			scanf("%d",&dir);
			if(dir==0)
			{
				parent=child;
				child=child->left;
			}
			else
			{
				parent=child;
				child=child->right;
			}
		}
		// printf("enter the direction\n");
		// scanf("%d",&dir);
		if(parent->left==NULL &&dir==0)
		{
			struct node *p=(struct node *)malloc(sizeof(struct node));
			p->left=NULL;
			p->right=NULL;
			parent->left=p;
			p->data=data;
		}
		else
		{
			struct node *p=(struct node *)malloc(sizeof(struct node));
			p->left=NULL;
			p->right=NULL;
			parent->right=p;
			p->data=data;

		}
		printf("do you want to continue?\n");
		scanf("%d",&dir);
		if(dir==0)
			break;
	}
  int height;
  printf("Diameter of the given binary tree is %d\n", diameterOpt(root,&height));
  return 0;
}

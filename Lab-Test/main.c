#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int val;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode* insert(TreeNode *, int);
void in_order(TreeNode *);
void root_to_leaf(TreeNode *, int *, int);

int main()
{
	TreeNode *root = NULL;

	printf("Enter number of elements: ");
	int size;
	scanf("%d", &size);
	printf("\n");

	printf("Enter %d elements: ", size);
	for(int i=0; i<size; i++)
	{
		int n;
		scanf("%d", &n);
		root = insert(root, n);
	}
	printf("\n");

	printf("\nInorder traversal\n");
	in_order(root);
	printf("\n");

	printf("\nRoot to leaf paths\n");
	int path[size];
	root_to_leaf(root, path, 0);
	printf("\n");	

	return 0;
}

TreeNode *insert(TreeNode *root, int n)
{
	if (root == NULL)
	{
		TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
		temp->val = n;
		temp->left = NULL;
		temp->right = NULL;

		return temp;
	}

	if (n < root->val)
	{
		root->left = insert(root->left, n);
	}
	if (n > root->val)
	{
		root->right = insert(root->right, n);
	}

	return root;
}

void in_order(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}

	in_order(root->left);
	printf("%d ", root->val);
	in_order(root->right);
}

void root_to_leaf(TreeNode *root, int *curr_path, int index)
{
	if (root == NULL)
	{
		return;
	}

	curr_path[index++] = root->val;

	if(root->left == NULL && root->right == NULL)
	{
		for (int i=0; i<index; i++)
		{
			printf("%d ", curr_path[i]);
		}
		printf("\n");
		return;
	}

	root_to_leaf(root->left, curr_path, index);
	root_to_leaf(root->right, curr_path, index);
}
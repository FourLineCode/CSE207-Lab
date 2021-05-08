#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int val;
	struct TreeNode *left, *right;
} TreeNode;

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
		root->left = insert(root->left, n);
	if (n > root->val)
		root->right = insert(root->right, n);

	return root;
}

int height(TreeNode* root)
{
	int left, right;
    if (root == NULL) 
        return 0;
	else
	{
		left = height(root->left);
        right = height(root->right);
	}
	
    return left > right ? left + 1 : right + 1;
}

int main()
{
	TreeNode *root = NULL;
	int size;
	scanf("%d", &size);

	for(int i=0; i<size; i++)
	{
		int n;
		scanf("%d", &n);
		root = insert(root, n);
	}

	printf("Height: %d\n", height(root));
	return 0;
}

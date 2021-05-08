int findBF(struct Node *root)
{
	if(root == NULL)
		return 0;

	int left = height(root->left);
	int right = height(root->right);

	return left - right;
}

int height(struct Node *root)
{
	if (root == NULL)
		return 0;

	int left =  height(root->left);
	int right = height(root->right);

	if (left > right)
		return 1 + left;
	else
		return 1 + right;
}


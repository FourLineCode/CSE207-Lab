void print(TreeNode *root, int n)
{
	if (root == NULL)
		return;
	for(int i=0; i<n; i++)
		printf("\t");

	printf("%d. %d\n", n+1, root->val);
	print(root->left, n+1);
	print(root->right, n+1);
}
#include <iostream>
using namespace std;

typedef struct TreeNode
{
	int val;
	TreeNode *left, *right;
} TreeNode;

TreeNode *insert(TreeNode *, int);
void preOrder(TreeNode *);
void inOrder(TreeNode *);
void postOrder(TreeNode *);
TreeNode *search(TreeNode *, int);
TreeNode *findMin(TreeNode *);
TreeNode *findMax(TreeNode *);
TreeNode *deleteNode(TreeNode *, int);

int main()
{
	TreeNode *root = NULL;

	bool running = true;

	while (running)
	{
		printf("======Menu======\n");
		printf("1. Insert\n");
		printf("2. Preorder\n");
		printf("3. Inorder\n");
		printf("4. Postorder\n");
		printf("5. Search\n");
		printf("6. Find min\n");
		printf("7. Find max\n");
		printf("8. Delete\n");
		printf("9. Exit\n");

		int res;
		printf("Enter response: ");
		cin >> res;

		int n;
		switch (res)
		{
		case 1:
		{
			printf("Enter element: ");
			cin >> n;
			root = insert(root, n);
			break;
		}
		case 2:
		{
			printf("Pre-order elements: ");
			preOrder(root);
			printf("\n");
			break;
		}
		case 3:
		{
			printf("In-order elements: ");
			inOrder(root);
			printf("\n");
			break;
		}
		case 4:
		{
			printf("Post-order elements: ");
			postOrder(root);
			printf("\n");
			break;
		}
		case 5:
		{
			printf("Enter element: ");
			cin >> n;
			TreeNode *found = search(root, n);
			if (found == NULL)
				printf("%d was not found\n");
			else
				printf("%d was found\n");
			break;
		}
		case 6:
		{
			TreeNode *found = findMin(root);
			if (found == NULL)
				printf("Tree is empty\n");
			else
				printf("Min value: %d\n", found->val);
			break;
		}
		case 7:
		{
			TreeNode *found = findMax(root);
			if (found == NULL)
				printf("Tree is empty\n");
			else
				printf("Max value: %d\n", found->val);
			break;
		}
		case 8:
		{
			printf("Enter element: ");
			cin >> n;
			root = deleteNode(root, n);
			break;
		}
		case 9:
		{
			printf("Program exited successfully!\n");
			running = false;
			break;
		}
		default:
		{
			printf("Invalid response!\n");
			running = false;
			break;
		}
		}
	}
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

void preOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	printf("%d ", root->val);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	inOrder(root->left);
	printf("%d ", root->val);
	inOrder(root->right);
}

void postOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->val);
}

TreeNode *search(TreeNode *root, int n)
{
	if (root == NULL || root->val == n)
		return root;

	if (n < root->val)
		return search(root->left, n);

	return search(root->right, n);
}

TreeNode *findMin(TreeNode *root)
{
	TreeNode *curr = root;

	while (curr != NULL && curr->left != NULL)
	{
		curr = curr->left;
	}

	return curr;
}

TreeNode *findMax(TreeNode *root)
{
	TreeNode *curr = root;

	while (curr != NULL && curr->right != NULL)
	{
		curr = curr->right;
	}

	return curr;
}

TreeNode *deleteNode(TreeNode *root, int n)
{
	if (root == NULL)
		return root;

	if (n < root->val)
		root->left = deleteNode(root->left, n);
	else if (n > root->val)
		root->right = deleteNode(root->right, n);
	else
	{
		if (root->left == NULL)
		{
			TreeNode *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode *temp = root->left;
			free(root);
			return temp;
		}

		TreeNode *temp = findMin(root->right);
		root->val = temp->val;
		root->right = deleteNode(root->right, temp->val);
	}
	return root;
}

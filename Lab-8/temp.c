#include <stdio.h>

#define MAX 100
int size;

void init_matrix(int arr[][MAX]);
void insert_vertex(int arr[][MAX]);
void remove_vertex(int arr[][MAX], int);
void insert_edge(int arr[][MAX], int, int);
void remove_edge(int arr[][MAX], int, int);
void display_matrix(int arr[][MAX]);

int main()
{
	int adj[MAX][MAX];
	init_matrix(adj);

	printf("Enter number of vertices: ");
	scanf("%d", &size);

	if (size > MAX)
	{
		printf("Size cannot be more that 100!\n");
		return 0;
	}

	while (1)
	{
		printf("\nGraph represented as Adjacency Matrix\n");
		printf("======== MENU ========\n");
		printf("1. Insert vertex\n");
		printf("2. Insert edge\n");
		printf("3. Remove vertex\n");
		printf("4. Remove edge\n");
		printf("5. Display matrix\n");
		printf("6. Exit\n");

		printf("\nEnter choice > ");
		char choice;
		scanf("%s", &choice);

		switch (choice)
		{
		case '1':
		{
			insert_vertex(adj);
			break;
		}
		case '2':
		{
			int src, dest;
			printf("Enter source vertex: ");
			scanf("%d", &src);
			printf("Enter destination vertex: ");
			scanf("%d", &dest);
			insert_edge(adj, src, dest);
			break;
		}
		case '3':
		{
			int vertex;
			printf("Enter vertex to remove: ");
			scanf("%d", &vertex);
			remove_vertex(adj, vertex);
			break;
		}
		case '4':
		{
			int src, dest;
			printf("Enter source vertex: ");
			scanf("%d", &src);
			printf("Enter destination vertex: ");
			scanf("%d", &dest);
			remove_edge(adj, src, dest);
			break;
		}
		case '5':
		{
			display_matrix(adj);
			break;
		}
		case '6':
		{
			printf("\nProgram exited!\n");
			return 0;
		}
		default:
		{
			printf("\nInvalid choice!\n");
		}
		}
	}

	return 0;
}

void init_matrix(int arr[][MAX])
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			arr[i][j] = 0;
}

void display_matrix(int arr[][MAX])
{
	printf("=== Adjacency Matrix ===\n");
	for (int i = 0; i < size; i++)
	{
		if (i < 10)
			printf("(%d) -> ", i);
		else
			printf("(%d)-> ", i);

		for (int j = 0; j < size; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void insert_vertex(int arr[][MAX])
{
	if (size + 1 <= MAX)
		size++;
}

void remove_vertex(int arr[][MAX], int index)
{
	if (index < 0 || index >= size)
	{
		printf("Invalid vertex\n");
		return;
	}

	for (int i = index; i < size - 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = arr[i + 1][j];
		}
	}

	for (int i = index; i < size - 1; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[j][i] = arr[j][i + 1];
		}
	}

	for (int i = 0; i < size; i++)
	{
		arr[i][size - 1] = 0;
		arr[size - 1][i] = 0;
	}

	size--;
}

void insert_edge(int arr[][MAX], int src, int dest)
{
	if (src < 0 || src >= size)
	{
		printf("Invalid source vertex\n");
		return;
	}

	if (dest < 0 || dest >= size)
	{
		printf("Invalid desrination vertex\n");
		return;
	}

	arr[src][dest] = 1;
	arr[dest][src] = 1;
}

void remove_edge(int arr[][MAX], int src, int dest)
{
	if (src < 0 || src >= size)
	{
		printf("Invalid source vertex\n");
		return;
	}

	if (dest < 0 || dest >= size)
	{
		printf("Invalid desrination vertex\n");
		return;
	}

	arr[src][dest] = 0;
	arr[dest][src] = 0;
}
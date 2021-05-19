/*

This is an implementation of Hash Table in C using method of Linear Probing.
This project was made for mini project of CSE207 Data Structures Spring-2021 (East West University)

===== Author =====
Name	: Akmal Hossain
ID		: 2019-3-60-123
Section	: 02

===== Faculty =====
Dr. Maheen Islam
Associate Professor
Department of Computer Science & Engineering
East West University

Version: 1.1
License: MIT
Date: 19.05.2021

*/

#include <stdio.h>
#include <stdlib.h>

// Max size of hashtable
#define MAX_SIZE 10

// Individual array item consisting of (key, value)
typedef struct Item
{
	int key, value;
} Item;

// Each hashtable item with flag
typedef struct HashtableItem
{
	// flag = 0 : data does not exist
	// flag = 1 : data exists
	// flag = 2 : data existed at least once
	int flag;
	Item *data;
} HashtableItem;

// Global data
HashtableItem *array;
int size = 0;

// Functions pointers
void init_array();
void insert(int, int);
void remove_element(int);
void display();
int hash(int);
int current_size();
void clear_screen();

// ====== MAIN ======
void main()
{
	array = (HashtableItem *)malloc(MAX_SIZE * sizeof(HashtableItem));
	init_array();

	int running = 1;

	while (running)
	{
		clear_screen();

		printf("Implementation of Hash Table in C with Linear Probing\n\n");
		printf("======== MENU ========\n");
		printf("1. Insert into Hashtable\n");
		printf("2. Search item in Hashtable\n");
		printf("3. Remove item from Hashtable\n");
		printf("4. Check size of Hashtable\n");
		printf("5. Display Hashtable\n");
		printf("6. Exit\n");

		printf("\nEnter choice > ");
		int choice;
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			int key, value;
			printf("Inserting in Hashtable\n");
			printf("Enter key and value: ");
			scanf("%d%d", &key, &value);
			insert(key, value);
			break;
		}
		case 2:
		{
			printf("Search\n");
			break;
		}
		case 3:
		{
			int key;
			printf("Removing from Hashtable\n");
			printf("Enter the key to delete: ");
			scanf("%d", &key);
			remove_element(key);
			break;
		}
		case 4:
		{
			printf("Size of Hashtable is: %d\n", current_size());
			break;
		}
		case 5:
		{
			display();
			break;
		}
		case 6:
		{
			running = 0;
			printf("\nProgram exited!\n");
			return 0;
		}
		default:
		{
			printf("\nInvalid choice!\n");
		}
		}

		char c;
		printf("\nContinue? (y/n) : ");
		scanf("%s", &c);
		if (c != 'y' && c != 'Y' && c != '1')
		{
			running = 0;
		}
	}
}

// Initializing hashtable array
void init_array()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		array[i].flag = 0;
		array[i].data = NULL;
	}
}

// Generate unique hash code for any key
int hash(int key)
{
	return key % MAX_SIZE;
}

// Insert (key, value) to hashtable
void insert(int key, int value)
{
	int index = hash(key);
	int i = index;

	// New item to insert in the hashtable array
	Item *new_item = (Item *)malloc(sizeof(Item));
	new_item->key = key;
	new_item->value = value;

	// Probing through the array until we reach an empty space
	while (array[i].flag == 1)
	{
		// Existing key matches the given key
		if (array[i].data->key == key)
		{
			printf("\nKey already exists, updating its value\n");
			array[i].data->value = value;
			return;
		}

		i = (i + 1) % MAX_SIZE;
		if (i == index)
		{
			printf("\nHash table is full!\n");
			return;
		}
	}

	array[i].flag = 1;
	array[i].data = new_item;
	size++;
	printf("\nKey (%d) has been inserted\n", key);
}

// Remove an element from the hashtable
void remove_element(int key)
{
	int index = hash(key);
	int i = index;

	// Probing through array until we reach an empty space where not even once an element had been present
	while (array[i].flag != 0)
	{
		// Data key matches the given key
		if (array[i].flag == 1 && array[i].data->key == key)
		{
			array[i].flag = 2;
			array[i].data = NULL;
			size--;
			printf("\nKey (%d) has been removed\n", key);
			return;
		}

		i = (i + 1) % MAX_SIZE;
		if (i == index)
		{
			printf("\nKey does not exist\n");
			break;
		}
	}
}

// Display all the elements of hashtable
void display()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		Item *current = (Item *)array[i].data;

		if (current == NULL)
			printf("\nArray[%d] has no elements\n", i);
		else
			printf("\nArray[%d] has elements: { key: %d, value: %d }\n", i, current->key, current->value);
	}
}

int current_size()
{
	return size;
}

// Define clear_screen method based on the current os (windows/linux)
#ifdef _WIN32
void clear_screen()
{
	system("cls");
}
#else
void clear_screen()
{
	system("clear");
}
#endif
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct list
{
	int data;
	struct list* next;
};

struct list* create(int a);
struct list* add(struct list* lst, int data);
struct list* delete_head(struct list* root);
struct list* delet_elem(struct list* lst, struct list* root);
void print_list(struct list* lst);
struct list* delete_elem_num(int data, struct list* root);


int main(void)
{
	struct list* head = NULL;
	struct list* p = NULL;
	int elem, n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Enter element: ");
		scanf("%d", &elem);
		if (i == 0)
		{
			p = create(elem);
			head = p;
		}
		else
			p = add(p, elem);
	}
	int navigation = 1;
	while (navigation != 0) {
		putchar('\n');
		printf("Choose:\n");
		printf("1)Add new element\n2)Delete element by number\n3)Delete last element\n4)Delete head element\n5)Show list\n6)Exit\n");
		printf("> ");
		scanf("%d", &navigation);
		if (navigation == 1) {
			scanf("%d", &elem);
			p = add(p, elem);
		}
		if (navigation == 2) {
			scanf("%d", &elem);
			head = delete_elem_num(elem, head);
		}
		if (navigation == 3) {
			p = delet_elem(p, head);
		}
		if (navigation == 4) {
			head = delete_head(head);
		}
		if (navigation == 5) {
			print_list(head);
			putchar('\n');
		}
		if (navigation == 6) {
			if (head != NULL) {
				free(head);
			}
			if (p != NULL) {
				free(p);
			}
			return 0;
		}
	}
}

struct list* create(int a)
{
	struct list* lst;
	lst = (struct list*)malloc(sizeof(struct list));
	if (lst == NULL) return NULL;
	lst->data = a;
	lst->next = NULL;
	return(lst);
}
struct list* add(struct list* lst, int data)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(struct list));
	p = lst->next;
	lst->next = temp;
	temp->data = data;
	temp->next = p;
	return(temp);
}

struct list* delete_head(struct list* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	struct list* temp;
	temp = root->next;
	free(root);
	return(temp);
}

struct list* delet_elem(struct list* lst, struct list* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	struct list* temp;
	temp = root;
	while (temp->next != lst)
	{
		temp = temp->next;
	}
	temp->next = lst->next;
	free(lst);
	return(temp);
}


void print_list(struct list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->data);
		p = p->next;
	} while (p != NULL);
}

struct list* delete_elem_num(int data, struct list* root)
{
	struct list* tmp = root, * p = NULL;
	if (root == NULL)
		return NULL;
	while (tmp && tmp->data != data)
	{
		p = tmp;
		tmp = tmp->next;
	}
	if (tmp == root)
	{
		free(root);
		return tmp->next;
	}
	if (!tmp)
		return root;
	p->next = tmp->next;
	free(tmp);
	return root;
}
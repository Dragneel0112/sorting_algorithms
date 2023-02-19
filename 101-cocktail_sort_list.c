#include "sort.h"

/**
 * swap_list - Swaps the elements of the list
 * @ptr1: First pointer
 * @ptr2: Second pointer
 * @n: n is 0 for increase, n is 1 for decrease
 */
void swap_list(listint_t **ptr1, listint_t **ptr2, int n)
{
	listint_t *temp, *tmp;

	temp = *ptr1;
	tmp = *ptr2;

	temp->next = tmp->next;
	tmp->prev = temp->prev;

	if (tmp->next)
		tmp->next->prev = temp;

	if (temp->prev)
		temp->prev->next = tmp;

	temp->prev = tmp;
	tmp->next = temp;

	if (n == 0)
		*ptr1 = tmp;
	else
		*ptr2 = temp;
}

/**
 * increase_sort - Move the bigger numbers to the end
 * @ptr: Pointer to the bigger number
 * @limit: Limit of the list
 * @list: List of integers
 */
void increase_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->next != *limit)
	{
		if (aux->n > aux->next->n)
		{
			swap_list(&aux, &(aux->next), 0);
			if (aux->prev == NULL)
				*list = aux;
			print_list(*list);
		}
		aux = aux->next;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * decrease_sort - Moves the smaller numbers to the start
 * @ptr: Pointer to the smaller number
 * @limit: Limit of the list
 * @list: List of integers
 */
void decrease_sort(listint_t **ptr, listint_t **limit, listint_t **list)
{
	listint_t *aux;

	aux = *ptr;

	while (aux != *limit && aux->prev != *limit)
	{
		if (aux->n < aux->prev->n)
		{
			swap_list(&(aux->prev), &aux, 1);
			if (aux->prev->prev == NULL)
				*list = aux->prev;
			print_list(*list);
		}
		aux = aux->prev;
	}

	*limit = aux;
	*ptr = aux;
}

/**
 * cocktail_sort_list - sorts a doubly linked list
 * of integers in ascending order using the
 * Cocktail shaker sort algorithm
 *
 * @list: head of the linked list
 * Return: no return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *limit1, *limit2, *ptr;

	if (list == NULL)
		return;

	if (*list == NULL)
		return;

	limit1 = limit2 = NULL;
	ptr = *list;

	do {
		increase_sort(&ptr, &limit1, list);
		decrease_sort(&ptr, &limit2, list);
	} while (limit1 != limit2);
}

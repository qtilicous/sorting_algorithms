#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion Sort algorithm.
 * @list: A pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *insert = current;
		listint_t *prev = current->prev;

		while (prev != NULL && insert->n < prev->n)
		{
			if (insert->next != NULL)
				insert->next->prev = prev;
			prev->next = insert->next;
			insert->prev = prev->prev;
			insert->next = prev;
			prev->prev = insert;
				if (insert->prev == NULL)
					*list = insert;
				else
					insert->prev->next = insert;

				print_list(*list);
				prev = insert->prev;
		}

		current = current->next;
	}
}

#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *pretmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tmp = (*list)->next;
	while (tmp != NULL)
	{
		pretmp = tmp->prev;
		while (pretmp != NULL && tmp->n < pretmp->n)
		{
			pretmp->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = pretmp;
			tmp->prev = pretmp->prev;
			tmp->next = pretmp;
			if (pretmp->prev != NULL)
				pretmp->prev->next = tmp;
			else
				*list = tmp;
			pretmp->prev = tmp;
			pretmp = tmp->prev;
			print_list((const listint_t *)*list);
		}
		tmp = tmp->next;
	}
}

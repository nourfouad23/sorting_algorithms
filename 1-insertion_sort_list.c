#include "sort.h"

/**
 * insertion_sort_list - insertion sort
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *pnt, *nxt;

	if (list && *list && (*list)->next)
	{
		temp = (*list)->next;
		pnt = temp->prev;
		nxt = temp->next;

		while (temp)
		{
			if (temp->n < pnt->n)
			{
				swap_list(pnt, temp, nxt, list);
			}
			temp = nxt;
			if (temp)
			{
				nxt = temp->next;
				pnt = temp->prev;
			}
		}
	}
}

/**
 * swap_list - swaps list
 * @pn: param
 * @temp: param
 * @nxt: param
 * @h: param
 */
void swap_list(listint_t *pn, listint_t *temp, listint_t *nxt, listint_t **h)
{

	while (pn && temp->n < pn->n)
	{
		if (nxt)
			nxt->prev = pn;
		temp->next = pn;
		temp->prev = pn->prev;
		if (pn->prev)
			(pn->prev)->next = temp;
		pn->prev = temp;
		pn->next = nxt;
		nxt = pn;
		pn = temp->prev;
		if ((*h)->prev)
			*h = (*h)->prev;
		print_list(*h);
	}
}
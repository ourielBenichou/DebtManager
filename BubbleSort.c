#include"BubbleSort.h"
/* Bubble sort the given linked list */
customerList* bubbleSort(customerList* start)
{
	int swapped, i;
	customerList* ptr1;
	customerList* lptr = NULL;

	/* Checking for empty list */
	if (start == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr)
		{
			if (ptr1->data.debt > ptr1->next->data.debt)
			{
				swap(&ptr1, &ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
	return start;
}

/* function to swap data of two nodes a and b*/
void swap(customerList** a, customerList** b)
{
	customer temp = (*a)->data;
	(*a)->data = (*b)->data;
	(*b)->data = temp;
}
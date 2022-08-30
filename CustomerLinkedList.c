#include"CustomerLinkedList.h"

customerList* insertCustomerNode(customerList* head,customerList* tmp)
{
	customerList* prev;
	if (!head)//האם הצומת הוא ראשון
		head = tmp;
	else
	{
		prev = head;
		while (prev->next)
			prev = prev->next;
		prev->next = tmp;
	}
	return head;
}

int checkNewCostomer(customerList* head, customer tmpCust)
{
	customerList* curr = head;
	while (curr)
	{
		if (!strcmp(curr->data.ID, tmpCust.ID)) //if the customer exists is increased is debt to old debt
		{
			if (strcmp(curr->data.firstName, tmpCust.firstName) || strcmp(curr->data.lastName, tmpCust.lastName)) {
				printf("\n+=======================================================+");
				printf("\n|The Name of customer ID: %s is:%-8s %-8s|", curr->data.ID, curr->data.firstName, curr->data.lastName);
				printf("\n+=======================================================+");
			}
			curr->data.debt += tmpCust.debt;//increased debt to old debt
			if (comperDate(curr->data.date, tmpCust.date) > 0)//compare between 2 date and save the old one
				curr->data.date = tmpCust.date;
			return 0;
		}
		curr = curr->next;
	}
	return 1;
}

void releaseLinkedList(customerList* head)
{
	customerList* preve, * tmp;
	preve = tmp = head;
	while (tmp != NULL)
	{

		tmp = tmp->next;
		free(preve->data.firstName);
		free(preve->data.lastName);
		free(preve);
		preve = tmp;
	}
}

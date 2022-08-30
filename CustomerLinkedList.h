#ifndef CustomerLinkedList
#define CustomerLinkedList


#include<stdio.h>
#include<string.h>
#include"Date.h"

typedef struct customer
{
	char *firstName;
	char *lastName;
	char ID[10];
	char phone[11];
	int debt;
	Date date;
}customer;

typedef struct customerList
{
	customer data;
	struct customerList* next;
}customerList;


customerList* insertCustomerNode(customerList* head, customerList* tmp);

int checkNewCostomer(customerList* head, customer tmpCust);

void releaseLinkedList(customerList* head);

#endif // !CustomerLinkedList




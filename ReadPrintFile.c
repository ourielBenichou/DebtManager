#include"ReadPrintFile.h"

customerList* readFile(FILE* fDebt, customerList* head)
{
	char buffer[MAX_LINE],*token;
	//for each line in the file insert info to customer linked list after validation
	while (!feof(fDebt)) {

#pragma region Linked_List
		char* firstName = (char*)malloc(sizeof(char)*MAX_NUM);
		char * lastName = (char*)malloc(sizeof(char)* MAX_NUM);
		customerList* tmp = (customerList*)malloc(sizeof(customerList));
		tmp->data.firstName = firstName;
		tmp->data.lastName = lastName;
		fgets(buffer, MAX_LINE, fDebt);
		token = strtok(buffer, ",");
		if (checkFirstLastName(token))
			strcpy(firstName, token);
		token = strtok(NULL, ",");
		if (checkFirstLastName(token))
			strcpy(lastName, token);
		token = strtok(NULL, ",");
		if (checkID(token))
			strcpy(tmp->data.ID, token);
		token = strtok(NULL, ",");
		if (checkPhone(token))
			strcpy(tmp->data.phone, token);
		token = strtok(NULL, ",");
		if (checkDebt(token)) 
			tmp->data.debt = atoi(token);
		token = strtok(NULL, ",");
		
		//convert date strint to int date dd/mm/yyyy
		tmp->data.date = stringToDate(token);

		tmp->next = NULL;
#pragma endregion

		//check if the client have valid info and is not exist already
		if (checkNewCostomer(head, tmp->data)) 
			head = insertCustomerNode(head, tmp);
		else
		{
			free(tmp->data.firstName);
			free(tmp->data.lastName);
			free(tmp);
		}
		
	}
	//return a new and full linked list
	return head;
}

/*prints the all customer that in the file*/
void printFile(customerList* head)
{
	while (head != NULL)
	{
		printCustomer(head->data);
		head = head->next;
	}
}

void printCustomer(customer result)
{
	printf("\n+=======================================================+");
	printf("\n| First Name:%-8s         Last Name:%-16s|", result.firstName, result.lastName);
	printf("\n+-------------------------------------------------------+");
	printf("\n| ID:%10s               Phone Number:%s   |", result.ID, result.phone);
	printf("\n| Debt: $%-10d           Date Of Market:%-0.2d/%-0.2d/%-0.4d |", result.debt, result.date.day, result.date.mount, result.date.year);
	printf("\n+=======================================================+\n\n");
}

void printMenu()
{
	printf("\nExsemple to set new recod: set first name=***,last name=***,ID=***(9 digit),phone=***(10 digit),date=dd/mm/yyyy,debt=***(+-)\n");
	printf("\nsearch by First Name=***/Last Name=***/ID:*********/Debt (><=)/Date(><=) ");
	printf("\nselect ......");
	printf("\nTo Print wirth: \"print\" ");
	printf("\nTo Quit wirth: \"quit\" ");
}
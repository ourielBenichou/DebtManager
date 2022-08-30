#include"SelectQuery.h"

void getCommand(char buffer[], FILE* fDebts, customerList* head)
{
	int errorFlag = FALSE;
	char* token, * tmpBuffer = buffer, * selectArr[3];
	token = strtok(buffer, " ");

	/*-----------------------------------If the user is interested to adding a new record----------------------------*/
	if (!strcmp("set", token))
	{
		//Checking and placing the new customer if the data is correct
		
		setValidation(buffer, head);
		
	}
	/*-----------------------------------------query for the user ---------------------------------------------------*/
	else
		if (!strcmp("print", buffer))
			printFile(head);
		else
		{
			if (!strcmp("select", buffer)) {
				/*filtering the word select from the buffer*/
				token = strtok(NULL, " ");
				if (token)
					selectArr[Left_Expression] = token;
				else errorFlag=TRUE;
				
				/*check if the search commande is not first/family value*/
				if (strcmp(selectArr[Left_Expression], "first") && strcmp(selectArr[Left_Expression], "last")) {
					token = strtok(NULL, " ");
					if (token)
						selectArr[Operator] = token;
					else errorFlag = TRUE;
					token = strtok(NULL, " ");
					if (token)
					selectArr[Rigth_Expression] = token;
					else errorFlag = TRUE;
				}
				/* if the user search first / last name*/
				else
				{
					token = strtok(NULL, " ");
					token = strtok(NULL, "=");
					token += 1;
					if (token)
						selectArr[Rigth_Expression] = token;
					else errorFlag = TRUE;
				}

				if (!errorFlag) {
					if (!selectQuery(selectArr, head))//make the query
						printf("\nCustomer is NOT found !!!");
				}

				else printf("\nError Command !!!");
			}
		}

}

int selectQuery(char* selectArr[], customerList* head)
{
	int i, result, debt,flag=FALSE;
	char* token, operat, * commandArr[] = { "first","last","ID","phone","date","debt" };

	int (*fun_ptr_arr[])(char*, customerList*) = { searchByFirstName,searchByLastName,searchByID,searchByPhone };
	int (*fun_ptr_arr2[])(customerList*, char*, char*) = { dateComparOperator,debtComparOperator };
	for (i = 0; i < 4; i++)
		if (!strcmp(commandArr[i], selectArr[Left_Expression])) {
			flag = (*fun_ptr_arr[i])(selectArr[Rigth_Expression], head);
				return flag;
		}
	/*if the user search by date or debt*/
	for (i = 0; i < 2; i++)
		if (!strcmp(commandArr[i+4], selectArr[Left_Expression])) {
			flag = (*fun_ptr_arr2[i])(head, selectArr[Operator], selectArr[Rigth_Expression]);
			return flag;
		}
}

int searchByFirstName(char* value, customerList* head)
{
	int flag = FALSE;
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (strcmp(head->data.firstName, value) == 0) {
			printCustomer(head->data);
			flag = TRUE;
		}
		head = head->next;
	}

	return flag;
}

int searchByLastName(char* value, customerList* head)
{
	int flag = FALSE;
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (!strcmp(head->data.lastName, value)) {
			printCustomer(head->data);
			flag = 1;
		}
		head = head->next;
	}

	return flag;
}

int searchByID(char* value, customerList* head)
{
	customerList* curr = head;
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (!strcmp(head->data.ID, value)) {
			printCustomer(head->data);
			return 1;
		}
		head = head->next;
	}

	return 0;
}

int searchByPhone(char* value, customerList* head)
{
	int flag = 0;
	//חיפוש הערך בכול הרשימה המקושרת
	while (head)
	{
		if (!strcmp(head->data.phone, value)) {
			printCustomer(head->data);
			flag = 1;
		}
		head = head->next;
	}

	return flag;
}

int dateComparOperator(customerList* head, char* operat, char* value)
{
	Date tmpDate = stringToDate(value);
	int i, flag = 0;
	i = operat[0] * 100;
	i += operat[1] * 10;

	switch (i)
	{
	case bigger:  //operator: >
		while (head != NULL)
		{
			if (comperDate(head->data.date, tmpDate) > 0) {
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;

	case smaller: //operator: <
		while (head != NULL)
		{
			if (comperDate(head->data.date, tmpDate) < 0) {
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;

	case equal: //operator: =
		while (head != NULL)
		{
			if (comperDate(head->data.date, tmpDate) == 0) {
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;

	case biggerEqual:       //operator: >=
		while (head != NULL)
		{
			if (comperDate(head->data.date, tmpDate) >= 0 || comperDate(head->data.date, tmpDate) == 0) {
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;

	case smallerEqual:   //operator: <=
		while (head != NULL)
		{
			if (comperDate(head->data.date, tmpDate) < 0 || comperDate(head->data.date, tmpDate) == 0) {
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;

	case different:  //operator: !=
		while (head != NULL)
		{
			if (comperDate(head->data.date, tmpDate) < 0 || comperDate(head->data.date, tmpDate) > 0) {
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;

	default:
		printf("\nError Commend!!!");
		return flag;
	}
}

int debtComparOperator(customerList* head, char* operat, char* value)
{
	int debt,flag=FALSE;
	int i = operat[Left_Expression] * 100;
	i += operat[Operator] * 10;

	if (checkDebt(value))
		debt = atoi(value);
	else
		return FALSE;

	switch (i)
	{
	
	case bigger:  //operator: >
		while (head != NULL)
		{
			if (head->data.debt > debt) {
				printCustomer(head->data);
				flag=TRUE;
			}
			head = head->next;
		}
		return flag;
	
	case smaller: //operator: <
		while (head != NULL)
		{
			if (head->data.debt < debt) {
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;

	case equal: //operatour: =
		while (head != NULL)
		{
			if (head->data.debt == debt){
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		
	return flag;

	case biggerEqual:       //operator: >=
		while (head != NULL)
		{
			if (head->data.debt >= debt){
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;
	
	case smallerEqual:   //operator: "<="
		while (head != NULL)
		{
			if (head->data.debt <= debt){
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;
	
	case different:  //operator: !=
		while (head != NULL)
		{
			if (head->data.debt != debt){
				printCustomer(head->data);
				flag = TRUE;
			}
			head = head->next;
		}
		return flag;
	
	default:
		printf("\nError Commend!!!");
		return flag;
	}
}



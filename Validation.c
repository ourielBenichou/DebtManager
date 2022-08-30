#include"Validation.h"

int setValidation(char* buffer,customerList* head)
{
	char* firstName = (char*)malloc(sizeof(char)*MAX_NUM);
	char* lastName = (char*)malloc(sizeof(char)* MAX_NUM);
	customerList* tmp = (customerList*)malloc(sizeof(customerList));
	tmp->data.firstName = firstName;
	tmp->data.lastName = lastName;

	char* token;
	token = strtok(NULL, "=");
	int errorFlag = FALSE;

	//get the first name to the struct
	if (token != NULL && !strcmp(token, "first name")) {
		token = strtok(NULL, ",");
		if (checkFirstLastName(token))
			strcpy(tmp->data.firstName, token);
		else errorFlag = TRUE;
	}
	else errorFlag = TRUE;

	//get the family name
	token = strtok(NULL, "=");
	if (token != NULL && !strcmp(token, "last name")) {
		token = strtok(NULL, ",");
		if (checkFirstLastName(token))
			strcpy(tmp->data.lastName, token);
		else errorFlag = TRUE;
	}
	else errorFlag = TRUE;

	//Id
	token = strtok(NULL, "=");
	if (token != NULL && !strcmp(token, "ID")) {
		token = strtok(NULL, ",");
		if (checkID)
			strcpy(tmp->data.ID, token);
		else errorFlag = TRUE;
	}
	else errorFlag = TRUE;

	//phone
	token = strtok(NULL, "=");
	if (token != NULL && !strcmp(token, "phone")) {
		token = strtok(NULL, ",");
		if (checkPhone(token))
			strcpy(tmp->data.phone, token);
		else errorFlag = TRUE;
	}
	else errorFlag = TRUE;

	//debt
	token = strtok(NULL, "=");
	if (token != NULL && !strcmp(token, "debt")) {
		token = strtok(NULL, ",");
		if (checkDebt(token))
			tmp->data.debt = atoi(token);
		else errorFlag = TRUE;
	}
	else errorFlag = TRUE;

	//date
	token = strtok(NULL, "=");
	if (token != NULL && !strcmp(token, "date")) {
		token = strtok(NULL, ",");
		tmp->data.date = stringToDate(token);
	}
	else errorFlag = TRUE;

	//updating the node in the end of the list
	tmp->next = NULL;

	if (!errorFlag && checkNewCostomer(head, tmp->data)) {
		insertCustomerNode(head, tmp);
		printf("\nAdd New customer Success !!!");
		return TRUE;
	}
	else
	{
		printf("\nAdd New customer Faild !!!\n");
		free(tmp->data.firstName);
		free(tmp->data.lastName);
		free(tmp);
		return FALSE;
	}

}

int checkFirstLastName(char* value)
{
	if (value == NULL) {
		printf("\nName missing!!!");
		return FALSE;
	}
	return TRUE;
}
int checkID( char* value)
{
	if (!value && strlen(value) != 9) {
		printf("\nUn currect ID");
		return FALSE;
	}
	return TRUE;
}
int checkPhone(char* value)
{
	if (!value && strlen(value) == 10&&value[0]=='0') {
		printf("\nUn currect phone!!!");
		return FALSE;
	}
	return TRUE;
}

int checkDebt(char* value)
{
	if (value[0] == '-')
		value++;
	for (int i = 0; i < strlen(value); i++)
	{
		if (value[i] < '0' || value[i] > '9')
			if (value[i] != '.')
				return FALSE;
	}
	return TRUE;
 }

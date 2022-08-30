#ifndef SelectQuery
#define SelectQuery


#include"CustomerLinkedList.h"
#include"ReadPrintFile.h"
#include"Validation.h"

enum ComparOperator
{
	bigger = 6200,
	equal = 6100,
	smaller = 6000,
	biggerEqual = 6810,
	smallerEqual = 6611,
	different = 3910
};
enum expression { Left_Expression, Operator, Rigth_Expression  };
																																																																														

void getCommand(char buffer[], FILE* fDebts, customerList* head);
int selectQuery(char* selectArr[], customerList* head);

int searchByFirstName(char* value, customerList* head);
int searchByLastName(char* value, customerList* head);
int searchByID(char* value, customerList* head);
int searchByPhone(char* value, customerList* head);

int dateComparOperator(customerList* head, char* operat, char* value);
int debtComparOperator(customerList* head, char* operat, char* value);

#endif // !SelectQuery
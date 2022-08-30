#ifndef Validation
#define Validation


#include"ReadPrintFile.h"

#define DATE_LENGTH 11

int setValidation(char* buffer, customerList* head);
int checkFirstLastName(char* value);
int checkID(char* value);
int checkPhone(char* value);
int checkDebt(char* value);
#endif // !Validation
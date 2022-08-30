#ifndef ReadPrintFile
#define ReadPrintFile
#define MAX_NUM 20

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CustomerLinkedList.h"
#include"BubbleSort.h"
#include"Validation.h"
#include"Date.h"

#define TRUE 1
#define FALSE 0
#define MAX_LINE 200

customerList* readFile(FILE* fDebt, customerList* head);
void printCustomer(customer result);
void printFile(customerList* head);
void printMenu();	

#endif // !ReadPrintFile


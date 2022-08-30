#include<stdio.h>
#include"Date.h"

Date stringToDate(char* dateString) 
{
	int errorCommand=0;
	Date sDate; //
	int day, mount, year;
	char* token;	
	
	if (!dateString)
		return;
	token = strtok(dateString, "/");
	if (token)
		day = atoi(token);
	else errorCommand = 1;
	if (day > 0 && day <= 31)
		sDate.day = day;
	else {
		//sDate.day = 0;
		printf("\n day not exsist,");
		return;
	}
	token = strtok(NULL, "/");
	if (token) {
		mount = atoi(token);
		if (mount > 0 && mount <= 12)
			sDate.mount = mount;
		else
		{
			//sDate.mount = 0;
			printf("\n mount not exsist,");
			return;
		}
	}
	else errorCommand = 1;
	token = strtok(NULL, "/");
	if (token) {
		year = atoi(token);
		if (year > 1900)
			sDate.year = year;
		else
		{
			//sDate.year = 0;
			printf("\nEror on the year date");
			return;
		}
	}
	else errorCommand = 1;
	if (!errorCommand)
		return sDate;
	else return;
}

int comperDate(Date a, Date b)
{
	if (a.year != b.year)
		return a.year - b.year;
	if (a.mount != b.mount)
		return a.mount - b.mount;
	if (a.day != b.day)
		return a.day - b.day;
	return 0;
}


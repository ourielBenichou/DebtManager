#ifndef Dates
#define Dates


typedef struct Date
{
	int day, mount, year;
}Date;

Date stringToDate(char* dateString);
int comperDate(Date a, Date b);

#endif // !Dates

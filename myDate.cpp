#include "myDate.h"
#include "string.h"
using namespace std;
#include "Calander.h"
myDate::myDate(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}
myDate::myDate(int day, int month)
{
	setDay(day);
	setMonth(month);
	setYear(2002);
}
myDate::myDate()
{
}
int myDate::getday()
{
	return this->day;
	
}
int myDate::getmonth()
{
	return this->month;
}
int myDate::getyear()
{
	return this->year;
}
void myDate::setDay(int _day)
{	
	this->day = _day;
}
void myDate::setMonth(int _month)
{
	this->month = _month;
}
void myDate::setYear(int _year)
{
	this->year = _year;
}
void myDate::set(int day, int month, int year)
{
	if (year < 1900 || year>2100)
	{
		cout << "ERROR! :incorrect data" << endl;
		return;
	}
	if (month < 1 || month>12)
	{
		cout << "ERROR! :incorrect data" << endl;
		return;
	}
	if (month == 2)
	{
		if (day > 28 || day < 1)
		{
			cout << "ERROR! :incorrect data" << endl;
			return;
		}
	}
	else
	{
		if (day > 30 || day < 1)
		{
			cout << "ERROR! :incorrect data" << endl;
			return;
		}
	}
	setDay(day);
	setMonth(month);
	setYear(year);
}
void  myDate::init()
{
	set(22, 8,2022);
}
bool myDate::isBefore(myDate date)
{
	if (this->year < date.year)
		return true;
	else if (this->year > date.year)
		return false;
	else
	{
		if (this->month < date.month)
			return true;
		else if (this->month > date.month)
			return false;
		else
		{
			if (this->day < date.day)
				return true;
			else 
				return false;
		}
	}
}
void myDate::changeComment(char comment[])
{
	if (strlen(comment) > 20)
	{
		cout << "ERROR! :incorrect data" << endl;
		return;
	}
	strcpy_s(this->comment, comment);
}
void myDate::bringForward(int day)
{
	if (day > 365 || day < 0)
	{
		cout << "ERROR! :incorrect data" << endl;
		return;
	}
	while (day>0)
	{
		if (this->month == 2)
		{
			if (this->day + day > 28)
			{
				this->month++;
				day = day-(28 - this->day); 
				this->day = 0;
			}
			else
			{
				this->day += day;
				day = 0;
			}
		}
		else
		{
			if (this->day + day > 30)
			{
				this->month++;
				if (month > 12)
				{
					this->month = 0;
					this->year++;
				}
				day =day-( 30 - this->day);
				this->day = 0;
			}
			else
			{
				this->day += day;
				day = 0;
			}
		}
	}
}
void myDate::delay(int day)
{
	if (day > 365 || day < 0)
	{
		cout << "ERROR! :incorrect data" << endl;
		return;
	}
	while (day>0) 
	{
		if (this->day-day < 0 && this->month != 3)
		{
			this->month--;
			day = day - this->day;
			this->day = 30;
			if (this->month == 0)
			{
				this->year--;
				this->month = 12;
			}
		}
		if (this->day-day < 0 && this->month == 3)
		{
			this->month--;
			day = day - this->day;
			this->day = 28;
		}
		else if (this->day-day > 0)
		{
			this->day -= day;
			day = 0;
		}

	}
}
void myDate:: print()
{
	cout << this;
}

ostream& operator<<(ostream& os, myDate* date)
{
	return os << date->getday() << '/' <<date->getmonth()<< '/' <<date->getyear()<< endl;
}


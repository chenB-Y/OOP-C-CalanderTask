#pragma once
#include "iostream"
using namespace std;
class myDate
{
private:
	int day;
	int month;
	int year;
	char comment[20];
public:
	myDate(int day, int month, int year);
	myDate();
	myDate(int day, int month);
	int getday();
	int getmonth();
	int getyear();
	void setDay(int _day);
	void setMonth(int _month);
	void setYear(int _year);
	void set(int day, int month, int year);
	void init();
	void changeComment(char comment[]);
	bool isBefore(myDate date);
	void delay(int day);
	void bringForward(int day);
	void print();
	friend ostream& operator<<(ostream& os, myDate* date);
};


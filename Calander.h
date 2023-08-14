#pragma once
#include "myDate.h"
#define MY_DATE_SIZE 30
class Calander 
{
private:
	myDate** dates = new myDate * [30];
	/*myDate* dates[MY_DATE_SIZE] = { nullptr };*/ 
public:
	Calander();
	
	void setDate(int num , myDate mydate);
	bool isFree(int num);
	int firstFree();
	void Insert(myDate* mydate); 
	int oldest();
	int datesNum();
	void deleteAll();
	void Delete(int num);
	void Print();
};


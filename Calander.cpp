#include "Calander.h"
Calander::Calander()
{
	for (int i = 0; i < MY_DATE_SIZE; i++)
		dates[i] = nullptr;
}
void Calander::setDate(int num, myDate mydate)
{
	if (isFree(num) == true)
	{
		cout << "ERROR! : INCORRECT DATE" << endl;
		return;
	}
	else
	{
		dates[num] = new myDate;
		dates[num]->set(mydate.getday(),mydate.getmonth(),mydate.getyear());
	}
}
bool Calander::isFree(int num)
{
	if (num < 0 || num>30) 
	{
		cout << "ERROR! : INCORRECT DATE" << endl;
		return false;
	}
	if (dates[num]== nullptr) 
		return true;
	else
		return false;
}
int Calander::firstFree()
{
	for (int i = 0; i < MY_DATE_SIZE; i++)
	{
		if (dates[i] == nullptr )
		{
			return i+1;
		}
	}
	return -1;
}
void Calander::Insert(myDate* mydate)
{
	int freeSpot = firstFree() -1;
	if (freeSpot != -1)
	{
		dates[freeSpot] = new myDate;
		dates[freeSpot]->set(mydate->getday(), mydate->getmonth(), mydate->getyear());
	}
}
int Calander::oldest()
{
	myDate* firstDate = nullptr;
	int index = 0;
	for (int i = 0; i < MY_DATE_SIZE; i++)
	{
		if (isFree(i) == true)
			continue;
		if (firstDate == nullptr)
		{
			firstDate = dates[i];
			index = i;
			continue;
		}
		if (dates[i]->isBefore(*firstDate))
		{
			firstDate = dates[i];
			index = i;
		}
	}
	return index+1;
}
int Calander::datesNum()
{
	int occupiedSpot = 0;
	for (int i = 0; i < MY_DATE_SIZE; i++)
	{
		if (dates[i] != nullptr)
			occupiedSpot++;
	}
	return occupiedSpot;
}
void Calander::deleteAll()
{
	for (int i = 0; i < 30; i++)
	{
		Delete(i);
	}
	//delete[]dates;
}
void Calander::Delete(int num)
{
	delete dates[num];
	dates[num] = nullptr;
}
void Calander::Print()
{
	int counter = 0;
	for (int i = 0; i < 30; i++)
	{
		if (dates[i] == nullptr)
			counter++;
		else
		{
			cout << i+1 << '.';
			dates[i]->print();
		}
	}
	if (counter == 30)
		cout << "EMPTY CALANDER!!" << endl;
}



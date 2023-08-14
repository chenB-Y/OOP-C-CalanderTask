#include "iostream"
#include "myDate.h"
#include "Calander.h"
using namespace std;
void main()
{
	myDate tal, adi, shir (8,5,2002),chen(13,5);
	cout << "the function Init" << endl;
	tal.init();
	adi.init();
	adi.print();
	tal.bringForward(59);
	cout << "tal bring forward" << endl;
	tal.print();
	cout << "adi delay" << endl;
	adi.delay(23);
	adi.print();
	cout << "who comes before ? adi / tal?"<< endl;
	cout <<((tal.isBefore(adi) == true) ? "tal is before adi" : "adi is before tal")<< endl;
	cout << boolalpha << tal.isBefore(adi) << endl;
	cout <<"shir" << endl;
	shir.print();
	cout << "chen" << endl;
	chen.print();
	myDate tal1, adi1(1, 2, 2020);
	tal1 = adi1;
	cout << &tal1 << endl;

	Calander date;
	date.Insert(&tal);
	cout << "the seconde index in the aaray is free?" << date.isFree(1) << endl;
	date.Insert(&adi);
	cout <<"the seconde index in the aaray is free?"<< date.isFree(1) << endl;
	date.Insert(&shir);
	cout << "the first available index is :" << date.firstFree() << endl;
	date.Print();
	date.setDate(2,chen);
	date.Print();
	cout <<" the index with the earliest date is:" << date.oldest() << endl;
	cout << "there is: " << date.datesNum() << " index with dates inside."<<endl;
	cout << "the next function delete the seconde index in the array" << endl;
	date.Delete(1);
	date.Print();
	cout << "the next function delete all the aaray" << endl;
	date.deleteAll();
	date.Print();
	


	
	
}

/*
* main()
* {
* myDate 






















myDate adi(1,2,3);-12000
pri
.....
......

* insert(&adi); //myDate shir(1,2,3);-2500
* 
* }
* 
* void insert(myDate chen)-2500
* {
* }
*/
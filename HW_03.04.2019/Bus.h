#pragma once
#include<iostream>
#include <iomanip>
#include<Windows.h>
#include<ctime>
#include<cstring>
#include<fstream>
using namespace std;

//Bus: Фамилия и инициалы водителя, Номер автобуса, Номер маршрута, Марка, Год начала эксплуатации, Пробег.
//Создать массив объектов.Вывести :
//a) список автобусов для заданного номера маршрута;
//b) список автобусов, которые эксплуатируются больше 10 лет;
//c) список автобусов, пробег у которых больше 10000 км.

class Bus {
private:
	char driver[30];
	char bus[10];
	int route;
	char model[30];
	int year;
	double run;
public:
	Bus();
	Bus(const char *driver, const char* bus, int route, const char *model, int year, double run);
	void setDriver(const char* driver);
	void setBus(const char* bus);
	void setRoute(int route);
	void setModel(const char* model);
	void setYear(int year);
	void setRun(double run);

	const char*getDriver();
	const char* getBus();
	int getRoute();
	const char*getModel();
	int getYear();
	double getRun();

	void print();
	bool by_route(int route);
	bool years10();
	bool by_run();
};

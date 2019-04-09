#include "Bus.h"

Bus::Bus()
{
	strcpy_s(driver, "");
	strcpy_s(bus, "");
	route = 0;
	strcpy_s(model, "");
	year = 0;
	run = 0;
}

Bus::Bus(const char* driver, const char* bus, int route, const char* model, int year, double run)
{
	strcpy_s(this->driver, driver);
	strcpy_s(this->bus, bus);
	this->route = route;
	strcpy_s(this->model, model);
	this->year = year;
	this->run = run;
}

void Bus::setDriver(const char * driver)
{
	strcpy_s(this->driver, driver);
}

void Bus::setBus(const char* bus)
{
	strcpy_s(this->bus, bus);
}
void Bus::setRoute(int route)
{
	this->route = route;
}

void Bus::setModel(const char * model)
{
	strcpy_s(this->model, model);
}

void Bus::setYear(int year)
{
	this->year = year;
}

void Bus::setRun(double run)
{
	this->run = run;
}

const char * Bus::getDriver()
{
	return driver;
}

const char* Bus::getBus()
{
	return bus;
}

int Bus::getRoute()
{
	return route;
}

const char * Bus::getModel()
{
	return model;
}

int Bus::getYear()
{
	return year;
}

double Bus::getRun()
{
	return run;
}

void Bus::print()
{
	cout << driver << " // " << bus << " " << route << " " << model << " " <<year<< " " << run;
}

bool Bus::by_route(int route)
{
	return (this->route==route);
}

bool Bus::years10()
{
	return (2019 - year > 10);
}

bool Bus::by_run()
{
	return (run > 10000);
}

#include <iostream>
#include <vector>
#include "Classes.h"
using namespace std;

int main()
{
	Car car("Audi", 30);
	Horse horse("Star", "Black", 5);
	vector<IDriveble*> vehicle;
	vehicle.push_back(&car);
	vehicle.push_back(&horse);
	//vector<IDriveble*>* ptr = &vehicle;
	Driver driver("John", vehicle);

	//driver.SetGarage(vehicle);
	//driver.SetVehicle(&car);
	//driver.TestDrive();
	//cout << vehicle.size() << endl;
	//cout<< ""
	//cout << typeid(*vehicle[0]).name() << endl;
	//if (typeid(*vehicle[0]).name() == string("class Car"))
	//	cout << "Yep" << endl;
	//if (!strcmp(typeid(*vehicle[0]).name(), "class Car"))
	//	cout << "Yep" << endl;
	driver.TestDrive();
	//cout << horse.GetType() << endl;
	system("pause");
	return 0;
}
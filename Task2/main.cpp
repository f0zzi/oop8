#include <iostream>
#include "Classes.h"
using namespace std;

int main()
{
	Car car("Car", 30);
	Horse horse("Star", "Black", 5);

	IDriveble* d = &car;

	Driver driver("John");
	driver.SetVehicle(d);
	driver.TestDrive();

	//cout<< ""
	system("pause");
	return 0;
}
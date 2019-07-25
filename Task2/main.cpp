#include <iostream>
#include <vector>
#include "Classes.h"
using namespace std;

int main()
{
	Car car("Audi", 30);
	Horse horse("Star", "Black", 5);
	vector<IDriveble*> garage;
	garage.push_back(&car);
	garage.push_back(&horse);
	Driver driver("John", garage);
	driver.TestDrive();
	system("pause");
	return 0;
}
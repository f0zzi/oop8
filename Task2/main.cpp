#include <iostream>
#include "Classes.h"
using namespace std;

int main()
{
	Car car("Car", 30);
	Horse horse("Star", "Black", 5);

	IDriveble* d = &car;
	d->Go();
	d->Stop();
	d->UpSpeed(10);
	d->DownSpeed(5);

	d = &horse;
	d->Go();
	d->Stop();
	d->UpSpeed(10);
	d->DownSpeed(5);
	d->DownSpeed(10);

	//Driver driver("John");
	//driver.SetVehicle(d);
	//driver.TestDrive();

	//cout<< ""
	system("pause");
	return 0;
}
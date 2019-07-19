#include <iostream>
#include "Classes.h"
using namespace std;

int main()
{
	Amphibia a("car/ship", 20, 4, 2);
	cout << a.Car::GetSpeed() << endl;
	cout << "Set doors 10." << endl;
	a.SetDoors(10);
	a.Print();
	a.Car::SetSpeed(11);
	a.Vehicle::GetBrand();
	system("pause");
	return 0;
}
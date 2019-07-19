#include <iostream>
#include "Classes.h"
using namespace std;

int main()
{
	Amphibia a("car", 10, "ship", 5, 2, 2);
	a.Print();
	cout << "Set doors 10." << endl;
	a.Car::SetDoors(10);
	a.Print();
	a.Car::SetSpeed(11);
	system("pause");
	return 0;
}
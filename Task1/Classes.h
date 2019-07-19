#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
	string brand;
	int speed;
public:
	Vehicle(string brand = "Noname", int speed = 1) : brand(brand)
	{
		SetSpeed(speed);
	}
	int GetSpeed() const
	{
		return speed;
	}
	void SetSpeed(int speed)
	{
		if (speed > 0)
			this->speed = speed;
	}
	void Print() const
	{
		cout << "Brand: " << brand << "\tSpeed: " << speed << endl;
	}
};

class Car : public Vehicle
{
private:
	int doors;
public:
	Car(string brand, int speed, int doors = 4) : Vehicle(brand, speed)
	{
		SetDoors(doors);
	}
	int GetDoors() const
	{
		return doors;
	}
	void SetDoors(int doors)
	{
		if (doors > 0)
			this->doors = doors;
	}
	void Print() const
	{
		cout << "Car\t" << "Brand: " << brand << "\tSpeed: " << speed << "\tDoors: " << doors << endl;
	}
};

class Ship : public Vehicle
{
private:
	int turbines;
public:
	Ship(string brand, int speed, int turbines = 2) : Vehicle(brand, speed)
	{
		SetTurbines(turbines);
	}
	int GetTurbines() const
	{
		return turbines;
	}
	void SetTurbines(int turbines)
	{
		if (turbines > 0)
			this->turbines = turbines;
	}
	void Print() const
	{
		cout << "Ship\t" << "Brand: " << brand << "\tSpeed: " << speed << "\tTurbines: " << turbines << endl;
	}
};

class Amphibia : public Car, public Ship
{
public:
	Amphibia(string cName, int cSpeed, string sName, int sSpeed, int doors, int turbines) :
		Car(cName, cSpeed, doors), Ship(sName, sSpeed, turbines) {}
	void Print() const
	{
		cout << "Amphibia:\n";
		Car::Print();
		Ship::Print();
	}
};
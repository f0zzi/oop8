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
	Vehicle(string brand, int speed) : brand(brand)
	{
		SetSpeed(speed);
	}
	void SetBrand(const string& brand)
	{
		if (brand.size())
			this->brand = brand;
	}
	string GetBrand() const
	{
		return brand;
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
		cout << "Brand: " << GetBrand() << "\tSpeed: " << GetSpeed() << endl;
	}
};

class Car : virtual public Vehicle
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
		Vehicle::Print();
		cout << "Car\t" << "Doors: " << GetDoors() << endl;
	}
};

class Ship : virtual public Vehicle
{
private:
	int turbines;
	int waterSpeed;
public:
	Ship(string brand, int speed, int waterSpeed, int turbines = 2) : Vehicle(brand, speed), waterSpeed(waterSpeed)
	{
		SetTurbines(turbines);
	}
	void SetWaterSpeed(int waterSpeed)
	{
		if (waterSpeed > 0)
			this->waterSpeed = waterSpeed;
	}
	int GetWaterSpeed() const
	{
		return waterSpeed;
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
		Vehicle::Print();
		cout << "Ship\t" << "Turbines: " << GetTurbines() << "\tWaterspeed: " << waterSpeed << endl;
	}
};

class Amphibia : public Car, public Ship
{
public:
	Amphibia(string name, int speed, int waterspeed, int doors, int turbines) :
		Vehicle(name, speed), Car(name, speed, doors), Ship(name, speed, waterspeed, turbines) {}
	void Print() const
	{
		cout << "Amphibia:\n";
		Vehicle::Print();
		cout << "Doors: " << Car::GetDoors() << "\tTurbines: " << Ship::GetTurbines() << "\tWaterspeed: " << Ship::GetWaterSpeed() << endl;
	}
};
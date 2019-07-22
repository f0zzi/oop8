#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
__interface IDriveble
{
	void Go();
	void UpSpeed(int speed);
	void DownSpeed(int speed);
	void Stop();
};

class Car : public IDriveble
{
private:
	const int MAX_SPEED = 200;
	string brand;
	int speed;
public:
	Car(string brand = "Audi", int speed = 100) : brand(brand)
	{
		SetSpeed(speed);
	}
	int GetSpeed() const
	{
		return speed;
	}
	void SetSpeed(int speed)
	{
		if (speed >= 0)
			this->speed = speed;
		else
			this->speed = 0;
	}
	void Go()
	{
		cout << brand << "\tI am going " << speed << " km/h." << endl;
	}
	void UpSpeed(int speed = 10)
	{
		if (speed > 0)
		{
			SetSpeed(this->speed + speed);
			cout << brand << "\tSpeeding up. Speed: " << this->speed << endl;
		}
	}
	void DownSpeed(int speed = 10)
	{
		if (speed > 0)
		{
			SetSpeed(this->speed - speed);
			cout << brand << "\tSlowing down. Speed: " << this->speed << endl;
		}
	}
	void Stop()
	{
		SetSpeed(0);
		cout << brand << "\tStoping. Speed: " << this->speed << endl;
	}
};

class Horse : public IDriveble
{
private:
	const int MAX_SPEED = 50;
	string name;
	string color;
	int speed;
public:
	Horse(string name = "Star", string color = "black", int speed = 5) : name(name), color(color)
	{
		SetSpeed(speed);
	}
	string GetType() const
	{
		return typeid(*this).name();
	}
	int GetSpeed() const
	{
		return speed;
	}
	void SetSpeed(int speed)
	{
		if (speed >= 0)
			this->speed = speed;
		else if (speed > MAX_SPEED)
			this->speed = MAX_SPEED;
		else
			this->speed = 0;
	}
	void Go()
	{
		if (speed == 0)
			speed = 40;
		cout << name << "\t" << color << "\tI am going " << speed << " km/h." << endl;
	}
	void UpSpeed(int speed = 5)
	{
		if (speed > 0)
		{
			SetSpeed(this->speed + speed);
			cout << name << "\t" << color << "\tSpeeding up. Speed: " << this->speed << endl;
		}
	}
	void DownSpeed(int speed = 5)
	{
		if (speed > 0)
		{
			if (this->speed > speed)
			{
				SetSpeed(this->speed - speed);
				cout << name << "\t" << color << "\tSlowing down. Speed: " << this->speed << endl;
			}
			else
				Stop();
		}
	}
	void Stop()
	{
		SetSpeed(0);
		cout << name << "\t" << color << "\tStoping. Speed: " << this->speed << endl;
	}
};

class Driver
{
	string name;
	IDriveble* vehicle;
	vector<IDriveble*> garage;
public:
	Driver(string name, IDriveble* vehicle = nullptr) : name(name)
	{
		SetVehicle(vehicle);
	}
	void SetVehicle(IDriveble* vehicle)
	{
		if (vehicle != nullptr)
			this->vehicle = vehicle;
	}
	void SetGarage(vector<IDriveble*>& garage)
	{
		if (garage.size() > 0)
			this->garage = garage;
		garage.clear();
	}
	void TestDrive() const
	{
		if (vehicle != nullptr)
		{
			int selection;
			bool vehType = true;
			do {
				system("cls");
				cout << "You are siting " << (vehType ? "int the car." : "on the horse.") << endl;
				cout << "1 - Go.\n";
				cout << "2 - Speed up.\n";
				cout << "3 - Slow down.\n";
				cout << "4 - Stop.\n";
				cout << "5 - Change vehicle.\n";
				cout << "0 - Exit.\n";
				cout << "Your action: ";
				cin >> selection;
				switch (selection)
				{
				case 1:
					vehicle->Go();
					break;
				case 2:
					vehicle->UpSpeed(10);
					break;
				case 3:
					vehicle->DownSpeed(10);
					break;
				case 4:
					vehicle->Stop();
					break;
				case 5:
					break;
				case 0:
					cout << "Have a nice day.\n";
					break;
				default:
					cout << "Invalid input. Try again.\n";
					system("pause");
					break;
				}
			} while (selection != 0);
		}
	}
};
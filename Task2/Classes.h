#pragma once
#include <iostream>
#include <string>
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
	const int MAX_SPEED = 300;
	string brand;
	int speed;
public:
	Car(string brand = "Audi", int speed = 40) : brand(brand)
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
	void TestDrive() const
	{
		if (vehicle != nullptr)
		{
			vehicle->Go();
			vehicle->Stop();
			vehicle->UpSpeed(10);
			vehicle->DownSpeed(5);
		}
	}
};
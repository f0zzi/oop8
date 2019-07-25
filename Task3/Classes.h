#pragma once
#include <iostream>
#include <string>
using namespace std;

class Grandpa
{
private:
	string name;
public:
	Grandpa(string name = "Grandpa")
	{
		SetName(name);
	}
	void SetName(string name)
	{
		if (name.size())
			this->name = name;
	}
	virtual void Sleep()
	{
		cout << name << " is sleeping." << endl;
	}
};

class Daddy: public Grandpa
{
private:
	string name;
public:
	Daddy(string name = "Daddy")
	{
		SetName(name);
	}
	virtual void Sleep()
	{
		cout << name << " is sleeping." << endl;
	}
	virtual void Walk()
	{
		cout << name << " is walking." << endl;
	}
};

class Son : public Daddy
{
private:
	string name;
public:
	Son(string name = "Son")
	{
		SetName(name);
	}
	virtual void Sleep()
	{
		cout << name << " is sleeping." << endl;
	}
	virtual void Walk()
	{
		cout << name << " is walking." << endl;
	}
	virtual void Play()
	{
		cout << name << " is palying." << endl; 
	}
};
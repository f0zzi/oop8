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
	string GetName() const
	{
		return name;
	}
	virtual void Sleep()
	{
		cout << name << " is sleeping." << endl;
	}
};

class Daddy : public Grandpa
{
public:
	Daddy(string name = "Daddy") : Grandpa(name) {}
	virtual void Sleep()
	{
		cout << GetName() << " is sleeping." << endl;
	}
	virtual void Walk()
	{
		cout << GetName() << " is walking." << endl;
	}
};

class Son : public Daddy
{
public:
	Son(string name = "Son") : Daddy("Son") {}
	virtual void Sleep()
	{
		cout << GetName() << " is sleeping." << endl;
	}
	virtual void Walk()
	{
		cout << GetName() << " is walking." << endl;
	}
	virtual void Play()
	{
		cout << GetName() << " is playing." << endl;
	}
};
#include <iostream>
#include <vector>
#include "Classes.h"
using namespace std;

void Call(vector<Grandpa*>& family);
void CallStatic(vector<Grandpa*>& family);

int main()
{
	Grandpa gr;
	Daddy d;
	Son s;
	vector<Grandpa*> family;
	family.push_back(&gr);
	family.push_back(&d);
	family.push_back(&s);
	cout << "-------------------	dynamic_cast	----------------------" << endl;
	Call(family);
	cout << "--------------------	static_cast		----------------------" << endl;
	CallStatic(family);

	system("pause");
	return 0;
}

void Call(vector<Grandpa*>& family)
{
	Grandpa* pgr;
	Daddy* pd;
	Son* ps;
	for (int i = 0; i < family.size(); i++)
	{
		if (ps = dynamic_cast<Son*>(family[i]))
			ps->Play();
		if (pd = dynamic_cast<Daddy*>(family[i]))
			pd->Walk();
		if (pgr = dynamic_cast<Grandpa*>(family[i]))
			pgr->Sleep();
	}
}

void CallStatic(vector<Grandpa*>& family)
{
	for (int i = 0; i < family.size(); i++)
	{
		if (typeid(Son) == typeid(*family[i]))
		{
			static_cast<Son*>(family[i])->Play();
			static_cast<Son*>(family[i])->Walk();
			static_cast<Son*>(family[i])->Sleep();
		}
		if (typeid(Daddy) == typeid(*family[i]))
		{
			static_cast<Daddy*>(family[i])->Walk();
			static_cast<Daddy*>(family[i])->Sleep();
		}
		if (typeid(Grandpa) == typeid(*family[i]))
		{
			static_cast<Grandpa*>(family[i])->Sleep();
		}
	}
}

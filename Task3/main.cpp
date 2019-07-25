#include <iostream>
#include <vector>
#include "Classes.h"
using namespace std;

void Call(vector<Grandpa*>& family);

int main()
{
	Grandpa gr;
	Daddy d;
	Son s;
	vector<Grandpa*> family;
	family.push_back(&gr);
	family.push_back(&d);
	family.push_back(&s);
	Call(family);
	system("pause");
	return 0;
}

void Call(vector<Grandpa*>& family)
{
}

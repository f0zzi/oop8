#include <iostream>
#include "Class.h"
using namespace std;

int main()
{
	//� - �����(const char* t = �my text�) - ���������
	//const char* t = "my text";
	//char* tmp1 = const_cast<char*>(&t);
	//tmp1[0] = 'W';
	//cout << t << endl;

	//�++ - �����(const string * ps = new string(�my test�))
	const string* ps = new string("my test");
	const_cast<string*>(ps)->replace(0, 1, "W");
	cout << *ps << endl;

	//��������� ���������� �����(const  int field)
	Tmp tmp;
	*(const_cast<int*>(tmp.GetField())) = 5;
	cout << *tmp.GetField() << endl;

	system("pause");
	return 0;
}
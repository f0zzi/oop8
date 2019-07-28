#pragma once
class Tmp
{
private:
	const int field = 1;
public:
	const int* GetField() const
	{
		return &field;
	}
};
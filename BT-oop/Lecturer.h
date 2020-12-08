#pragma once
#include "Person.h"
#include <algorithm>

class Lecturer : public Person
{
private:
	string lecturerId;
	string capbac;
public:
	Lecturer(string = "", int = 0, string = "", bool = false, string = "", string = "");
	~Lecturer();
	string getTen();
	string getLecturerId();
	void setId();
	friend istream& operator>>(istream&, Lecturer&);
	friend ostream& operator<<(ostream&, const Lecturer&);
};

#include "Person.h"

Person::Person(string ten, int tuoi, string dc,bool gt)
:ten(ten),tuoi(tuoi),diachi(dc),gioitinh(gt)
{

}

Person::~Person(){}

void Person::show()
{
	cout << "Ten :" << this->ten << endl
		<< "Tuoi: " << this->tuoi << endl
		<< "Gioi tinh: " << ((this->gioitinh) ? "Nam" : "Nu") << endl
		<< "Dia chi: " << this->diachi << endl;
}

#include "Lecturer.h"

Lecturer::Lecturer(string ten, int tuoi, string diachi, bool gioitinh,string malecturer,string capbac)
:Person(ten,tuoi,diachi,gioitinh)
{
  this->lecturerId = malecturer;
  this->capbac = capbac;
}
Lecturer::~Lecturer()
{}

string Lecturer::getTen()
{
	return this->ten;
}

string Lecturer::getLecturerId()
{
  return this->lecturerId;
}

void Lecturer::setId()
{
	int count = 0;
	string tmp = this->ten;
	string s = "";
	s = s + "102";
	string substr = "";
	for (int i = 0; i < this->ten.length(); i++)
	{
		if (this->ten.at(i) == ' ') count++;
	}
	transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) { return tolower(c); });
	substr += tmp.at(0);
	for (int i = 0; i < this->ten.length(); i++)
	{
		if (tmp.at(i) == ' ' && count > 1)
		{
			++i;
			substr += tmp.at(i);
			count--;
		}
		else if (tmp.at(i) == ' ' && count == 1)
		{
			++i;
			substr += tmp.substr(i, this->ten.length());
			break;
		}
	}
	s += substr;
	this->lecturerId = s;
}

ostream& operator<<(ostream& o, const Lecturer& l)
{
	o << "Ma lecturer: " << l.lecturerId << endl
		<< "Ten: " << l.ten <<endl
		<< "Tuoi: " << l.tuoi << endl
		<< "Gioi tinh: " << ((l.gioitinh)?"Nam":"Nu") << endl
		<< "Cap bac: " << l.capbac << endl
		<< "Dia chi: " << l.diachi << endl;
  return o;
}

istream& operator>>(istream& i, Lecturer& l)
{
  cout<<"Ten: ";
  fflush(stdin);
  getline(i, l.ten);
  cout<<"Tuoi: "; i>>l.tuoi;
  cout<<"Gioi tinh: "; i>>l.gioitinh;
  cout<<"Cap bac: ";
  i.ignore();
  getline(i, l.capbac);
  cout<<"Dia chi: ";
  fflush(stdin);
  getline(i, l.diachi);
  l.setId();
  return i;
}
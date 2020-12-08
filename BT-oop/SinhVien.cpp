#include "SinhVien.h"

SinhVien::SinhVien(string ten,int tuoi, string add,bool gender,string msv,double dtb)
:Person(ten,tuoi,diachi,gioitinh)
{
  this->lop = nullptr;
  this->msv = msv;
  this->dtb = dtb;
}

SinhVien::~SinhVien()
{
}

string SinhVien::getId()
{
    return this->msv;
}

string SinhVien::getTen()
{
    return this->ten;
}

void SinhVien::show()
{
    cout << "MSV: " << this->msv << endl
        << "Ten :" << this->ten << endl
        << "Tuoi: " << this->tuoi << endl
        << "Gioi tinh: " << ((this->gioitinh) ? "Nam" : "Nu") << endl
        << "Dia chi: " << this->diachi << endl
        << "DTB: " << this->dtb << endl;
}

void SinhVien::addLop(LopSinhHoat<SinhVien,Lecturer>* l)
{
  (this->lop) = l;
}

void SinhVien::setMSV(istream& i)
{
  cout<<"MSV: ";
  fflush(stdin);
  i >> this->msv;
  if(msv.front() == '0' || !(msv.size() == 10))
  {
    throw string("MSV khong hop le.\n"); 
  }
}

void SinhVien::setGT(istream& i)
{
  cout<<"Gioi tinh: ";
  i>>this->gioitinh;
  if(i.fail())
  {
    i.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    throw string("Gioi tinh phai la 0 hoac 1.");
  }
}

void SinhVien::setDTB(istream& i)
{
  cout<<"Diem trung binh: ";
  i>>this->dtb;
  if(i.fail())
  {
    i.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    throw string("Du lieu khong hop le.");
  }
  else if(this->dtb < 0.0 || this->dtb > 4.0)
  {
    throw string("DTB phai nam trong khoang 0 -> 4.");
  }
}

bool SinhVien::operator>(SinhVien& sv) 
{
    return (this->dtb > sv.dtb);
}

bool SinhVien::operator<(SinhVien& sv)
{
    return (this->dtb < sv.dtb);
}

//void SinhVien::operator=(const SinhVien& sv)
//{
//    this->ten = sv.ten;
//    this->tuoi = sv.tuoi;
//    this->diachi = sv.diachi;
//    this->dtb = sv.dtb;
//    this->msv = sv.msv;
//    this->lop = sv.lop;
//}

ostream& operator<<(ostream& o,const SinhVien& sv)
{
  o<<"MSV: "<<sv.msv<<endl
  <<"Ten: "<<sv.ten<<endl
  <<"Tuoi: "<<sv.tuoi<<endl
  <<"Gioi tinh: "<<((sv.gioitinh)?"Nam":"Nu")<<endl
  <<"Dia chi: "<<sv.diachi<<endl
  <<"Lop: "<< (sv.lop)->tenlop<<" Diem trung binh: "<<sv.dtb<<endl;
  return o;
}

istream& operator>>(istream& i, SinhVien& sv)
{
  bool k;
  do
  {
    k = true;
    try
    {
      sv.setMSV(i);
    }
    catch(string s)
    {
      k = false;
      cout<< s <<endl;
    }
  } while (!k);
  cout<<"Ten: ";
  i.ignore();
  getline(i, sv.ten);
  cout << "Tuoi: ";
  i >> sv.tuoi;
  do
  {
    k = true;
    try
    {
      sv.setGT(i);
    }
    catch(string s)
    {
      k = false;
      cout<<s<<endl;
    }
  } while (!k);
  cout<<"Dia chi: ";
  i.ignore();
  getline(i,sv.diachi);
  do
  {
    k = true;
    try
    {
      sv.setDTB(i);
    }
    catch(string s)
    {
      k = false;
      cout<< s <<endl;
    }
  } while (!k);
  return i;
}



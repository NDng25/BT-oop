#pragma once
#include "Person.h"
#include "Lecturer.h"
#include "LopSinhHoat.h"
class Lecturer;
template<class T, class V>
class LopSinhHoat;
class SinhVien : public Person
{
private:
  string msv;
  LopSinhHoat<SinhVien,Lecturer>* lop;
  double dtb;
  void addLop(LopSinhHoat<SinhVien,Lecturer>*);
public:
  SinhVien(string = "",int = 0,string = "",bool = true,string = "",double = 0.0);
  ~SinhVien();
  string getId();
  string getTen();
  void show();
  friend istream& operator>>(istream&,SinhVien&);
  friend ostream& operator<<(ostream&,const SinhVien&);
  void setMSV(istream&);
  void setGT(istream&);
  void setDTB(istream&);
  bool operator> (SinhVien&);
  bool operator< (SinhVien&);
//  void operator=(const SinhVien&);
  template<class T, class V>
  friend class LopSinhHoat;
};
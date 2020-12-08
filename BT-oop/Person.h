#pragma once
#include <string>
#include <iostream>
#include <limits>
using namespace std;
class Person
{
protected:
  string ten;
  int tuoi;
  string diachi;
  bool gioitinh;
public:
  Person(string = "",int = 0,string = "",bool = "");
  ~Person();
  virtual void show();
};
#pragma once
//#include "SinhVien.h"
#include "Lecturer.h"
#include <algorithm>
#include <assert.h>

//template<class T, class V> class LopSinhHoat;
//
//template<class T, class V> ostream& operator<<(ostream&, const LopSinhHoat<T, V>&);

class T;
template<class T,class V>
class LopSinhHoat
{
private:
	string tenlop;
	T** dssv;
	V* gvcn;
	int size;
public:
	LopSinhHoat(string = "");
	~LopSinhHoat();
//	void setTen(istream&);
	string getTen();
	void addGVCN(V*);
	void Insert(T*,int);
	void InsertFirst(T*);
	void InsertLast(T*);
	void UpdateSV(int);
	void UpdateGV();
	void RemoveAt(int);
	void Erase();
	void Display();
	int Search(string);
	void Sort(bool(*cmp)(T&, T&));
	template<class U, class I>
	friend ostream& operator<<(ostream&, const LopSinhHoat<U,I>&);
	template<class A,class B>
	friend istream& operator>>(istream&, LopSinhHoat<A,B>&);
	friend ostream& operator<<(ostream&, const T&);
	void operator=(const LopSinhHoat<T, V>&);
	T& operator[](int);
};




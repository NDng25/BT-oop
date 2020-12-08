#include "LopSinhHoat.h"

template<class T, class V>
LopSinhHoat<T, V>::LopSinhHoat(string name)
:tenlop(name)
{
	this->dssv = nullptr;
	this->gvcn = nullptr;
	this->size = 0;
}
template<class T, class V>
LopSinhHoat<T, V>::~LopSinhHoat()
{
	delete[] this->dssv;
}
//template<class T, class V>
//void LopSinhHoat<T, V>::setTen(istream& i)
//{
//	cout << "Nhap ten lop: ";
//	fflush(stdin);
//	i >> this->tenlop;
//}

template<class T, class V>
string LopSinhHoat<T, V>::getTen()
{
	return this->tenlop;
}

template<class T, class V>
void LopSinhHoat<T, V>::InsertLast(T* sv)
{
	Insert(sv, this->size);
}

template<class T, class V>
void LopSinhHoat<T, V>::addGVCN(V* l)
{
	if (this->gvcn == nullptr)
	{
		this->gvcn = l;
	}
	else throw string("Lop da co GVCN.\n");
}

template<class T, class V>
void LopSinhHoat<T, V>::Insert(T* sv, int k)
{
	assert(k >= 0 && k <= this->size);
	T** tmp = new T*[this->size + 1];
	for (int i = 0; i < k; i++)
	{
		tmp[i] = *(this->dssv + i);
	}
	*(tmp + k) = sv;
	for (int i = k; i < this->size; i++)
	{
		tmp[k + 1] = *(this->dssv + i);
	}
	delete[] this->dssv;
	this->dssv = tmp;
	sv->addLop(this);
	this->size++;
}
template<class T, class V>
void LopSinhHoat<T, V>::InsertFirst(T* sv)
{
	Insert(sv, 0);
}
template<class T, class V>
void LopSinhHoat<T, V>::UpdateSV(int k)
{
	if (k < this->size)
	{
		try
		{
			cin >> (*this)[k];
		}
		catch(string e)
		{
			cout<<e;
		}
	}
	else
	{
		cout << "Khong co sinh vien " << k << "." << endl;
	}
}
template<class T, class V>
void LopSinhHoat<T, V>::UpdateGV()
{
	if (this->gvcn != nullptr)
	{
	cout << "Update GVCN:" << endl;
		try
		{
			cin >> *(this->gvcn);
		}
		catch(string e)
		{
			cout<<e;
		}
	}
	else
	{
		cout << "Chua co GVCN." << endl;
	}
}
template<class T, class V>
void LopSinhHoat<T, V>::RemoveAt(int index) // Xoa sinh vien tai vi tri index
{
	assert(index >= 0 && index < this->size);
	if (this->size == 1)
	{
		Erase();
		return;
	}
	T** tmp = new T * [this->size - 1];
	for (int i = 0; i < index; i++)
	{
		tmp[i] = *(this->dssv + i);
	}
	for (int i = index + 1; i < this->size; i++)
	{
		tmp[i - 1] = *(this->dssv + i);
	}
	delete[] this->dssv;
	this->dssv = tmp;
	this->size--;
}
template<class T, class V>
void LopSinhHoat<T, V>::Erase() //Xoa toan bo dssv
{
	delete[] this->dssv;
	this->dssv = nullptr;
	this->size = 0;
}
template<class T, class V>
void LopSinhHoat<T, V>::Display()
{
	cout << "\nThong tin lop:" << endl;
	cout << "Ten Lop: " << this->tenlop << endl
		<< "Si so sinh vien: " << this->size << endl
		<< "GVCN: " << endl
		<< *(this->gvcn) << endl
		<< "Danh sach sinh vien:" << endl;
	for (int i = 0; i < this->size; i++)
	{
		cout << (*this)[i];
		cout << "--------------------------------------"<<endl;
	}
}
template<class T, class V>
int LopSinhHoat<T, V>::Search(string msv) //Tra ve vi tri cua sv co msv 
{
	for (int i = 0; i < this->size; i++)
	{
		if ((*this)[i].getId() == msv)
		{
			cout << (*this)[i];
			return i;
		}
	}
	return -1;
}

template<class T, class V>
void LopSinhHoat<T, V>::Sort(bool (*cmp)(T& , T&))
{
	for (int i = 0; i < this->size -1; i++)
	{
		for (int j = i + 1; j < this->size; j++)
		{
			if (cmp((*this)[i], (*this)[j]))
			{
				swap(*(this->dssv + i), *(this->dssv + j));
			}
		}
	}
}

template<class T, class V>
void LopSinhHoat<T, V>::operator=(const LopSinhHoat<T, V>& l)
{
	this->dssv = l.dssv;
	this->gvcn = l.gvcn;
	this->size = l.size;
	this->tenlop = l.tenlop;
	for (int i = 0; i < this->size; i++)
	{
		(*this)[i].addLop(this);
	}
}

template<class T, class V>
T& LopSinhHoat<T, V>::operator[](int i)
{
	return *(*(this->dssv + i));
}
template<class U, class I>
ostream& operator<<(ostream& o, const LopSinhHoat<U,I>& l)
{
	o << "\nThong tin lop:" << endl;
	o << "Ten Lop: " << l.tenlop << endl
		<< "Si so sinh vien: " << l.size << endl
		<< "GVCN: " << endl
		<< *(l.gvcn) << endl
		<< "Danh sach sinh vien:" << endl;
	for (int i = 0; i < l.size; i++)
	{
		o << (*l.dssv[i]);
		o << "--------------------------------------" << endl;
	}
	return o;
}
template<class A, class B>
istream& operator>>(istream& i, LopSinhHoat<A, B>& lsh)
{
	cout << "Nhap ten lop: ";
	getline(i, lsh.tenlop);
	cout << "Nhap thong tin GVCN: "<<endl;
	Lecturer* l = new Lecturer;
	i >> *l;
	lsh.addGVCN(l);
	return i;
}
template<class D>
bool up(D& a, D& b)
{
	return (a > b);
}
template<class D>
bool down(D& a, D& b)
{
	return (a < b);
}
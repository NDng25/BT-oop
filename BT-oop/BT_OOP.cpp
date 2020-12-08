#include <iostream>
#include "LopSinhHoat.cpp"
#include "SinhVien.h"
#include <iomanip>
#define MAX 500

LopSinhHoat<SinhVien, Lecturer> lsh;
SinhVien* arr[MAX];
int n = 0;

void ThongTinLop();
void SapXep();
void TimKiem();
void XoaSV();
void SuaThongTin();
void ThemSV();
void Menu();

int main()
{
    fflush(stdin);
    cin >> lsh;
    do 
    {
    Menu();
    } while (1);
    system("PAUSE");
    return 0;
}

void ThongTinLop()
{
    system("CLS");
    cout << lsh;
    system("PAUSE");
}

void SapXep()
{
    int ch;
    cout << "1. Sap xep theo diem tb tang dan." << endl
        << "2. Sap xep theo diem tb giam dan." << endl;
    cin >> ch;
    if (ch == 1) lsh.Sort(up);
    else lsh.Sort(down);
    lsh.Display();
    system("PAUSE");
}

void TimKiem()
{
    string s;
    int index;
    cout << "Nhap msv can tim: ";
    cin.ignore();
    cin >> s;
    index = lsh.Search(s);
    if (index == -1) cout << "Khong ton tai sv." << endl;
    else cout << lsh[index];
    system("PAUSE");
}

void XoaSV()
{
    string s;
    int index;
    cout << "Nhap msv can xoa: ";
    cin.ignore();
    cin >> s;
    index = lsh.Search(s);
    if (index == -1) cout << "Khong ton tai sv." << endl;
    else lsh.RemoveAt(index);
    system("PAUSE");
}

void SuaThongTin()
{
    char ch;
    int index;
    string s;
    cout << "1. Update thong tin SV." << endl
        << "2. Update thong tin GVCN." << endl
        << "Nhap lua chon: ";
    cin >> ch;
    switch (ch)
    {
    case '1': {
        cout << "Nhap msv: ";
        cin.ignore();
        cin >> s;
        index = lsh.Search(s);
        if (index) {
            cout << "Nhap thong tin chinh sua: " << endl;
            lsh.UpdateSV(index);
        }
        else cout << "Khong ton tai sv." << endl;
    } break;
    case '2': {
        lsh.UpdateGV();
    }
    default:
        break;
    }
    system("PAUSE");
}

void ThemSV()
{
    system("CLS");
    char ch;
    cout << "1. Them vao dau danh sach." << endl
        << "2. Them vao cuoi danh sach." << endl
        << "Nhap lua chon: ";
    cin >> ch;
    switch (ch)
    {
    case '1': {
        arr[n] = new SinhVien;
        cin >> *arr[n];
        lsh.InsertFirst(arr[n]);
        n++;
    } break;
    case '2': {
        arr[n] = new SinhVien;
        cin >> *arr[n];
        lsh.InsertLast(arr[n]);
        n++;
    } break;
    default: return;
    }
    system("PAUSE");
}

void Menu()
{
    system("CLS");
    char ch;
    cout << setw(8) <<"QUAN LY LOP SINH HOAT"<<endl;
    cout << "1. Hien thi thong tin lop." << endl
        << "2. Them sinh vien." << endl
        << "3. Sua thong tin." << endl
        << "4. Xoa sinh vien." << endl
        << "5. Tim sinh vien." << endl
        << "6. Sap xep danh sach sinh vien." << endl
        << "0. Thoat CT." << endl
        << "Nhap lua chon: ";
    cin >> ch;
    switch (ch)
    {
    case '1': ThongTinLop(); break;
    case '2': ThemSV(); break;
    case '3': SuaThongTin(); break;
    case '4': XoaSV(); break;
    case '5': TimKiem(); break;
    case '6': SapXep(); break;
    case '0': exit(1); break;
    default: Menu();
    }
}

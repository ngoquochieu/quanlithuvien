#include "ManageBooks.h"
#include<string>
#include<iostream>
#include"Book.h"
#include<iomanip>
#include<fstream>
#include<vector>
#include<Extension.h>
Extension extension;
using namespace std;
enum TheLoai
{
    ChinhtriPhapLuat = 1,
    KhoahoccongngheKinhte,
    Vanhocnghethuat,
    VanhoaxahoiLichsu,
    Giaotrinh,
    TruyenTieuthuyet,
    TamliTamlinhTongiao,
    ThieuNhi
};
ManageBooks::ManageBooks()
{
}

ManageBooks::~ManageBooks()
{

}
/* ngang 120 doc 25
    Ham in danh sach duoc tim thay
*/
void ManageBooks::display(vector<int> DS)
{
    cout<<setw(100)<<"Thong tin tat ca sach co trong thu vien"<<endl;
    cout<<"STT"<<setw(10)<<"Ma Sach"<<setw(50)<<"Ten Sach"<<setw(40)<<"The loai"<<setw(30)<<"Tac gia"<<setw(30)<<"Nha xuat ban"<<endl;

    for(int i = 0; i < DS.size(); i ++)
    {
        cout<<i+1<<setw(10)<<books[DS[i]].maSH<<setw(65)<<books[DS[i]].tenSH<<setw(35)<<books[DS[i]].theLoai<<setw(28)<<books[DS[i]].tacGia<<setw(23)<<books[DS[i]].NXB<<endl;
    }
    cout<<"Tong: "<<DS.size()<<endl<<endl;
    system("pause");
}

void ManageBooks::display()
{
   //In toan bo sach
    cout<<setw(100)<<"Thong tin tat ca sach co trong thu vien"<<endl;
    cout<<"STT"<<setw(10)<<"Ma Sach"<<setw(50)<<"Ten Sach"<<setw(40)<<"The loai"<<setw(30)<<"Tac gia"<<setw(30)<<"Nha xuat ban"<<endl;

    for(int i = 0; i < books.size(); i ++)
    {
        cout<<i+1<<setw(10)<<books[i].maSH<<setw(65)<<books[i].tenSH<<setw(35)<<books[i].theLoai<<setw(28)<<books[i].tacGia<<setw(23)<<books[i].NXB<<endl;
    }
    cout<<"Tong: "<<books.size()<<endl<<endl;
    system("pause");
}

// Them sach
void ManageBooks::addBook()
{
    //Dang loi cai pArr
    string pArr[] ={"Chinh Tri - Phap Luat",
        "Khoa Hoc Cong Nghe - Kinh Te",
        "Van Hoc Nghe Thuat",
        "Van Hoa Xa Hoi - Lich Lu",
        "Giao Trinh",
        "Truyen, Tieu Thuyet",
        "Tam li, Tam linh, Ton giao",
        "Thieu Nhi"
    };
    string maSH, tenSH, tacGia, theLoai, NXB;
    cin.seekg(0, ios::end);
    cin.clear();

    cout<<"Enter the information for the book one by one"<<endl;
    cout<<"Ten sach: ";getline(cin,tenSH);
    cout<<"Tac gia: ";getline(cin, tacGia);
    cout<<"The loai: "<<endl;

    for(int i = 0; i < 8; i ++)
        cout<<"     "<<i+1<<". "<<pArr[i]<<endl;
    int choice;
    bool check;
    do{
        cout<<"Enter options:";
        cin>>choice;
        check = false;
        switch(choice)
        {
            case ChinhtriPhapLuat:
            {
                theLoai = pArr[ChinhtriPhapLuat - 1];
                break;
            }
            case KhoahoccongngheKinhte:
            {
                theLoai = pArr[KhoahoccongngheKinhte - 1];
                break;
            }
            case Vanhocnghethuat:
            {
                theLoai = pArr[Vanhocnghethuat - 1];
                break;
            }
            case VanhoaxahoiLichsu:
            {
                theLoai = pArr[VanhoaxahoiLichsu];
                break;
            }
            case Giaotrinh:
            {
                theLoai = pArr[Giaotrinh - 1];
                break;
            }
            case TruyenTieuthuyet:
            {
                theLoai = pArr[TruyenTieuthuyet - 1];
                break;
            }
            case TamliTamlinhTongiao:
            {
                theLoai = pArr[TamliTamlinhTongiao - 1];
                break;
            }
            case ThieuNhi:
            {
                theLoai = pArr[ThieuNhi - 1];
                break;
            }

            default:
            {
                cout<<"Your choice invalid. PLS Try again"<<endl;
                check = true;
            }
        }
    }while(check == true);
    maSH = to_string(extension.randomID());
    cin.seekg(0, ios::end);
    cin.clear();
    cout<<"NXB: ";
    getline(cin,NXB);
    extension.format(tenSH);
    extension.format(tacGia);
    extension.format(NXB);
    Book book(maSH, tenSH, tacGia, theLoai, NXB);
    books.push_back(book);

}
// Xoa sach
void ManageBooks::deleteBook()
{
    cin.seekg(0, ios::end);
    cin.clear();
    string id;
    int n;
        cout<<"Nhap ma sach de xoa: ";
        getline(cin, id);
        cout<<"Ban co chac chan xoa hay khong 1/2(1.CO/2.KHONG): ";
        do{
            cin>>n;
            if(n != 1 and n != 2)
                cout<<"1.Khong hop le. Nhap lai: ";
            else
                break;
        }while(true);
        if (n == 1)
            for(int i = 0; i < books.size(); i ++)
                if(id == books[i].maSH)
                {
                    books.erase(books.begin() + i);
                    break;
                }
        else
            if(n == 2);
}

//Ham doc du lieu tu file
void ManageBooks::readToFile()
{
    string emptys, maSH, tenSH,  theLoai, tacGia, NXB;
    ifstream fi("D:\\Books.txt");
    getline(fi, emptys);
    while(!fi.eof())
    {
        getline(fi, maSH);
        getline(fi, tenSH);
        getline(fi, theLoai);
        getline(fi, tacGia);
        getline(fi, NXB);
        Book book(maSH, tenSH, tacGia, theLoai, NXB);
        books.push_back(book);
    }
    fi.close();


}

//Ham ghi du lieu vao file
void ManageBooks::writeToFile()
{
    ofstream fo("D:\\Books.txt");
    for(int i = 0; i < books.size(); i ++)
    {
        fo<<endl<<books[i].maSH<<endl<<books[i].tenSH<<endl<<books[i].theLoai<<endl<<books[i].tacGia<<endl<<books[i].NXB;
    }
    fo.close();
}

//Tim kiem sach theo Ma sach
vector<int> ManageBooks::searchBookID()
{
    cin.seekg(0, ios::end);
    cin.clear();
    string id;
    vector<int> DS;
    cout<<"Nhap ID sach ban muon tim kiem: ";
    getline(cin, id);
    for(int i = 0; i < books.size(); i ++)
    {
        if(id == books[i].maSH)
        {
            DS.push_back(i);
            break;
        }
    }
    return DS;
}

// Tim kiem theo ten sach
vector<int> ManageBooks::searchBookTenSH()
{
    cin.seekg(0, ios::end);
    cin.clear();
    string tenSH;
    vector<int> DS;
    cout<<"Nhap ten sach muon tim kiem: ";
    getline(cin, tenSH);
    extension.format(tenSH);
    for(int i = 0; i < books.size(); i++)
    {
        size_t pos = books[i].tenSH.find(tenSH);
        if(pos >= 0 and pos <= books[i].tenSH.size())
            DS.push_back(i);
    }
    return DS;
}

//Tim kiem theo ten tac gia
vector<int> ManageBooks::searchBookTacGia()
{
    cin.seekg(0, ios::end);
    cin.clear();
    string tacGia;
    vector<int> DS;
    cout<<"Nhap ten sach co tac gia muon tim kiem: ";
    getline(cin, tacGia);
    extension.format(tacGia);
    for(int i = 0; i < books.size(); i++)
    {
        size_t pos = books[i].tenSH.find(tacGia);
        if(pos >= 0 and pos <= books[i].tenSH.size())
            DS.push_back(i);
    }
    return DS;
}

//Tim kiem theo the loai
vector<int> ManageBooks::searchBookTheLoai()
{
    cin.seekg(0, ios::end);
    cin.clear();
    string theLoai;
    vector<int> DS;
    cout<<"Nhap the loai sach muon tim kiem: ";
    getline(cin, theLoai);
    extension.format(theLoai);
    for(int i = 0; i < books.size(); i++)
    {
        size_t pos = books[i].theLoai.find(theLoai);
        cout<<books[i].theLoai<<endl;
        if(pos >= 0 and pos <= books[i].theLoai.size())
            DS.push_back(i);
    }
    return DS;

}









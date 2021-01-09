#include "Menu.h"
#include <ManageBooks.h>
#include <ManagerReaders.h>
#include <Extension.h>
#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
//enum class LuaChon {QUANLISACH, QUANLIDOCGIA, QUANLIMUONTRA, EXIT};
enum class LuaChon {QUANLISACH, QUANLIDOCGIA, EXIT};
enum class LuaChonSach {INTOANBOSACH, THEMSACH, XOASACH, TIMSACH, SAVE, EXIT};
enum class TimKiem {TIMKIEMTHEOIDSACH, TIMKIEMTHEOTENSACH, TIMKIEMTHEOTHELOAI, TIMKIEMTHEOTACGIA, EXIT};
enum class DocGia {HIENTHITOANBODOCGIA, THEMDOCGIA, XOADOCGIA, UPDATE, SEARCH, SAVE, EXIT};
enum class UpdateDG {UPDATETENDOCGIA, UPDATESDT, EXIT};
enum class TimKiemDG {TIMKIEMTHEOID, TIMKIEMTHEOTEN, EXIT};
ManageBooks man;
ManagerReaders manRD;

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
void Menu::textColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}


Directional Menu::status(int n)
{
    if(n == 224){
        char key = getch();
        if(key == 72 )
            return Directional::UP;
        if(key == 80)
            return Directional::DOWN;
        if(key == 77)
            return Directional::RIGHT;
        if(key == 75)
            return Directional::LEFT;
    }
    else{
        if(n == 13)
            return Directional::ENTER;
        if(n == 8)
            return Directional::BACK;
        if(n == 27)
            return Directional::ESC;
    }
}

int Menu::menuOptions(char* pArr[], int n)
{
    int tt = 0; /* Biến chỉ ra đang ở thao tác thứ nhất */
    int* mau = new int(n);
    for(int i = 1; i < n; i ++)
        mau[i] = MAUCHU;
    mau[0] = 12; // Hiện tại đang ở thao tác thứ nhất
    while(true)
    {
        system("cls");
        for(int i = 0; i < n; i ++)
        {
            textColor(mau[i]);
            cout<<pArr[i]<<endl;
        }
        int key = getch();
        Directional _status = status(key);
        switch(_status)
        {
            case Directional::UP:
                {
                    if(tt == 0){
                        tt = n - 1;
                    }
                    else
                        tt--;
                    break;
                }
            case Directional::DOWN:
                {
                    if(tt == n - 1){
                        tt = 0;
                    }
                    else
                        tt++;
                    break;
                }
            case Directional::ENTER:
                {
                    return tt;
 //                   break;
                }
        }

        for(int i = 0; i < n; i ++)
            mau[i] = MAUCHU;
        mau[tt] = 12;
    }
}

void Menu::mainMenu()
{
 //  char* pArr[] ={"Quan li sach", "Quan li doc gia", "Quan li muon tra", "Exit"};
   char* pArr[] ={"Quan li sach", "Quan li doc gia", "Exit"};
   bool check = false;
   do{
        int choice = menuOptions(pArr, 3);
        system("cls");
        switch((LuaChon)choice)
        {
            case LuaChon::QUANLISACH:
            {
                menuManagerBooks();
                break;
            }
            case LuaChon::QUANLIDOCGIA:
            {
                menuManagerReaders();
                break;
            }
            case LuaChon::EXIT:
            {
                check = true;
                break;
            }

        }
   }while(!check);
}

void Menu::menuManagerBooks()
{
    man.readToFile();
    char* pArr[] = {"IN TOAN BO SACH", "THEM SACH", "XOA SACH" ,"TIM SACH", "SAVE", "EXIT"};
    bool check = false;
    do{
        int choice = menuOptions(pArr, 6);
//        delete []pArr;
        system("cls");
        switch((LuaChonSach)choice)
        {
            case LuaChonSach::INTOANBOSACH:
            {
                man.display();
                break;
            }

            case LuaChonSach::THEMSACH:
            {
                int n;
                do{
                    system("cls");
                    man.addBook();
                    cout<<"Ban co muon tiep tuc su dung chuc nang nay nua khong 1/2(1.CO/2.KHONG): ";
                    do{
                        cin.seekg(0, ios::end);
                        cin.clear();
                        cin>>n;
                        if(n != 1 and n != 2)
                            cout<<"Khong hop le. Nhap lai: ";
                        else
                            break;
                    }while(true);
                }while(n == 1);
                break;
            }

            case LuaChonSach::XOASACH:
            {
                int n;
                do{
                    system("cls");
                    man.display();
                    man.deleteBook();
                    cout<<"Ban co muon tiep tuc su dung chuc nang nay khong 1/2(1.CO/2.KHONG): ";
                    do{
                        cin>>n;
                        if(n != 1 and n != 2)
                            cout<<"Khong hop le. Nhap lai: ";
                    else
                        if(n == 2)
                            break;
                    }while(true);
                }while(n == 1);
                break;
            }

            case LuaChonSach::TIMSACH:
            {
                bool KT = false;//Bien kiem tra
                char* Timkiem[] = {"TIM KIEM THEO ID SACH", "TIM KIEM THEO TEN SACH", "TIM KIEM THEO THE LOAI" ,"TIM KIEM THEO TAC GIA", "EXIT"};
                do{
                    int choice = menuOptions(Timkiem, 5);
                    system("cls");
                    switch((TimKiem)choice)
                    {
                        case TimKiem::TIMKIEMTHEOIDSACH:
                        {
                            man.display(man.searchBookID());
                            break;
                        }

                        case TimKiem::TIMKIEMTHEOTENSACH:
                        {
                            man.display(man.searchBookTenSH());
                            break;
                        }
                        case TimKiem::TIMKIEMTHEOTHELOAI:
                        {
                            man.display(man.searchBookTheLoai());
                            break;
                        }
                        case TimKiem::TIMKIEMTHEOTACGIA:
                        {
                            man.display(man.searchBookTenSH());
                            break;
                        }
                        case TimKiem::EXIT:
                        {
                            KT = true;
                            break;
                        }
                    }
                }while(!KT);
                break;
            }
            case LuaChonSach::SAVE:
            {
                cout<<"Ban co chac chan luu khong 1/2(1.CO/2.KHONG):";
                int a;
                do{
                    cin>>a;
                    if(a != 1 and a != 2)
                        cout<<"Khong hop le. Hay nhap lai: ";
                    else {
                        man.writeToFile();
                        break;
                    };
                }while(true);
                break;
            }
            case LuaChonSach::EXIT:
            {
                check = true;
                break;
            }
        }
    }while(!check);
/*
Trong cac case khong duoc su dung cac bien khai bao trong trong case trung ten nhau
Vi khi ket thuc 1 case bien do ko mat di ma no se mang 1 gia tri rac nao no
Nen goi cac case vao {}
Solution: https://stackoverflow.com/questions/5685471/error-jump-to-case-label

*/

}

void Menu::menuManagerReaders()
{

    manRD.readFile();
    char* pArr[] = {"HIEN THI TOAN BO DOC GIA", "THEM DOC GIA", "XOA DOC GIA", "UPDATE", "SEARCH", "SAVE", "EXIT"};
    bool checkk = false;
    do{
        int choice = menuOptions(pArr, 7);
        system("cls");
        switch((DocGia)choice)
        {
            case DocGia::HIENTHITOANBODOCGIA:
            {
                manRD.display();
                break;
            }
            case DocGia::THEMDOCGIA:
            {
                int n;
                do{
                    system("cls");
                    manRD.addRD();
                    cout<<"Ban co muon tiep tuc su dung chuc nang nay nua khong 1/2(1.CO/2.KHONG): ";
                    do{
                        cin>>n;
                        if(n != 1 and n != 2)
                            cout<<"Khong hop le. Nhap lai: ";
                        else
                            break;
                    }while(true);
                }while(n == 1);
                break;
            }
            case DocGia::XOADOCGIA:
            {
                int n;
                do{
                    system("cls");
                    manRD.display();
                    manRD.deleteRD();
                    cout<<"Ban co muon tiep tuc su dung chuc nang nay nua khong 1/2(1.CO/2.KHONG): ";
                    do{
                        cin>>n;
                        if(n != 1 and n != 2)
                            cout<<"Khong hop le. Nhap lai: ";
                        else
                            break;
                    }while(true);
                }while(n == 1);
                break;
            }
            case DocGia::UPDATE:
            {
                bool check = false;
                char* arr[] = {"UPDATE TEN DOC GIA", "UPDATE SDT", "EXIT"};
                do{
                    int choice = menuOptions(arr, 3);
                    system("cls");
                    switch((UpdateDG)choice)
                    {
                        case UpdateDG::UPDATETENDOCGIA:
                        {
                            manRD.updateTenDG();
                            break;
                        }
                        case UpdateDG::UPDATESDT:
                        {
                            manRD.updateSDT();
                            break;
                        }
                        case UpdateDG::EXIT:
                        {
                            check = true;
                            break;
                        }
                    }
                }while(!check);
                break;
            }

            case DocGia::SEARCH:
            {
                char* arr[] = {"TIM KIEM THEO ID", "TIM KIEM THEO TEN", "EXIT"};
                bool KT = false;
                do{
                    int choice = menuOptions(arr, 3);
                    system("cls");
                    switch((TimKiemDG)choice)
                    {
                        case TimKiemDG::TIMKIEMTHEOTEN:
                        {
                            manRD.display(manRD.searchName());
                            break;
                        }
                        case TimKiemDG::TIMKIEMTHEOID:
                        {
                            manRD.display(manRD.searchID());
                            break;
                        }
                        case TimKiemDG::EXIT:
                        {
                            KT = true;
                            break;
                        }
                    }
                }while(!KT);
                break;
            }
            case DocGia::SAVE:
            {
                cout<<"Ban co chac chan luu khong 1/2(1.CO/2.KHONG):";
                int a;
                do{
                    cin>>a;
                    if(a != 1 and a != 2)
                        cout<<"Khong hop le. Hay nhap lai: ";
                    else {
                        manRD.writeFile();
                        break;
                    };
                }while(true);
                break;
            }
            case DocGia::EXIT:
            {
                checkk = true;
                break;
            }
        }
    }while(!checkk);
}
void Menu::menuManagerBorrow()
{

}





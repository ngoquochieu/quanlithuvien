#include "ManagerReaders.h"
#include "Extension.h"
#include "Reader.h"
#include<iostream>
#include<string>
#include<iomanip>
#include <vector>
#include<fstream>
using namespace std;
Extension ex;

ManagerReaders::ManagerReaders()
{
    //ctor
}

ManagerReaders::~ManagerReaders()
{
    //dtor
}
// Them 1 doc gia
void ManagerReaders::addRD()
{
    cin.seekg(0, ios::end);
    cin.clear();
    string maDG, tenDG, SDT, soThe;
    cout<<"Nhap ten doc gia: ";
    getline(cin, tenDG);
    //Bat buoc phai nhap
    ex.requiredToEnter(tenDG);
    //Dinh dang
    ex.format(tenDG);
    cout<<"Nhap SDT: ";
    do{
        getline(cin, SDT);
        if(ex.requiredToEnter(SDT))
            if(SDT.size() == 10 and SDT[0] == '0')
                break;
            else
                cout<<"Khong hop le. Nhap lai: ";
    }while(true);
    maDG = to_string(ex.randomID());
    soThe = to_string(ex.randomID() + 10);
    Reader reader(maDG, tenDG, SDT, soThe);
    readers.push_back(reader);
}

void ManagerReaders::deleteRD()
{
    cin.seekg(0, ios::end);
    cin.clear();
    string id;
    int n;
        cout<<"Nhap ma doc gia de xoa: ";
        getline(cin, id);
        ex.requiredToEnter(id);
        cout<<"Ban co chac chan xoa khong 1/2(1.CO/2.KHONG): ";
        do{
            cin>>n;
            if(n != 1 and n != 2)
                cout<<"Khong hop le. Nhap lai: ";
            else
                break;
        }while(true);
        if(n == 1)
            for(int i = 0; i < readers.size(); i ++)
                if(id == readers[i].maDG)
                {
                    readers.erase(readers.begin() + i);
                    break;
                }
}

void ManagerReaders::updateTenDG()
{
    cin.seekg(0, ios::end);
    cin.clear();

    string tenDG, id;
    bool check = false;
    cout<<"Nhap ma doc gia muon thay doi: ";
    getline(cin, id);
    ex.requiredToEnter(id);
    cout<<"Nhap ten doc gia thay doi: ";
    getline(cin, tenDG);
    ex.requiredToEnter(tenDG);
    ex.format(tenDG);
    for(int i = 0; i < readers.size(); i ++)
        if(readers[i].maDG == id)
        {
            check = true;
            readers[i].tenDG = tenDG;
            break;
        }
    if(check == false)
        cout<<"Ma doc gia khong tim thay";
}

void ManagerReaders::updateSDT()
{
     cin.seekg(0, ios::end);
    cin.clear();

    string SDT, id;
    bool check = false;

    cout<<"Nhap ma doc gia muon thay doi: ";
    getline(cin, id);
    ex.requiredToEnter(id);
    cout<<"Nhap SDT thay doi: ";
    do{
        getline(cin, SDT);
        if(ex.requiredToEnter(SDT))
            if(SDT.size() == 10 and SDT[0] == '0')
                break;
            else
                cout<<"Khong hop le. Nhap lai: ";
    }while(true);
    for(int i = 0; i < readers.size(); i ++)
        if(readers[i].maDG == id)
        {
            check = true;
            readers[i].SDT = SDT;
            break;
        }
    if(check == false)
        cout<<"Ma doc gia khong tim thay";
}


vector<int> ManagerReaders::searchID()
{
    string id;
    vector<int> DS;
    cout<<"Nhap ma doc gia muon tim kiem: ";
    getline(cin, id);
    ex.requiredToEnter(id);
    for(int i = 0; i < readers.size(); i ++)
        if(id == readers[i].maDG)
            DS.push_back(i);
    return DS;
}

vector<int> ManagerReaders::searchName()
{
    string tenDG;
    vector<int> DS;
    cout<<"Nhap ten doc gia muon tim kiem: ";
    getline(cin, tenDG);
    ex.requiredToEnter(tenDG);
    ex.format(tenDG);
    for(int i = 0; i < readers.size(); i ++)
    {
        size_t pos = readers[i].tenDG.find(tenDG);
        if(pos >= 0 and pos <= readers[i].tenDG.size())
            DS.push_back(i);
    }
    return DS;
}

void ManagerReaders::display()
{
    cout<<setw(70)<<"Thong tin doc gia"<<endl;
    cout<<" STT "<<setw(20)<<"Ma Doc Gia"<<setw(40)<<"Ten Doc Gia"<<setw(25)<<"So DT"<<setw(25)<<"So The"<<endl;
    for(int i = 0; i < readers.size(); i ++)
    {
        cout<<"  "<<i+1<<setw(19)<<readers[i].maDG<<setw(45)<<readers[i].tenDG<<setw(26)<<readers[i].SDT<<setw(21)<<readers[i].soThe<<endl;
      //  cout<<readers[i].maDG<<"    "<<readers[i].tenDG<<"      "<<readers[i].SDT<<"    "<<readers[i].soThe<<endl;
    }
    system("pause");
}

void ManagerReaders::display(vector<int>DS)
{
    cout<<setw(70)<<"Thong tin doc gia"<<endl;
    cout<<" STT "<<setw(20)<<"Ma Doc Gia"<<setw(40)<<"Ten Doc Gia"<<setw(25)<<"So DT"<<setw(25)<<"So The"<<endl;
    for(int i = 0; i < DS.size(); i ++)
    {
        cout<<"  "<<i+1<<setw(19)<<readers[DS[i]].maDG<<setw(45)<<readers[DS[i]].tenDG<<setw(26)<<readers[DS[i]].SDT<<setw(21)<<readers[DS[i]].soThe<<endl;
      //  cout<<readers[i].maDG<<"    "<<readers[i].tenDG<<"      "<<readers[i].SDT<<"    "<<readers[i].soThe<<endl;
    }
    system("pause");

}

void ManagerReaders::readFile()
{
    string emptys, maDG, tenDG,  SDT, soThe;
    ifstream fi("D:\\Readers.txt");
    getline(fi, emptys);
    while(!fi.eof())
    {
        getline(fi, maDG);
        getline(fi, tenDG);
        getline(fi, SDT);
        getline(fi, soThe);
        Reader reader(maDG, tenDG, SDT, soThe);
        readers.push_back(reader);
    }
    fi.close();
}

void ManagerReaders::writeFile()
{
    ofstream fo("D:\\Readers.txt");
    for(int i = 0; i < readers.size(); i ++)
    {
        fo<<endl<<readers[i].maDG<<endl<<readers[i].tenDG<<endl<<readers[i].SDT<<endl<<readers[i].soThe;
    }
    fo.close();
}





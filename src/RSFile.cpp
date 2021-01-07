#include "RSFile.h"
#include<iostream>
#include<fstream>
#include<Book.h>
using namespace std;
RSFile::RSFile()
{
    //ctor
}

RSFile::~RSFile()
{
    //dtor
}

void RSFile::readFile(ManageBooks &arr)
{
    ifstream fi("D:\\Books.txt", ios::in|ios::binary);
    while(!fi.eof())
    {
        fi.read((char*) &arr, sizeof(arr));
    }
    arr.display();
    fi.close();

}

void RSFile::writeFile(ManageBooks &arr)
{
    ofstream fo("D:\\Books.txt", ios::out|ios::binary);
    fo.write((char*) &arr, sizeof(arr));
    fo.close();
}

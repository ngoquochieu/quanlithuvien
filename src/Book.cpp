#include "Book.h"

Book::Book()
{
    //ctor
}

Book::~Book()
{
    //dtor
}
void Book::input()
{

}

void Book::display()
{

}

Book::Book(string maSH, string tenSH, string tacGia, string theLoai, string NXB)
{
    this->maSH = maSH;
    this->tenSH = tenSH;
    this->tacGia = tacGia;
    this->theLoai = theLoai;
    this->NXB = NXB;
}



#ifndef BOOK_H
#define BOOK_H
#include<string>
using namespace std;

class Book
{
    public:
        friend class ManageBooks;
        Book();
        Book(string maSH, string tenSH, string tacGia, string theLoai, string NXB);
        virtual ~Book();
        virtual void input();
        virtual void display();

    protected:
        string maSH, tenSH, tacGia, theLoai, NXB;

    private:

};

#endif // BOOK_H

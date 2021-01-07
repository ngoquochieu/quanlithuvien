#ifndef MANAGEBOOKS_H
#define MANAGEBOOKS_H
#include<vector>
#include "Book.h"


class ManageBooks:public Book{
    public:
        ManageBooks();
        virtual ~ManageBooks();
        void display(); // In toan bo sach
        void display(vector<int> DS);  // In sach
        void addBook();      // Them sach
        void deleteBook();   // Xoa
        vector<int> searchBookID(); // Tim kiem ID
        vector<int> searchBookTenSH(); // Tim kiem theo ten sach
        vector<int> searchBookTacGia();// Tim kiem theo ten tac gia
        vector<int> searchBookTheLoai(); // Tim kiem theo the loai
//        void searchBook
        void readToFile();
        void writeToFile();

    protected:
        vector<Book> books;
    private:

};

#endif // MANAGEBOOKS_H

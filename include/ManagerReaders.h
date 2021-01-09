#ifndef MANAGERREADERS_H
#define MANAGERREADERS_H
#include<Reader.h>
#include<vector>

class ManagerReaders:public Reader
{
    public:
        friend class QLThe;
        ManagerReaders();
        virtual ~ManagerReaders();
        void addRD();   //Them 1 doc gia
        void deleteRD();    // Xoa doc gia
        void updateTenDG();
        void updateSDT();
        vector<int> searchID();
        vector<int> searchName();
        void display();
        void display(vector<int> DS);
        void readFile();
        void writeFile();

    protected:
        vector<Reader> readers;

    private:
};

#endif // MANAGERREADERS_H

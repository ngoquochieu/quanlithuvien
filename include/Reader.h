#ifndef READER_H
#define READER_H
#include "ManageBooks.h"


class Reader
{
    public:
        friend class ManagerReaders;
        Reader();
        Reader(string maDG, string tenDG, string SDT, string soThe);
        virtual ~Reader();

    protected:
        string maDG, tenDG, SDT, soThe;

    private:
};

#endif // READER_H

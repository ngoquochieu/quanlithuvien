#ifndef RSFILE_H
#define RSFILE_H
#include<ManageBooks.h>

class RSFile
{
    public:
        friend class ManageBooks;
        RSFile();
        virtual ~RSFile();
        void readFile(ManageBooks &pArr);
        void writeFile(ManageBooks &pArr);

    protected:

    private:
};

#endif // RSFILE_H

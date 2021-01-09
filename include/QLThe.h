#ifndef QLTHE_H
#define QLTHE_H
#include<The.h>
#include <vector>



class QLThe
{
    public:
        QLThe();
        QLThe(string id);
        virtual ~QLThe();

    protected:
        vector<The> the;


    private:
};

#endif // QLTHE_H

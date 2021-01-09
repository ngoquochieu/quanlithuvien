#ifndef THE_H
#define THE_H
#include<string>
using namespace std;
class The
{
    public:
        friend class QLThe;
        The();
        The(string soThe, string ngayBD, string ngayHH);
        virtual ~The();

    protected:
        string soThe, ngayBD, ngayHH;

    private:
};

#endif // THE_H

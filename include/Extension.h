#ifndef EXTENSION_H
#define EXTENSION_H
#include<string>
using namespace std;
class Extension
{
    public:
        Extension();
        virtual ~Extension();
        void format(string &str);
        int randomID();
        bool requiredToEnter(string &str);
        bool isReuse(void(*reuse)());

    protected:

    private:
};

#endif // EXTENSION_H

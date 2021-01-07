#ifndef MENU_H
#define MENU_H
#define MAUNEN 176
#define MAUCHU 7
#include<string>
using namespace std;
enum class Directional{UP, DOWN, LEFT, RIGHT, ENTER, BACK, ESC};

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        int menuOptions(char* pArr[], int n);
        Directional status(int n);
        void textColor(int x);
        void mainMenu();
        void menuManagerBooks();
        void menuManagerReaders();
        void menuManagerBorrow();

    protected:


    private:
};

#endif // MENU_H

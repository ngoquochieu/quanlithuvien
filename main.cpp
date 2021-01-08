#include <iostream>
#include "Menu.h"
#include "ManageBooks.h"
#include "ManagerReaders.h"
#include<fstream>
using namespace std;

int main()
{
    Menu menu;
//    menu.menuManagerBooks();
    //cin.seekg(0, ios::end);
    //cin.clear();
    menu.menuManagerReaders();
    menu.menuManagerBooks();
    return 0;
}

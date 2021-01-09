#include <iostream>
#include "Menu.h"
#include "ManageBooks.h"
#include "ManagerReaders.h"
#include<fstream>
using namespace std;

int main()
{
    Menu menu;
    //cin.seekg(0, ios::end);
    //cin.clear();
    menu.mainMenu();
    return 0;
}

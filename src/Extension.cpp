#include "Extension.h"
#include<string>
#include<time.h>
#include<iostream>
#include<string>
using namespace std;

Extension::Extension()
{
    //ctor
}

Extension::~Extension()
{
    //dtor
}

void Extension::format(string& str)
{
    for(int i = 0; i < str.size(); i ++)
        if(str[i] >= 'A' and str[i] <= 'Z')
            str[i] += 32;

    while(str[0] == ' ' || str[0] == '\t'){
        str.erase(str.begin() + 0);
    }

    while(str[str.size() - 1] == ' ' || str[str.size() - 1] == '\t'){
        str.erase(str.begin() + str.size()-1);
    }

    for(int i = 0; i < str.size(); i ++)
        if(str[i] == '\t')
            str[i] = 32;

    for(int i = 0; i < str.size();)
    {
        if((str[i] == 32 and str[i + 1] == 32))
            str.erase(str.begin() + i);
        else
            i++;
    }
    for(int i = 0; i < str.size(); i ++)
        if(str[i] == 32)
            str[i+1] -= 32;
    str[0] -= 32;
}

//Ham random ma sach
int Extension::randomID() // Ham random [1000,9999]
{
/*
    - Ham srand(int seed) khi tham so seed thay doi thi se sinh ra cac so khac nhau
    - O day ta truyen vao tham so la thoi gia va ep kieu thanh int
*/
    srand((int)time(0));
    return 1000 + rand() % (9999 + 1 - 1000);
}
// Bat buoc phai nhap du lieu
bool Extension::requiredToEnter(string& str)
{
    while(true)
    {
        if(str.size() == 0)
            getline(cin, str);
        else
            break;
    }
    return true;
}


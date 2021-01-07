#include "Goto.h"
#include<windows.h>
Goto::Goto()
{
    //ctor
}

Goto::~Goto()
{
    //dtor
}

void Goto::gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}


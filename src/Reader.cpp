#include "Reader.h"

Reader::Reader()
{
    //ctor
}

Reader::~Reader()
{
    //dtor
}

Reader::Reader(string maDG, string tenDG, string SDT, string soThe)
{
    this->maDG = maDG;
    this->tenDG = tenDG;
    this->SDT = SDT;
    this->soThe = soThe;
}


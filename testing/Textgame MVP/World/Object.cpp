#include "../headers.h"
using namespace std ;

Object::Object(string name, string description, bool pickable )
{
    this->name = name ;
    this->description = description ;
    this->pickable = pickable ;
}

bool Object::Is_Path()
{
    return false ;
}

string Object::Get_name()
{
    return this->name ;
}

string Object::Get_description()
{
    return this->description ;
}

bool Object::Get_pickable()
{
    return this->pickable ;
}


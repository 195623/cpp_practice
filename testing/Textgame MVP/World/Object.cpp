#include "../headers.h"
using namespace std ;

Object::Object(string name, string description, string useDescription, bool pickable )
{
    this->name = name ;
    this->description = description ;
    this->useDescription = useDescription;
    this->pickable = pickable ;
}

std::string Object::Get_Used( Player* player )
{
    return this->Get_useDescription();
}

bool Object::Is_Path()
{
    return false ;
}

string Object::Display()
{
    return "    " + this->name ;
}

string Object::Get_name()
{
    return this->name ;
}

string Object::Get_description()
{
    return this->description ;
}

string Object::Get_useDescription()
{
    return this->useDescription ;
}

bool Object::Is_Pickable()
{
    return this->pickable ;
}


#include "../headers.h"
using namespace std ;

Direction::Direction(string name)
{
    this->name = name;
}

string Direction::Get_name()
{
    return this->name ;
}

int Direction::Get_SortingOrder()
{
    int order = 0 ;

    // count order

    return order ;
}

bool Direction::Is_Valid()
{
    bool output = false ;

    if ( name == "u" ) output = true ;

    if ( name == "nw" || name == "n" || name == "ne" ) output = true ;

    if ( name == "w" || name == "e" ) output = true ;

    if ( name == "sw" || name == "s" || name == "se" ) output = true ;

    if ( name == "d" ) output = true ;

    return output ;
}



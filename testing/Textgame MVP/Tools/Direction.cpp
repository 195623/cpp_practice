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

string dirs[] = {"u","nw","n","ne","w","e","sw","s","se","d"} ;

int Direction::Get_SortingOrder()
{
     // copy: Player::Is_Direction()

    for( unsigned int i = 0; i < sizeof(dirs)/sizeof(dirs[0]); i++ )
    {
        if( this->name == dirs[i] ) return i+1 ;
    }

    return -1 ;
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



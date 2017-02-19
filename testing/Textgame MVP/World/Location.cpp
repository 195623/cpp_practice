#include "../headers.h"
using namespace std;

Location::Location( string name, string description, vector<Object*> objects )
{
    this->name = name ;
    this->description = description ;
    this->objects = objects ;

}

void Location::Set_objects( vector<Object*> objects )
{
    this->objects = objects ;
}



string Location::Get_name()
{
    return this->name ;
}

string Location::Get_description()
{
    return this->description ;
}

vector<Object*> Location::Get_objects( string type )
{
    vector<Object*> output ;

    if ( type == "" ) return this->objects ;

    else if ( type == "Path" )
    {
        for( vector<Object*>::iterator it = this->objects.begin() ; it != this->objects.end() ; it++ )
        {
            if ( (*it)->Is_Path() ) output.push_back(*it) ;
        }
    }
    else cout << "Location::Get_objects( string type ): \"" << type << "\" is an invalid type.\n" ;

    return output ;

}


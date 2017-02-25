#include "../headers.h"
using namespace std;

Location::Location( string name, string description, vector<Object*> objects )
{
    this->name = name ;
    this->description = description ;
    this->container = new Container(objects);

}

Container* Location::Return_Container()
{
    return this->container ;
}

void Location::Set_objects( vector<Object*> objects )
{
    this->container = new Container(objects);
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
    vector<Object*> allObjects = container->Return_contents();

    if ( type == "" ) return allObjects ;

    else if ( type == "Path" )
    {
        for( vector<Object*>::iterator it = allObjects.begin() ; it != allObjects.end() ; it++ )
        {
            if ( (*it)->Is_Path() ) output.push_back(*it) ;
        }
    }
    else cout << "Location::Get_objects( string type ): \"" << type << "\" is an invalid type.\n" ;

    return output ;

}


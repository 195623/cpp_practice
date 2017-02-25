#include "../headers.h"

using namespace std ;

Path::Path( string name,
            string description,
            string useDescription,
            string directionName,
            string targetDirectory,
            Location* location ) : Object(name,description,useDescription,false)
{
    this->direction = new Direction(directionName) ;

    this->targetDirectory = targetDirectory ;
    this->location = location ;

    this->targetPointer = NULL ;

    if(!this->direction->Is_Valid()) cout << "\"" << Get_PathID() << "\" has an invalid directionName: \"" << directionName << "\"\n\n" ;
}

void Path::Set_targetPointer( Path* targetPointer )
{
    this->targetPointer = targetPointer ;
}

string Path::Get_directionName()
{
    return this->direction->Get_name() ;
}

Direction* Path::Get_direction()
{
    return this->direction ;
}

string Path::Get_PathID()
{
    if( location != NULL ) return location->Get_name() + '/' + this->name ;

    return "" ;
}

string Path::Get_targetDirectory()
{
    return this->targetDirectory ;
}

Path* Path::Get_targetPointer()
{
    return this->targetPointer ;
}

Location* Path::Get_location()
{
    return this->location ;
}



// virtual functions:

bool Path::Is_Path()
{
    return true ;
}

string Path::Display()
{
    string space = "" ;

    string directionName = this->direction->Get_name() ;

    if( directionName.length() == 1 ) space = " " ;

    return space + directionName + ": " + this->name ;
}



#include "../headers.h"

using namespace std ;

Path::Path( string name,
            string description,
            string useDescription,
            string targetDirectory,
            Location* location ) : Object(name,description,useDescription,false)
{
    this->targetDirectory = targetDirectory ;
    this->location = location ;

    this->targetPointer = NULL ;
}

void Path::Insert_Location_Pointer( Location* location )
{
    this->location = location ;
}

string Path::Get_PathID()
{
    if( location != NULL ) return location->Show_name() + '/' + this->name ;

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

bool Path::Is_Path()
{
    return true ;
}

void Path::Connect_Path( Path* targetPointer )
{
    this->targetPointer = targetPointer ;
}

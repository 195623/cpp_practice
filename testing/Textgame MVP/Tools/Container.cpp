#include "../headers.h"
using namespace std ;

Container::Container( vector<Object*> contents )
{
    this->contents = contents ;
}

void Container::Set_contents( vector<Object*> objects )
{
    this->contents = objects ;
}


void Container::Container::Add_Object( Object* object )
{
    this->contents.push_back(object) ;
}


void Container::Container::Remove_Object( Object* object )
{
    this->contents.erase( find(contents.begin(),contents.end(),object) ) ;
}

vector<Object*> Container::Return_contents()
{
    return this->contents ;
}

#include <iostream>
#include "headers.h"
using namespace std ;

void Define_Locations( vector<Location*>* locations ) ;

int main()
{
    vector<Location*> locations ;
    Define_Locations(&locations);

    World world = World(locations) ;
    world.Run_World();



    cout << "\n-----\n\nBye!" ;
    cin.get() ;
}

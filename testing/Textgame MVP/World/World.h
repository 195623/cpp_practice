#include <iostream>
#include <vector>

class Location ;
class Player ;

class World
{
public:
    World( std::vector<Location*> locations ) ;
    void Run_World() ;
    void Store_Locations_In_Paths( std::vector<Location*> locations ) ;

private:
    std::vector<Location*> locations ;
    Player* player ;
};

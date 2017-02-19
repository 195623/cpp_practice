#include <iostream>
#include <vector>

class Location ;
class Player ;

class World
{
public:
    World( std::vector<Location*> locations ) ;
    void Run_World() ;


private:
    std::vector<Location*> locations ;
    Player* player ;
};

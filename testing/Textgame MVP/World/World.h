#include <iostream>
#include <vector>

class Location ;
class Player ;

class World
{
public:
    World( std::vector<Location*> locations ) ;
    void Run_World() ;
    void Sort_All_Paths();
    void Sort_Two_Paths( Path* path1, Path* path2 ) ;


private:
    std::vector<Location*> locations ;
    Player* player ;
};

#include <iostream>
#include <algorithm>

class Location ;
class Command ;

class Player
{
public:
    Player( Location* location ) ;
    ~Player() ;
    Command Get_Command() ;

    Location* Get_location();
    void Set_location( Location* location ) ;

    std::string Look_Around();
    std::string Execute_Command( Command command ) ;

    Object* Find_Object( std::string text, std::string searchFor = "name", std::string where = "local" ) ;

    bool Is_Direction( std::string text ) ;

    Container* Get_inventory();

private:
    Location* location ;
    Container* inventory ;
};

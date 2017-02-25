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
    std::string Look_Around();
    std::string Execute_Command( Command command ) ;
    Object* Find_Object( std::string text, std::string searchFor = "name" ) ;

    bool Is_Direction( std::string text ) ;

private:
    Location* location ;
};

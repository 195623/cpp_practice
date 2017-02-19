#include <iostream>
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
    Object* Find_Object( std::string objectName ) ;

private:
    Location* location ;
};

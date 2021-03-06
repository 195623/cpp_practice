#include <iostream>
#include <algorithm>
#include <vector>

class Character ;
class Location ;
class Command ;

class Player : public Character
{
public:
    Player( std::string name = "", Location* location = NULL) ;
    ~Player() ;
    Command Get_Command() ;

    Location* Get_location();
    void Set_location( Location* location ) ;

    std::string Look_Around();
    std::string Return_Objects_String( std::vector<Object*> objects, std::string type = "" ) ;
    std::string Execute_Command( Command command ) ;

    Object* Find_Object( std::string text, std::string searchFor = "name", std::string where = "local" ) ;

    bool Is_Direction( std::string text ) ;

    Container* Get_inventory();

private:
    Container* inventory ;
};

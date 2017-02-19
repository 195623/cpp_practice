#include <iostream>
#include <vector>

class Object ;

class Location
{
public:
    Location( std::string name = "",
              std::string description = "",
              std::vector<Object*> objects = std::vector<Object*>() ) ;

    void Set_objects( std::vector<Object*> objects ) ;
    std::string Show_name();
    std::string Show_description();
    std::vector<Object*> Show_objects( std::string type = "" ) ;

private:
    std::string name ;
    std::string description ;
    std::vector<Object*> objects ;

};


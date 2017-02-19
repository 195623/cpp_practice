#include <iostream>

class Object
{
public:
    Object(std::string name, std::string description, bool pickable ) ;
    std::string Get_name();
    std::string Get_description();
    bool Get_pickable();

    virtual bool Is_Path() ;

protected:
    std::string name ;
    std::string description ;
    bool pickable ;

};

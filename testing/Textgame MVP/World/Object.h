#include <iostream>

class Object
{
public:
    Object(std::string name ="",
           std::string description ="",
           std::string useDescription ="",
           bool pickable = false ) ;
    std::string Get_name();
    std::string Get_description();
    std::string Get_useDescription() ;
    bool Get_pickable();

    virtual bool Is_Path() ;

protected:
    std::string name ;
    std::string description ;
    std::string useDescription ;
    bool pickable ;

};

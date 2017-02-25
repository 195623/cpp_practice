#include <iostream>

class Player ;

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
    virtual std::string Display() ;

    virtual std::string Get_Used( Player* player ) ;

protected:
    std::string name ;
    std::string description ;
    std::string useDescription ;
    bool pickable ;

};

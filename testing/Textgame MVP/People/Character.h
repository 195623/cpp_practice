#include <iostream>
class Location ;

class Character
{
public:
    Character(std::string name ="", Location* location = NULL);

protected:
    std::string name ;
    Location* location ;
};

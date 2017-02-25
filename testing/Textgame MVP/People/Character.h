#include <iostream>
class Location ;

class Character
{
public:
    Character(std::string name ="", Location* location = NULL);

private:
    std::string name ;
    Location* location ;
};

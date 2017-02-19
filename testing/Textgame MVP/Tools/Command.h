#include <iostream>

class Command
{
public:
    Command(std::string action ="", std::string tool ="",std::string preposition ="",std::string target ="" ) ;
    std::string Get_action();
    std::string Get_tool();
    std::string Get_preposition();
    std::string Get_target();

private:
    std::string action ;
    std::string tool ;
    std::string preposition ;
    std::string target ;
};

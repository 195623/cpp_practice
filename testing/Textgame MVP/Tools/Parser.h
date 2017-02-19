#include<iostream>
#include<vector>
class Command ;

class Parser
{
public:
    Parser() ;
    std::vector<std::string> Parse_Words( std::string text ) ;
    Command* Parse_Sentence( std::vector<std::string> sentence ) ;

private:


};

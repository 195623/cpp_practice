#include "../headers.h"
using namespace std;

    Command::Command( string action, string tool, string preposition, string target )
    {
        this->action = action ;
        this->tool = tool ;
        this->preposition = preposition ;
        this->target = target ;

        /*cout << "Action:      \"" << action << "\"\n" ;
        cout << "Tool:        \"" << tool << "\"\n" ;
        cout << "Preposition: \"" << preposition << "\"\n" ;
        cout << "Target:      \"" << target << "\"\n\n" ;


        if ( this->action      != "" &&
             this->tool        != "" &&
             this->preposition == "" &&
             this->target      == "" )
        {
            target = tool ;
            tool = "" ;
        }*/
    }

    string Command::Get_action()
    {
        return this->action ;
    }

    string Command::Get_tool()
    {
        return this->tool ;
    }

    string Command::Get_preposition()
    {
        return this->preposition ;
    }

    string Command::Get_target()
    {
        return this->target ;
    }

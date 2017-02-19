#include "../headers.h"
using namespace std;

Player::Player( Location* location )
{
    this->location = location ;
}


Player::~Player()
{
    delete this->location ;
}


Command Player::Get_Command()
{
    string textInput = "" ;

    cout << "> " ;
    getline(cin,textInput) ;

    if ( textInput == "quit" || textInput == "exit" ) return Command("quit") ;

    // ----

    Parser parser ;
    vector<string> stringVector = parser.Parse_Words(textInput) ;

    Command command = *parser.Parse_Sentence(stringVector);

    return command ;
}


string Player::Look_Around()
{
    vector<Object*> localObjects = this->location->Show_objects() ;

    std::string objectList = "" ;

    for( vector<Object*>::iterator it = localObjects.begin() ; it != localObjects.end() ; it++ )
    {
        objectList += "  " ;
        objectList += (*it)->Get_name() ;
        objectList += '\n' ;
    }

    return this->location->Show_name() + "\n\n" +
           this->location->Show_description() + "\n\n" +
           objectList + '\n' ;
}


string Player::Execute_Command( Command command )
{
    string output = "" ;

    string action      = command.Get_action(),
           tool        = command.Get_tool(),
           preposition = command.Get_preposition(),
           target      = command.Get_target() ;

    Object* foundObject = NULL ;

    if( action == "examine" || action == "check" || action == "x" )
    {
        if ( preposition == "" )
        {
            if ( target != "" )
            {
                foundObject = Find_Object(target) ;

                if( foundObject != NULL ) return foundObject->Get_description() ;

                else return "There is no \"" + target + "\" here." ;
            }

            else output = "Examine what?" ;
        }
        else output = "[Prepositions are not implemented yet.]" ;

    }
    else if ( action == "use" )
    {
        if( tool == "" && preposition == "" )
        {
            if( target != "" )
            {
                foundObject = Find_Object(target) ;

                if ( foundObject != NULL )
                {
                    output = "You used the " + target + "." ;

                    if( foundObject->Is_Path() )
                    {
                        Path* foundPath = (Path*) foundObject ;
                        Path* targetPointer = foundPath->Get_targetPointer() ;

                        if( targetPointer != NULL )
                        {
                            Location* targetLocation = foundPath->Get_targetPointer()->Get_location() ;

                            if( targetLocation != NULL ) this->location = targetLocation ;
                            else output += "\nThe path's target's location pointer is NULL." ;
                        }
                        else output += "\nPath's targetPointer is null." ;
                    }
                }

                else output = "There is no " + target + " here." ;
            }
        }
    }
    else output = "[Invalid action-word.]" ;

    return output ;
}

Object* Player::Find_Object( std::string objectName )
{
    vector<Object*> localObjects = this->location->Show_objects() ;

    for( vector<Object*>::iterator it = localObjects.begin() ; it != localObjects.end() ; it++ )
    {
        if( (*it)->Get_name() == objectName ) return *it ;
    }

    return NULL ;
}

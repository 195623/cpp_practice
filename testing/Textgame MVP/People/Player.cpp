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
    vector<Object*> localObjects = this->location->Get_objects() ;

    std::string objectList = "" ;

    for( vector<Object*>::iterator it = localObjects.begin() ; it != localObjects.end() ; it++ )
    {
        objectList += (*it)->Display();
        objectList += '\n' ;
    }

    return this->location->Get_name() + "\n\n" +
           this->location->Get_description() + "\n\n" +
           objectList + '\n' ;
}


string Player::Execute_Command( Command command )
{
    string output = "" ;

    string action      = command.Get_action(),
           tool        = command.Get_tool(),
           preposition = command.Get_preposition(),
           target      = command.Get_target() ;

    Object* foundTool = NULL ;
    Object* foundTarget = NULL ;

    if( tool != "" )
    {
        foundTool = Find_Object(tool);

        if( foundTool == NULL ) output = "There are no " + tool + "s here." ;
    }

    if( target != "" )
    {
        foundTarget = Find_Object(target);

        if( foundTarget == NULL ) output += "\nThere are no " + target + "s here." ;
    }

/*return*/
    if( output != "" ) return output ;



    if( action == "examine" || action == "check" || action == "x" )
    {
        if ( preposition == "" ) output = foundTarget->Get_description() ;

        else output = "\"" + action + "\" can't be used with prepositions in the sentence." ;
    }
    else if ( action == "use" )
    {
        if( preposition == "" )
        {
            if( foundTarget->Is_Path() )
            {
                Path* foundPath = (Path*) foundTarget ;

                Path* pathExit = foundPath->Get_targetPointer() ;

                if( pathExit != NULL )
                {
                    Location* exitLocation = pathExit->Get_location() ;

                    if( exitLocation != NULL )
                    {
                        this->location = exitLocation ;
                        output = foundPath->Get_useDescription() ;
                    }
                    else output = "[The exit-path of this path has a NULL location pointer.]" ;
                }
                else output = "[This path has an empty pointer to its exit-path.]" ;
            }
            else output = foundTarget->Get_useDescription() ;
        }
        else
        {
            output = "[No commands with prepositions... yet." ;
        }
    }
    else output = "[Invalid action-word.]";

    return output ;
}

Object* Player::Find_Object( std::string objectName )
{
    vector<Object*> localObjects = this->location->Get_objects() ;

    for( vector<Object*>::iterator it = localObjects.begin() ; it != localObjects.end() ; it++ )
    {
        if( (*it)->Get_name() == objectName ) return *it ;
    }

    return NULL ;
}

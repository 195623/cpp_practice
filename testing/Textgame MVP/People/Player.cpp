#include "../headers.h"
using namespace std;

Player::Player( Location* location )
{
    this->location = location ;
    this->inventory = new Container();
}

Container* Player::Get_inventory()
{
    return this->inventory ;
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


Location* Player::Get_location()
{
    return this->location ;
}

void Player::Set_location( Location* location )
{
    this->location = location ;
}

string Player::Look_Around()
{
    vector<Object*> localObjects = this->location->Get_objects() ;

    std::string objectList = "" ;

    for( vector<Object*>::iterator it = localObjects.begin() ; it != localObjects.end() ; it++ )
    {
        if( !(*it)->Is_Path() )
        {
            objectList += (*it)->Display();
            objectList += '\n' ;
        }
    }

    objectList+= '\n' ;

    for( vector<Object*>::iterator it = localObjects.begin() ; it != localObjects.end() ; it++ )
    {
        if( (*it)->Is_Path() )
        {
            objectList += (*it)->Display();
            objectList += '\n' ;
        }
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

    Object* foundTool      = NULL ;
    Object* foundTarget    = NULL ;
    Object* foundTargetInv = NULL ;

    if( tool != "" )
    {
        foundTool = Find_Object(tool);

        if( foundTool == NULL ) output = "There are no " + tool + "s here." ;
    }

    if( target != "" )
    {
        foundTarget = Find_Object(target);
        foundTargetInv = Find_Object(target,"name","inventory");

        if( foundTarget    == NULL && action != "drop" ) output += "\nThere are no " + target + "s here." ;
        if( foundTargetInv == NULL && action == "drop" ) output += "\nYou have no " + target + "s in your inventory." ;
    }

/*return*/
    if( output != "" ) return output ;



    if( action == "examine" || action == "check" || action == "x" )
    {
        if( target != "" )
        {
            if ( preposition == "" ) output = foundTarget->Get_description() ;

            else output = "\"" + action + "\" can't be used with prepositions in the sentence." ;
        }
        else output = "Examine what?" ;

    }
    else if ( action == "use" )
    {
        if( preposition == "" )
        {
            if( target != "" )
            {
                output = foundTarget->Get_Used(this);
            }
            else output = "Use what?" ;
        }
        else
        {
            output = "[No commands with prepositions... yet." ;
        }
    }
    else if ( action == "take" )
    {
        if( preposition == "" )
        {
            if( target != "" )
            {
                if( foundTarget->Is_Pickable() )
                {
                    output = "You picked up the " + foundTarget->Get_name() + "." ;
                    this->Get_inventory()->Add_Object(foundTarget);
                    this->Get_location()->Return_container()->Remove_Object(foundTarget);
                }
                else
                {
                    output = "The " + foundTarget->Get_name() + " is immovable." ;
                }
            }
            else output = "Take what?" ;
        }
        else
        {
            output = "[No \"take\" command with a preposition... yet." ;
        }
    }
    else if ( action == "drop" )
    {
        if( preposition == "" )
        {
            if( target != "" )
            {
                if( foundTargetInv->Is_Pickable() )
                {
                    output = "You dropped the " + foundTargetInv->Get_name() + "." ;
                    this->Get_location()->Return_container()->Add_Object(foundTargetInv);
                    this->Get_inventory()->Remove_Object(foundTargetInv);

                }
                else
                {
                    output = "The " + foundTarget->Get_name() + " is immovable." ;
                }
            }
            else output = "Drop what?" ;
        }
        else
        {
            output = "[No \"take\" command with a preposition... yet." ;
        }
    }
    else if ( tool == "" && preposition == "" && target == "" && Is_Direction( action ) )
    {
        Object* dirObject = Find_Object(action,"direction");
        if( dirObject != NULL )
        {
                if( dirObject->Is_Path() )
                {
                    Path* foundPath = (Path*) dirObject ;

                    output = foundPath->Get_Used(this);
                }

        }
        else output = "No path in that direction." ;

    }
    else output = "[Invalid action-word.]";

    return output ;
}

bool Player::Is_Direction( string text )
{

    extern string dirs[] ;
    string* str = NULL ;

    str = find(dirs,dirs+10,text) ;

    string* emptyITERATOR = (string*)find(dirs,dirs+10,"") ;

    if( str != emptyITERATOR ) return true ;

    return false ;
}


Object* Player::Find_Object( string text, string searchFor, string where )
{
    vector<Object*> objects ;

    if( where == "local" ) objects = this->location->Get_objects();

    else if ( where == "inventory" ) objects = this->inventory->Return_contents() ;

    else return NULL ;


    if( searchFor == "name" )
    for( vector<Object*>::iterator it = objects.begin() ; it != objects.end() ; it++ )
    {
        if( (*it)->Get_name() == text ) return *it ;
    }


    if( searchFor == "direction" )
    for( vector<Object*>::iterator it = objects.begin() ; it != objects.end() ; it++ )
    {
        if( (*it)->Is_Path() )
        {
            Path* path = (Path*) *it ;
            if( path->Get_directionName() == text )
            {
                return *it ;
            }

        }
    }

    return NULL ;
}

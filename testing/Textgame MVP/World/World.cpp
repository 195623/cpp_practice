#include "../headers.h"
#include <windows.h>

using namespace std ;




void World::Store_Locations_In_Paths( vector<Location*> locations )
{
    for( vector<Location*>::iterator it = locations.begin() ; it != locations.end() ; it++ )
    {
        vector<Object*> pathObjects = (*it)->Show_objects("Path") ;

        for( vector<Object*>::iterator it = pathObjects.begin() ; it != pathObjects.end() ; it++ )
        {

        }
    }

}



World::World( vector<Location*> locations )
{
    this->locations = locations ;
    if( locations.size() >=1 ) this->player = new Player(locations[0]) ;
    else cout << "There are zero locations. Can't put the player anywhere." ;
}

void World::Run_World()
{
    if( locations.size() == 0 ) return ;

    Command command  = Command();
    string textOutput ;

    do
    {
        // Time_Passes( int time ) ;

        system("CLS");
        cout << player->Look_Around() << '\n' ;

        command = player->Get_Command() ;

        cout << '\n' ;

        cout << "Action:      \"" << command.Get_action() << "\"\n" ;
        cout << "Tool:        \"" << command.Get_tool() << "\"\n" ;
        cout << "Preposition: \"" << command.Get_preposition() << "\"\n" ;
        cout << "Target:      \"" << command.Get_target() << "\"\n\n" ;

        textOutput = command.Get_action() + command.Get_tool() + command.Get_preposition() + command.Get_target() ;

        if ( textOutput != "exit" && textOutput != "quit" )
        {
            cout << player->Execute_Command(command) ;

            cout << "\n\n[Press Enter]" ;

            cin.get() ;
        }
        else break ;

    } while ( 1 );
}



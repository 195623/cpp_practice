#include "../headers.h"
#include <windows.h>

using namespace std ;




World::World( vector<Location*> locations )
{
    this->locations = locations ;
    if( locations.size() >=1 ) this->player = new Player(locations[0]) ;
    else cout << "There are zero locations. Can't put the player anywhere." ;

    Sort_All_Paths() ;
}

void World::Sort_All_Paths()
{
    for( vector<Location*>::iterator it = this->locations.begin() ; it != this->locations.end() ; it++ )
    {
        vector<Object*> pathObjects = (*it)->Get_objects("Path");

        for( vector<Object*>::iterator itp1 = pathObjects.begin() ; itp1 != pathObjects.end()-1 ; itp1++ )
        for( vector<Object*>::iterator itp2 = itp1+1 ; itp2 != pathObjects.end() ; itp2++ )
        {
            Path* path1 = (Path*) *itp1 ;
            Path* path2 = (Path*) *itp2 ;
            Sort_Two_Paths(path1,path2);
        }
    }
}

void World::Sort_Two_Paths( Path* path1, Path* path2 )
{
    int val_1 = path1->Get_direction()->Get_SortingOrder() ;
    int val_2 = path2->Get_direction()->Get_SortingOrder() ;

    if( val_1 > val_2 )
    {
        Path temp_path = *path2 ;
        *path2 = *path1 ;
        *path1 = temp_path ;
    }
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



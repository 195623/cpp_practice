#include<iostream>
#include <vector>
#include "../headers.h"
using namespace std ;

vector<Path*> All_Paths_On_One_List( vector<Location*> locations ) ;
void Join_All_Paths( vector<Path*> paths ) ;
void Join_Two_Paths( Path* path1, Path* path2) ;



void Define_Locations( vector<Location*>* locations )
{
    Location* location ;
    string name, description, useDescription ;
    vector<Object*> objects ;

    objects.clear() ;
    location = NULL ;


    name = "Room #1" ;
    description = "It seems to be in the middle of remodeling.\n"
                  "Bare walls, no furniture, wooden floor stained with fresh white paint..." ;

    location = new Location(name,description) ;

    objects.push_back( new Object("rock",
                                  "Gray and small.",
                                  "You throw it into the air and swiftly grab it again.",
                                  true) ) ;

    objects.push_back( new Path("door",
                                "Simple and wooden.",
                                "You push the door open, and enter the room beyond.",
                                "e",
                                "Room #2/door",
                                location) ) ;

    objects.push_back( new Path("small door",
                                "Simple and wooden.",
                                "You push the door open, and enter the room beyond.",
                                "n",
                                "Room #2/small door",
                                location) ) ;

    location->Return_container()->Set_contents(objects);

    (*locations).push_back( location ) ;


    // --------

    objects.clear() ;
    location = NULL ;

    name = "Room #2" ;
    description = "Weirdly colored...\n"
                  "As if somebody tried to imitate the style of a young child's drawing.\n"
                  "It makes your eyes hurt." ;

    location = new Location(name,description);

    objects.push_back( new Path("door",
                                "Simple and wooden.",
                                "You pull the door open, and enter the next room.",
                                "w",
                                "Room #1/door",
                                location) ) ;

    objects.push_back( new Path("small door",
                                "Simple and wooden.",
                                "You push the door open, and enter the room beyond.",
                                "s",
                                "Room #1/small door",
                                location) ) ;

    location->Return_container()->Set_contents(objects);
    (*locations).push_back( location ) ;

    vector<Path*> allPaths = All_Paths_On_One_List( *locations ) ;
    Join_All_Paths(allPaths) ;
}


vector<Path*> All_Paths_On_One_List( vector<Location*> locations )
{
    vector<Path*> allPaths ;

    for( vector<Location*>::iterator it = locations.begin() ; it != locations.end() ; it++ )
    {
        vector<Object*> localPathObjects = (*it)->Get_objects("Path") ;

        for( vector<Object*>::iterator it = localPathObjects.begin() ; it != localPathObjects.end() ; it++ )
        {
            Path* localPath = (Path*) *it ;

            allPaths.push_back(localPath) ;
        }
    }

    return allPaths ;
}


void Join_Two_Paths( Path* path1, Path* path2)
{
    if( (path1)->Get_targetPointer() == NULL )
    if( (path1)->Get_targetDirectory() == (path2)->Get_PathID() )
    {
        (path1)->Set_targetPointer( path2 ) ;
        (path2)->Set_targetPointer( path1 ) ;

        cout << "Joined \"" << path1->Get_PathID() << "\" and \"" << path2->Get_PathID() << "\".\n";
    }
}


void Join_All_Paths( vector<Path*> paths )
{
    for( vector<Path*>::iterator it = paths.begin() ; it != paths.end()-1 ; it++ )
    {
        for( vector<Path*>::iterator it2 = it+1 ; it2 != paths.end() ; it2++ )
        {
            Join_Two_Paths(*it,*it2) ;
        }
    }

    cin.get();
}




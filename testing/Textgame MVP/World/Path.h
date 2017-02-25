class Object ;
class Location ;
class Direction ;
class Player ;

class Path : public Object
{
public:
    Path( std::string name = "",
          std::string description = "",
          std::string useDescription = "",
          std::string directionName = "",
          std::string targetDirectory = "",
          Location* location = NULL ) ;
    //void Insert_Location_Pointer( Location* location ) ;

    virtual std::string Get_Used( Player* player ) ;
    void Set_targetPointer( Path* targetPointer ) ;

    std::string Get_directionName();
    std::string Get_PathID() ; // location's name + path's name
    std::string Get_targetDirectory() ;

    Direction* Get_direction() ;

    Path* Get_targetPointer() ;
    Location* Get_location() ;

    virtual bool Is_Path() ;
    virtual std::string Display() ;

private:
    Location* location ;
    Path* targetPointer ;

    //std::string direction ;
    Direction* direction ;


    std::string targetDirectory ;

};

class Object ;
class Location ;

class Path : public Object
{
public:
    Path( std::string name,std::string description, std::string useDescription, std::string targetDirectory, Location* location = NULL ) ;
    void Insert_Location_Pointer( Location* location ) ;
    void Connect_Path( Path* targetPointer ) ;

    std::string Get_PathID() ;
    std::string Get_targetDirectory() ;

    Path* Get_targetPointer() ;
    Location* Get_location() ;

    virtual bool Is_Path() ;

private:
    Location* location ;
    Path* targetPointer ;
    std::string targetDirectory ;

};

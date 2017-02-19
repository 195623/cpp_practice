
class Direction
{
public:
    Direction(std::string name) ;
    bool Is_Valid() ;

    std::string Get_name() ;
    int Get_SortingOrder();

private:
    std::string name ;

};

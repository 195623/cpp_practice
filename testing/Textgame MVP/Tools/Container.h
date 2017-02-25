#include <vector>

class Object ;

class Container
{
public:
    Container( std::vector<Object*> contents = std::vector<Object*>() );
    void Add_Object( Object* object ) ;
    void Remove_Object( Object* object ) ;
    void Set_contents( std::vector<Object*> objects ) ;

    std::vector<Object*> Return_contents();

private:
    std::vector<Object*> contents ;
};

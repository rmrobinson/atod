#include <iostream>
#include <vector>

#include "bst.hpp"

using namespace atod;

int main()
{
    bst t;
    t.add ( 14 );
    t.add ( 32 );
    t.add ( 3 );
    t.add ( 43 );
    t.add ( 23 );
    t.add ( 10 );
    t.add ( 1 );
    t.add ( 7 );
    t.add ( 12 );

    std::cout << "Tree contains 41? " << ( t.contains ( 41 ) ? "true" : "false" ) << std::endl;
    std::cout << "Tree contains 3? " << ( t.contains ( 3 ) ? "true" : "false" ) << std::endl;
    std::cout << "Tree contains 12? " << ( t.contains ( 12 ) ? "true" : "false" ) << std::endl;

    t.print ( std::cout );

    return 0;
}


#include <iostream>
#include <vector>

#include "avl.hpp"

using namespace atod;

int main()
{
    avl t;
    t.add ( 14 );
    t.add ( 32 );
    t.add ( 3 );
    t.add ( 43 );
    t.add ( 23 );
    t.add ( 10 );
    t.add ( 1 );
    t.add ( 7 );
    t.add ( 12 );
    t.add ( 100 );
    t.add ( 101 );
    t.add ( 102 );
    t.add ( 103 );
    t.add ( 104 );
    t.add ( 105 );
    t.add ( 106 );
    t.add ( 107 );
    t.add ( 108 );
    t.add ( 109 );
    t.add ( 110 );
    t.add ( 111 );
    t.add ( 112 );
    t.add ( 113 );
    t.add ( 114 );
    t.add ( 115 );
    t.add ( 116 );
    t.add ( 117 );
    t.add ( 118 );
    t.add ( 119 );
    t.add ( 120 );

    std::cout << "Tree contains 41? " << ( t.contains ( 41 ) ? "true" : "false" ) << std::endl;
    std::cout << "Tree contains 3? " << ( t.contains ( 3 ) ? "true" : "false" ) << std::endl;
    std::cout << "Tree contains 12? " << ( t.contains ( 12 ) ? "true" : "false" ) << std::endl;

    t.print ( std::cout );

    return 0;
}


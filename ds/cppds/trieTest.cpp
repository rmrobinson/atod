
#include <iostream>

#include "trie.hpp"

using namespace atod;

int main ( int argc, char* argv[] )
{
    if ( argc < 3 )
    {
        std::cout << "Please provide a string to add to the tree, and the word to search for" << std::endl;
        return 1;
    }

    trie t;
    t.add ( argv[1] );

    size_t count = t.count ( argv[2] );

    std::cout << "Provided string included '" << argv[2] << "' " << count << " times" << std::endl;

    t.print ( std::cout );

    return 0;
}


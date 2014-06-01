#include <iostream>
#include <vector>

#include "insertion.hpp"
#include "quick.hpp"

void reset ( std::vector<int>& data )
{
    data.clear();

    data.push_back ( 13 );
    data.push_back ( 11 );
    data.push_back ( 3 );
    data.push_back ( 54 );
    data.push_back ( 23 );
    data.push_back ( 4 );
    data.push_back ( 31 );
}

void print ( const std::vector<int>& data )
{
    for ( size_t i = 0; i < data.size(); ++i )
    {
        if ( i > 0 )
            std::cout << ", ";

        std::cout << data.at ( i );
    }

    std::cout << std::endl << std::endl;
}

int main()
{
    std::vector<int> data;
    reset ( data );

    std::cout << "Unsorted vector: " << std::endl;
    print ( data );

    size_t ret = atod::insertion::sort ( data );
    std::cout << "Insertion sort results after " << ret << " swaps:" << std::endl;

    print ( data );
    reset ( data );

    ret = atod::quick::sort ( data );
    std::cout << "Quicksort results after " << ret << " partitions:" << std::endl;

    print ( data );
    reset ( data );

    return 0;
}


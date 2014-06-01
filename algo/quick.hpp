#pragma once

#include <iostream>

namespace atod
{

class quick
{
public:
    static size_t sort ( std::vector<int>& data )
    {
        return internalSort ( data, 0, data.size() - 1 );
    }

private:
    static size_t internalSort ( std::vector<int>& data, size_t left, size_t right )
    {
        if ( right - left < 2 )
            return 1;

        std::cout << "starting with left, right = " << left << ", " << right << std::endl;

        const int pivotIdx = ( right - left ) / 2 + left;
        const int pivot = data.at ( pivotIdx );

        std::cout << "left, right, pivotIdx = " << left << ", " << right << ", " << pivotIdx << std::endl;

        data.at ( pivotIdx ) = data.at ( right );
        data.at ( right ) = pivot;

        size_t low = left;
        size_t high = right;

        while ( low < high )
        {
            do {
                ++low;
            } while ( low < right && data.at ( low ) < pivot );

            do {
                --high;
            } while ( high > low && data.at ( high ) > pivot );

            if ( low > high )
                break;

            std::cout << "low, high = " << low << ", " << high << std::endl;

            std::cout << "swapping " << data.at ( low ) << " with " << data.at ( high ) << std::endl;
            int tmp = data.at ( low );
            data.at ( low ) = data.at ( high );
            data.at ( high ) = tmp;
        }

        
        std::cout << "final low, high = " << low << ", " << high << std::endl;
        data.at ( right ) = data.at ( low );
        data.at ( low ) = pivot;

        std::cout << "Array as currently sorted: " << std::endl;
        for ( size_t i = 0; i < data.size(); ++i )
        {
            if ( i > 0 )
                std::cout << ", ";

            std::cout << data.at ( i );
        }

        std::cout << std::endl;

        size_t ret = internalSort ( data, left, low );
        ret += internalSort ( data, high, right );

        return ret;
    }
};

}


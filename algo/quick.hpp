#pragma once

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

        const int pivotIdx = ( right - left ) / 2 + left;
        const int pivot = data.at ( pivotIdx );

        data.at ( pivotIdx ) = data.at ( right );
        data.at ( right ) = pivot;

        size_t low = left;
        size_t high = right - 1;

        while ( low < high )
        {
            while ( low < right && data.at ( low ) < pivot )
                ++low;

            while ( high > low && data.at ( high ) > pivot )
                --high;

            if ( low > high )
                break;

            int tmp = data.at ( low );
            data.at ( low ) = data.at ( high );
            data.at ( high ) = tmp;
        }

        
        data.at ( right ) = data.at ( low );
        data.at ( low ) = pivot;

        size_t ret = internalSort ( data, left, low );
        ret += internalSort ( data, high, right );

        return ret;
    }
};

}


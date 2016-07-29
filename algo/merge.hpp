#pragma once

#include <vector>

namespace atod
{

class merge
{
public:
    static size_t sort ( std::vector<int>& data )
    {
        return internalSort ( data );
    }

private:
    static size_t internalSort ( std::vector<int>& data )
    {
        if ( data.size() == 1 )
            return 1;

        std::vector<int> left ( data.begin(), data.begin() + data.size() / 2 );
        std::vector<int> right ( data.begin() + data.size() / 2, data.end() );

        size_t ret = internalSort ( left );
        ret += internalSort ( right );

        size_t li = 0;
        size_t ri = 0;
        std::vector<int> output;

        while ( li < left.size() && ri < right.size() )
        {
            if ( left.at ( li ) < right.at ( ri ) )
            {
                output.push_back ( left.at ( li ) );
                ++li;
            }
            else
            {
                output.push_back ( right.at ( ri ) );
                ++ri;
            }
        }

        for ( ; li < left.size(); ++li )
            output.push_back ( left.at ( li ) );

        for ( ; ri < right.size(); ++ri )
            output.push_back ( right.at ( ri ) );

        data = output;

        return ret;
    }
};

}


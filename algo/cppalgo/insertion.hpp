#pragma once

namespace atod
{

class insertion
{
public:
    static size_t sort ( std::vector<int>& data )
    {
        size_t count = 0;

        for ( size_t i = 1; i < data.size(); ++i )
        {
            for ( size_t j = i; j > 0; --j )
            {
                if ( data.at ( j - 1 ) > data.at ( j ) )
                {
                    int tmp = data.at ( j );
                    data.at ( j ) = data.at ( j - 1 );
                    data.at ( j - 1 ) = tmp; 
                    ++count;
                }
                else
                {
                    continue;
                }
            }
        }

        return count;
    }
};

}


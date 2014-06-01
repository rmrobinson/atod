#include <stdio.h>
#include <stdbool.h>

int main ( int argc, char* argv[] )
{
    if ( argc != 2 )
    {
        fprintf ( stdout, "Please provide the number to convert & display\n" );
        return 1;
    }

    char* curr = argv[1];
    int ret = 0;
    bool neg = false;
    bool start = false;

    while ( *curr != '\0' )
    {
        if ( ! start && *curr == '-' )
        {
            start = true;
            neg = true;

            ++curr;
            continue;
        }
        else if ( ! start && *curr == ' ' )
        {
            ++curr;
            continue;
        }
        else if ( *curr > '9' || *curr < '0' )
        {
            fprintf ( stdout, "Entered an invalid character '%c'\n", *curr );
            return 1;
        }

        start = true;
        ret = ret * 10 + ( *curr - '0' );
        ++curr;
    }

    if ( neg )
        ret *= -1;

    fprintf ( stdout, "You entered %d\n", ret );

    return 0;
}


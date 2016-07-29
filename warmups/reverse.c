#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char* argv[] )
{
    if ( argc < 2 )
    {
        fprintf ( stdout, "Please provide a string to reverse" );
        return 1;
    }

    const size_t strLen = strlen ( argv[1] );
    char* str = malloc ( strLen + 1 );
    assert ( str != NULL );
    strncpy ( str, argv[1], strLen );
    str[strLen] = '\0';

    fprintf ( stdout, "%s\n", str );

    char* back = str;
    while ( *back != '\0' )
    {
        ++back;
    }

    --back;

    char* front = str;
    while ( front < back )
    {
        char tmp = *back;
        *back = *front;
        *front = tmp;

        ++front;
        --back;
    }

    fprintf ( stdout, "%s\n", str );

    return 0;
}

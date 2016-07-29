#include <stdio.h>
#include <stdbool.h>

int main ( int argc, char* argv[] )
{
    if ( argc != 3 )
    {
        fprintf ( stdout, "Please provide a string to search, and another string to search for\n" );
        return 1;
    }

    char* find = argv[2];
    bool found = false;
 
    for ( char* str = argv[1]; *str != '\0'; ++str )
    {
        bool matched = false;

        if ( *str == *find )
        {
            matched = true;
        }
        else if ( ( *str <= 'Z' && *str >= 'A' ) || ( *str <= 'z' && *str >= 'a' ) )
        {
            char strLc = *str;

            if ( strLc <= 'Z' && strLc >= 'A' )
                strLc += 32;

            char findLc = *find;

            if ( findLc <= 'Z' && findLc >= 'A' )
                findLc += 32;

            if ( findLc == strLc )
            {
                matched = true;
            }
        }

        if ( matched )
        {
            ++find;

            if ( *find == '\0' )
            {
                found = true;
                break;
            }
        }
        else
        {
            // not found; start at beginning of the search string with the next character
            find = argv[2];
        }
    }

    fprintf ( stdout, "The string '%s' %s found in the first string '%s'\n", argv[2], ( found ? "was" : "was not" ), argv[1] );

    return 0;
}

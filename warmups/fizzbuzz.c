#include <stdio.h>
#include <stdbool.h>

int main()
{
    for ( size_t i = 1; i <= 100; ++i )
    {
        bool threeMult = false;
        bool fiveMult = false;

        if ( ! ( i % 3 ) )
            threeMult = true;

        if ( ! ( i % 5 ) )
            fiveMult = true;

        if ( ! threeMult && ! fiveMult )
        {
            fprintf ( stdout, "%lu\n", i );
            continue;
        }

        if ( threeMult )
            fprintf ( stdout, "Fizz" );
        if ( fiveMult )
            fprintf ( stdout, "Buzz" );

        fprintf ( stdout, "\n" );
    }

    return 0;
}


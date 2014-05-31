#include "trie.hpp"

#include <cassert>

using namespace atod;

trie::trie() : root_ ( ' ' )
{
}

trie::~trie()
{
}

void trie::add ( const std::string& str )
{
    node* curr = &root_;

    for ( size_t i = 0; i < str.length(); ++i )
    {
        assert ( curr != nullptr );

        int idx = getCharIdx ( str[i] );

        if ( idx < 0 )
        {
            ++ ( curr->count_ );

            curr = &root_;
            continue;
        }

        assert ( idx >= 0 );
        assert ( idx <= ALPHABET_SIZE );

        node*& next = curr->children_[idx];

        if ( next == nullptr )
        {
            next = new node ( str[i] );
        }

        assert ( next != nullptr );

        curr = next;
    }

    assert ( curr != nullptr );
    if ( curr != &root_ )
        ++ ( curr->count_ );
}

size_t trie::count ( const std::string& str ) const
{
    const node* curr = &root_;

    for ( size_t i = 0; i < str.length(); ++i )
    {
        assert ( curr != nullptr );

        int idx = getCharIdx ( str[i] );

        if ( idx < 0 )
            return 0;

        curr = curr->children_[idx];

        if ( curr == nullptr )
            return 0;
    }

    assert ( curr != nullptr );

    return curr->count_;
}

void trie::print ( std::ostream& dest ) const
{
    std::string tmp;
    internalPrint ( &root_, tmp, dest );
}

void trie::internalPrint ( const node* n, std::string& prev, std::ostream& dest) const
{
    assert ( n != nullptr );

    prev.push_back ( n->character_ );

    if ( n->count_ > 0 )
    {
        dest << prev << " (" << n->count_ << " times)" << std::endl;
    }

    for ( size_t i = 0; i < ALPHABET_SIZE; ++i )
    {
        if ( n->children_[i] != nullptr )
            internalPrint ( n->children_[i], prev, dest );
    }

    prev.pop_back();
}

int trie::getCharIdx ( char c )
{
    if ( c >= 'A' && c <= 'Z' )
        return ( c - 'A' );
    else if ( c >= 'a' && c <= 'z' )
        return ( c - 'a' );

    return -1;
}

trie::node::node ( char c ) : character_ ( c ), count_ ( 0 )
{
}

trie::node::~node()
{
    for ( size_t i = 0; i < ALPHABET_SIZE; ++i )
    {
        if ( children_[i] != nullptr )
            delete children_[i];
    }
}


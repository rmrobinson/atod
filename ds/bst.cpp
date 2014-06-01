
#include <cassert>

#include "bst.hpp"

using namespace atod;

bst::bst() : root_ ( nullptr )
{
}

bst::~bst()
{
}

void bst::add ( int value )
{
    node* curr = root_;

    while ( curr != nullptr )
    {
        if ( value == curr->value_ )
            return;

        node*& child = ( ( value < curr->value_ ) ? curr->left_ : curr->right_ );

        if ( child == nullptr )
        {
            child = new node ( value );
            return;
        }

        curr = child;
    }

    assert ( root_ == nullptr );

    root_ = new node ( value );
}

bool bst::contains ( int value ) const
{
    node* curr = root_;

    while ( curr != nullptr )
    {
        if ( value == curr->value_ )
            return true;

        if ( value < curr->value_ )
            curr = curr->left_;
        else
            curr = curr->right_;
    }

    return false;
}

void bst::print ( std::ostream& dest ) const
{
    internalPrint ( root_, 0, dest );
}

void bst::internalPrint ( const node* n, int depth, std::ostream& dest )
{
    if ( n == nullptr )
        return;

    for ( int i = 0; i < depth; ++i )
        dest << " ";

    dest << n->value_ << std::endl;

    internalPrint ( n->left_, depth+1, dest );
    internalPrint ( n->right_, depth+1, dest );
}

bst::node::node ( int value ) : value_ ( value ), left_ ( nullptr ), right_ ( nullptr )
{
}

bst::node::~node()
{
    if ( left_ != nullptr )
        delete left_;

    if ( right_ != nullptr )
        delete right_;
} 

